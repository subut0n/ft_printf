/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhexaminf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@42student.lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:53:00 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/09 12:09:44 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	print_precision(size_t nbr_digit, t_options *options)
{
	int nbr_char;
	size_t precision;

	nbr_char = 0;
	precision = options->precision;
	while (precision > nbr_digit)
	{
		ft_putchar('0');
		nbr_char++;
		precision--;
	}
	return (nbr_char);
}

static int print_width(size_t nbr_digit, t_options *options)
{
	int nbr_char;
	size_t width;

	nbr_char = 0;
	width = options->width;
	if (width < options->precision)
		width = 0;
	if ((options->minus || options->zero) && options->precision == 0 && width >= nbr_digit)
		width = width - nbr_digit;
	while (width > options->precision)
	{
		ft_putchar(' ');
		nbr_char++;
		width--;
	}
	return (nbr_char);
}

static int print_nbr(unsigned int nbr, t_options *options)
{
	if (nbr == 0 && options->precision == 0 && options->width == 0)
		return (0);
	if (nbr == 0 && options->precision == 0 && options->width >= 1)
	{
		if (options-> minus == 1)
			ft_putstr(" ");
		return (0);
	}
	ft_putnbr_base(nbr,"0123456789abcdef");
	return (ft_count_base(nbr,"0123456789abcdef"));
}

int		uhexaminf(t_options *options, va_list args)
{
	int nbr_char;
	size_t nbr_digits;
	unsigned int nbr;

	nbr = va_arg(args, unsigned int);
	nbr_digits = ft_count_base(nbr, "0123456789abcdef");
	nbr_char = 0;
	if (nbr == 0 && options->dot == 0 && options->width == 0)
		return (0);
	if (options->minus)
	{
		nbr_char += print_precision(nbr_digits, options);
		nbr_char += print_nbr(nbr, options);
		nbr_char += print_width(nbr_digits, options);
	}
	else
	{
		nbr_char = print_width(nbr_digits, options);
		nbr_char += print_precision(nbr_digits, options);
		nbr_char += print_nbr(nbr, options);
	}
	return (nbr_char);
}