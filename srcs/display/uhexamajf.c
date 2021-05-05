/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhexamajf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 14:10:27 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/05 17:04:20 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	pt_precision(int nbr, size_t nbr_digit, t_options *opt)
{
	int		nbr_char;
	size_t		digit;
	size_t	precision;
	long int neg_prec_abs;
	size_t width;

	nbr_char = 0;
	digit = nbr_digit;
	precision = opt->precision;
	neg_prec_abs = ft_absolute(opt->neg_prec);
	width = opt->width;
	if (opt->zero && neg_prec_abs > 0 && nbr < 0 && width > 0)
		precision = width - 1;
	if (nbr == 0 && opt->precision < 0)
		digit = 0;
	while (precision-- > digit)
	{
		ft_putchar('0');
		nbr_char++;
	}
	return (nbr_char);
}

static int	pt_width(unsigned int nbr, size_t nbr_digit, t_options *opt)
{
	int				nbr_char;
	size_t	width;
	size_t	precision;
	long int neg_prec_abs;

	nbr_char = 0;
	precision = opt->precision;
	width = ft_absolute((int)opt->width);
	neg_prec_abs = ft_absolute(opt->neg_prec);
	if (width < opt->precision || width < nbr_digit)
		width = 0;
	if (opt->precision == 0 && width >= nbr_digit && opt->dot == 0)
		width = width - nbr_digit;
	if (opt->precision < nbr_digit && opt->dot == 1 && nbr != 0)
		precision = nbr_digit;
	if (opt->zero && neg_prec_abs > 0 && nbr < 0)
		width = 0;
	while (width-- > precision)
	{
		if (opt->zero && opt->neg_prec < 0 && nbr >= 0 && !opt->minus)
			ft_putchar('0');
		else
			ft_putchar(' ');
		nbr_char++;
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
		nbr_char += pt_precision(nbr, nbr_digits, options);
		nbr_char += pt_nbr(nbr, options);
		nbr_char += pt_width(nbr, nbr_digits, options);
	}
	else
	{
		nbr_char = pt_width(nbr, nbr_digits, options);
		nbr_char += pt_precision(nbr, nbr_digits, options);
		nbr_char += pt_nbr(nbr, options);
	}
	return (nbr_char);
}
