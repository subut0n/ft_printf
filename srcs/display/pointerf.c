/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointerf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 15:57:25 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/23 15:40:40 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	pt_prec(unsigned long long nbr, size_t digit, t_options *options)
{
	int		nbr_char;
	size_t	precision;

	nbr_char = 0;
	precision = options->precision;
	if (precision < 0)
		precision *= -1;
	if (nbr == 0 && options->precision < 0)
		digit = 0;
	while (precision > digit)
	{
		ft_putchar('0');
		nbr_char++;
		precision--;
	}
	return (nbr_char);
}

static int	pt_width(unsigned long long nbr, size_t digit, t_options *options)
{
	int				nbr_char;
	unsigned int	width;
	unsigned int	precision;

	nbr_char = 0;
	precision = options->precision;
	width = options->width;
	if (width < options->precision)
		width = 0;
	if (width < digit + 2)
		width = 0;
	if (options->precision == 0 && width >= digit && options->dot == 0)
		width = width - digit;
	if (options->precision < digit && options->dot == 1 && nbr != 0)
		precision = digit;
	if (width >= 2)
		width = width - 2;
	while (width > precision)
	{
		ft_putchar(' ');
		nbr_char++;
		width--;
	}
	return (nbr_char);
}

static int	pt_prefix(void)
{
	ft_putstr("0x");
	return (2);
}

static int	pt_nbr(unsigned long long nbr, t_options *options)
{
	long	numb;
	size_t	digit_in_base;

	numb = (long)nbr;
	if (nbr == 0 && options->dot == 1)
	{
		if (options->precision == 0)
			return (0);
	}
	ft_putnbr_base(nbr, "0123456789abcdef");
	digit_in_base = ft_count_base(nbr, "0123456789abcdef");
	if (nbr == 0)
		digit_in_base = 1;
	return (digit_in_base);
}

int	pointerf(t_options *options, va_list args)
{
	int				nbr_char;
	size_t			nbr_digits;
	unsigned long	nbr;

	nbr = va_arg(args, unsigned long long);
	nbr_digits = ft_count_base(nbr, "0123456789abcdef");
	if (nbr == 0)
		nbr_digits = 1;
	nbr_char = 0;
	if (options->minus)
	{
		nbr_char = pt_prefix();
		nbr_char += pt_prec(nbr, nbr_digits, options);
		nbr_char += pt_nbr(nbr, options);
		nbr_char += pt_width(nbr, nbr_digits, options);
	}
	else
	{
		nbr_char = pt_width(nbr, nbr_digits, options);
		nbr_char += pt_prefix();
		nbr_char += pt_prec(nbr, nbr_digits, options);
		nbr_char += pt_nbr(nbr, options);
	}
	return (nbr_char);
}
