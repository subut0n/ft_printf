/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhexamajf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:27 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/30 15:01:27 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	pt_prec(unsigned int nbr, size_t nbr_digit, t_options *options)
{
	int		nbr_char;
	size_t	precision;

	nbr_char = 0;
	precision = options->precision;
	if (precision < 0)
		precision *= -1;
	if (nbr == 0 && options->precision < 0)
		nbr_digit = 0;
	while (precision > nbr_digit)
	{
		ft_putchar('0');
		nbr_char++;
		precision--;
	}
	return (nbr_char);
}

static int	pt_width(unsigned int nbr, size_t nbr_digit, t_options *options)
{
	int				nbr_char;
	unsigned int	width;
	unsigned int	precision;

	nbr_char = 0;
	precision = options->precision;
	width = options->width;
	if (width < options->precision)
		width = 0;
	if (width < nbr_digit)
		width = 0;
	if (options->precision == 0 && width >= nbr_digit && options->dot == 0)
		width = width - nbr_digit;
	if (options->precision < nbr_digit && options->dot == 1 && nbr != 0)
		precision = nbr_digit;
	while (width > precision)
	{
		ft_putchar(' ');
		nbr_char++;
		width--;
	}
	return (nbr_char);
}

static int	pt_nbr(unsigned int nbr, t_options *options)
{
	long	numb;
	size_t	digit_in_base;

	numb = (long)nbr;
	if (nbr == 0 && options->dot == 1)
	{
		if (options->precision == 0)
			return (0);
	}
	ft_putnbr_base(nbr, "0123456789ABCDEF");
	digit_in_base = ft_count_base(nbr, "0123456789ABCDEF");
	if (nbr == 0)
		digit_in_base = 1;
	return (digit_in_base);
}

int	uhexamajf(t_options *options, va_list args)
{
	int				nbr_char;
	size_t			nbr_digits;
	unsigned int	nbr;

	nbr = va_arg(args, int);
	nbr_digits = ft_count_base(nbr, "0123456789ABCDEF");
	if (nbr == 0)
		nbr_digits = 1;
	nbr_char = 0;
	if (options->minus)
	{
		nbr_char += pt_prec(nbr, nbr_digits, options);
		nbr_char += pt_nbr(nbr, options);
		nbr_char += pt_width(nbr, nbr_digits, options);
	}
	else
	{
		nbr_char = pt_width(nbr, nbr_digits, options);
		nbr_char += pt_prec(nbr, nbr_digits, options);
		nbr_char += pt_nbr(nbr, options);
	}
	return (nbr_char);
}
