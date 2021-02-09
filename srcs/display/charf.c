/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:29:59 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/09 15:36:17 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int print_width(t_options *options)
{
	int width;
	int nbr_char;
	
	width = options->width - 1;
	nbr_char = 0;
	while (width-- > 0)
	{
		ft_putchar(' ');
		nbr_char++;
	}
	return (nbr_char);
}

int		charf(t_options *options, va_list args)
{
	char c;
	int nbr_char;

	c = va_arg(args, int);
	nbr_char = 0;
	if (options->minus)
	{
		nbr_char = 1;
		ft_putchar(c);
		nbr_char += print_width(options);
	}
	else
	{
		nbr_char = print_width(options);
		nbr_char = nbr_char + 1;
		ft_putchar(c);
	}
	return(nbr_char);
}