/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:49:40 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/22 16:42:36 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	numb_of_digits(int n)
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

int	print_precision(int nbr, int nbr_digit, t_options *options)
{
	int nbr_char;
	int precision;

	precision = options->dot;
	while (precision > nbr_digit)
	{
		ft_putchar('0');
		precision--;
	}
	return (nbr_char);
}

int	ft_int(char *ret, size_t i, t_options *options, va_list args)
{
	int nbr_char;
	int nbr_digits;
	int nbr;
	int empty_to_fill;
	char *str;

	nbr = va_arg(args, int);
	nbr_digits = numb_of_digits(nbr);
	
	if (nbr == 0 && options->dot == 0 && options->width == 0)
		return (0);
	return (nbr_char);
}