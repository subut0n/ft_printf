/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percentf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:14:30 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/15 15:04:09 by addzikow         ###   ########lyon.fr   */
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
		if (options->zero == 1)
			ft_putchar('0');
		else
			ft_putchar(' ');
		nbr_char++;
	}
	return (nbr_char);
}

int		percentf(t_options *options)
{
	int nbr_char;

	nbr_char = 0;
	if (options->minus)
	{
		nbr_char = 1;
		ft_putchar('%');
		nbr_char += print_width(options);
	}
	else
	{
		nbr_char = print_width(options);
		nbr_char = nbr_char + 1;
		ft_putchar('%');
	}
	return(nbr_char);
}