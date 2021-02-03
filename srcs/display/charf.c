/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   charf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:29:59 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/03 16:33:14 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int		charf(t_options *options, va_list args)
{
	char c;
	int width;
	int nbr_char;

	c = va_arg(args, int);
	width = options->width - 1;
	nbr_char = 0;
	while (width-- > 0)
	{
		ft_putchar(' ');
		nbr_char++;
	}
	ft_putchar(c);
	nbr_char++;
	return(nbr_char);
}