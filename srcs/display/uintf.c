/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uintf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:15:44 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/08 14:32:09 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	numb_of_digits(unsigned int n)
{
	int		numb;
	long	nb;

	nb = n;
	numb = 0;
	if (nb < 0)
		nb = -nb;
	if (nb == 0)
		numb = 1;
	while (nb > 0)
	{
		nb = nb / 10;
		numb++;
	}
	return (numb);
}

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

static int print_width(unsigned int nbr, size_t nbr_digit, t_options *options)
{
	int nbr_char;
	size_t width;

	nbr_char = 0;
	width = options->width;
	if (nbr < 0 && width != 0)
		width = width - 1;
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
	char *str_nbr;

	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0 && options->precision == 0 && options->width == 0)
		return (0);
	if (nbr == 0 && options->precision == 0 && options->width >= 1)
	{
		if (options-> minus == 1)
			ft_putstr(" ");
		return (0);
	}
	str_nbr = ft_uitoa(nbr);
	ft_putstr(str_nbr);
	free(str_nbr);
	return ((int)ft_strlen(str_nbr));
}

int	uintf(t_options *options, va_list args)
{
	int nbr_char;
	size_t nbr_digits;
	unsigned int nbr;

	nbr = va_arg(args, unsigned int);
	nbr_digits = numb_of_digits(nbr);
	nbr_char = 0;
	if (nbr == 0 && options->dot == 0 && options->width == 0)
		return (0);
	if (options->minus)
	{
		nbr_char += print_precision(nbr_digits, options);
		nbr_char += print_nbr(nbr, options);
		nbr_char += print_width(nbr, nbr_digits, options);
	}
	else
	{
		nbr_char = print_width(nbr, nbr_digits, options);
		nbr_char += print_precision(nbr_digits, options);
		nbr_char += print_nbr(nbr, options);
	}
	return (nbr_char);
}