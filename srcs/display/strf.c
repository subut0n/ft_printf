/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 11:55:23 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/03 13:50:08 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		strf(t_options *options, va_list args)
{
	char *str;
	int width;
	int nbr_char;
	int i;

	str = va_arg(args, char *);
	i = 0;
	while(str[i])
		i++;
	width = options->width - i;
	nbr_char = 0;
	while (width-- > 0)
	{
		ft_putchar(' ');
		nbr_char++;
	}
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
		nbr_char++;
	}
	return(nbr_char);
}