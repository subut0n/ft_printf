/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:49:40 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/08 17:01:13 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	numb_of_digits(int n)
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

static int	print_precision(int nbr, size_t nbr_digit, t_options *options)
{
	int nbr_char;
	size_t precision;

	nbr_char = 0;
	precision = options->precision;
	if (nbr < 0 && options->zero == 1 && options->dot == 0)
		nbr_digit = nbr_digit + 1;
	while (precision > nbr_digit)
	{
		ft_putchar('0');
		nbr_char++;
		precision--;
	}
	return (nbr_char);
}

static int print_width(int nbr, size_t nbr_digit, t_options *options)
{
	int nbr_char;
	unsigned int width;
	unsigned int precision;

	nbr_char = 0;
	precision = options->precision;
	width = options->width;
	if (nbr < 0 && width != 0)
		width = width - 1;
	if (width < options->precision)
		width = 0;
	if (options->precision == 0 && width >= nbr_digit && options->dot == 0)
		width = width - nbr_digit;
	if (width < nbr_digit)
		width = 0;
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

static int print_sign(int nbr)
{
	int nbr_char;

	nbr_char = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr_char = 1;
	}
	return(nbr_char);
}

static int print_nbr(int nbr, t_options *options)
{
	char *str_nbr;

	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0 && options->dot == 1)
	{
		if (options->precision == 0)
			return (0);
	}
	str_nbr = ft_itoa(nbr);
	ft_putstr(str_nbr);
	free(str_nbr);
	return ((int)ft_strlen(str_nbr));
}

int	intf(t_options *options, va_list args)
{
	int nbr_char;
	size_t nbr_digits;
	int nbr;

	nbr = va_arg(args, int);
	nbr_digits = numb_of_digits(nbr);
	nbr_char = 0;
	// if (nbr == 0 && options->dot == 1)
	// 	return (0);
	if (options->minus)
	{
		nbr_char = print_sign(nbr);
		nbr_char += print_precision(nbr, nbr_digits, options);
		nbr_char += print_nbr(nbr, options);
		nbr_char += print_width(nbr, nbr_digits, options);
	}
	else
	{
		nbr_char = print_width(nbr, nbr_digits, options);
		nbr_char += print_sign(nbr);
		nbr_char += print_precision(nbr, nbr_digits, options);
		nbr_char += print_nbr(nbr, options);
	}
	return (nbr_char);
}