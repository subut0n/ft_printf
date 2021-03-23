/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:55:23 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/23 15:42:54 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	print_width(char *str, t_options *options)
{
	int		print_width;
	int		nbr_char;
	size_t	length;

	nbr_char = 0;
	length = 0;
	print_width = 0;
	while (str[length])
		length++;
	if (options->width > 0)
		print_width = options->width - length;
	if (options->dot)
	{
		if (options->precision < length && options->neg_prec == 0)
			print_width = options->width - options->precision;
		if (options->precision > length && options->width == 0)
			print_width = 0;
	}
	if (print_width < 0)
		print_width = 0;
	while (print_width-- > 0)
	{
		ft_putchar(' ');
		nbr_char++;
	}
	return (nbr_char);
}

static int	print_str(int is_null, char *str, t_options *options)
{
	int		nbr_char;
	size_t	i;
	size_t	limit;

	nbr_char = 0;
	i = 0;
	limit = 0;
	while (str[limit])
		limit++;
	if (options->dot && options->neg_prec == 0)
		limit = options->precision;
	if (options->dot && is_null && options->neg_prec < 0)
		limit = 6;
	while (str[i] && i < limit)
	{
		ft_putchar(str[i]);
		i++;
		nbr_char++;
	}
	return (nbr_char);
}

int	strf(t_options *options, va_list args)
{
	char	*str;
	size_t	is_null;
	int		nbr_char;

	str = va_arg(args, char *);
	is_null = 0;
	if (str == NULL)
	{
		str = "(null)";
		is_null = 1;
	}
	if (options->minus)
	{
		nbr_char = print_str(is_null, str, options);
		nbr_char += print_width(str, options);
	}
	else
	{
		nbr_char = print_width(str, options);
		nbr_char += print_str(is_null, str, options);
	}
	return (nbr_char);
}
