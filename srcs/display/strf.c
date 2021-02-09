/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:55:23 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/09 15:59:41 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	print_width(char *str, t_options *options)
{
	int width;
	int nbr_char;
	size_t i;

	i = 0;
	if (options->dot == 1)
	{
		while(str[i])
			i++;
		width = options->width - i;
	}
	nbr_char = 0;
	while (width-- > 0)
	{
		ft_putchar('x');
		nbr_char++;
	}
	return (nbr_char);
}

static int	print_str(char *str, t_options *options)
{
	int nbr_char;
	size_t i;
	size_t limit;

	i = 0;
	nbr_char = 0;
	limit = options->precision;
	while (str[i] && i > limit)
	{
		ft_putchar(str[i]);
		i++;
		nbr_char++;
	}
	return (nbr_char);
}

int		strf(t_options *options, va_list args)
{
	char *str;
	int nbr_char;
	

	str = va_arg(args, char *);
	if (options->minus)
	{
		nbr_char = print_str(str, options);
		nbr_char += print_width(str, options);
	}
	else
	{
		nbr_char = print_width(str, options);
		nbr_char += print_str(str, options);
	}
	return(nbr_char);
}