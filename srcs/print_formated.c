/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:31:49 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/01 15:52:25 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_formated(t_options *options, va_list args)
{
	int nbr_char;

	nbr_char = 0;
	if (options->specifier == 'd' || options->specifier == 'i')
		nbr_char = intf(options, args);
	if (options->specifier == 'u')
		nbr_char = uintf(options, args);
	if (options->specifier == 'c')
		nbr_char = charf(options, args);
	if (options->specifier == 's')
		nbr_char = strf(options, args);
	if (options->specifier == 'x')
		nbr_char = uhexaminf(options, args);
	if (options->specifier == 'X')
		nbr_char = uhexamajf(options, args);
	return (nbr_char);
}