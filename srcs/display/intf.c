/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:49:40 by addzikow          #+#    #+#             */
/*   Updated: 2021/05/05 17:46:50 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	print_precision(int nbr, size_t nbr_digit, t_options *opt)
{
	int			nbr_char;
	size_t		digit;
	size_t		precision;
	long int	neg_prec_abs;
	size_t		width;

	nbr_char = 0;
	digit = nbr_digit;
	precision = opt->precision;
	neg_prec_abs = ft_absolute(opt->neg_prec);
	width = opt->width;
	if (opt->zero && neg_prec_abs > 0 && nbr < 0 && width > 0)
		precision = width - 1;
	if (nbr < 0 && opt->dot == 0)
		digit = digit + 1;
	if (nbr == 0 && opt->precision < 0)
		digit = 0;
	while (precision-- > digit)
	{
		ft_putchar('0');
		nbr_char++;
	}
	return (nbr_char);
}

static int	print_width(int nbr, size_t nbr_digit, t_options *opt)
{
	int			nbr_char;
	size_t		width;
	size_t		precision;

	nbr_char = 0;
	precision = opt->precision;
	width = ft_absolute((int)opt->width);
	if (nbr < 0 && width != 0)
		width = width - 1;
	if (width < opt->precision || width < nbr_digit
		|| (opt->zero && opt->neg_prec < 0 && nbr < 0))
		width = 0;
	if (opt->precision == 0 && width >= nbr_digit && opt->dot == 0)
		width = width - nbr_digit;
	if (opt->precision < nbr_digit && opt->dot == 1 && nbr != 0)
		precision = nbr_digit;
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

static int	print_sign(int nbr)
{
	int	nbr_char;

	nbr_char = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr_char = 1;
	}
	return (nbr_char);
}

static int	print_nbr(int nbr, t_options *options)
{
	char	*str_nbr;
	int		nbr_char;
	long	numb;

	numb = (long)nbr;
	if (numb < 0)
		numb = -numb;
	if (nbr == 0 && options->dot == 1)
	{
		if (options->precision == 0)
			return (0);
	}
	str_nbr = ft_ltoa(numb);
	ft_putstr(str_nbr);
	nbr_char = ft_strlen(str_nbr);
	free(str_nbr);
	return (nbr_char);
}

int	intf(t_options *options, va_list args)
{
	int		nbr_char;
	size_t	nbr_digits;
	int		nbr;

	nbr = va_arg(args, int);
	nbr_digits = ft_count_digit((int)nbr);
	nbr_char = 0;
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
