/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formated.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 14:31:49 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/29 13:52:35 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_formated(const char *ret, size_t i, t_options *options, va_list args)
{
	int nbr_char;

	nbr_char = 0;
	if (options->specifier == 'd' || options->specifier == 'i')
		nbr_char = intf(ret, i, options, args);
	if (options->specifier == 'u')
		nbr_char = uintf(ret, i, options, args);
	if (options->specifier == 'c')
		nbr_char = charf(options, args);
	if (options->specifier == 's')
		nbr_char = strf(options, args);
	if (options->specifier == 'x')
		nbr_char = hexaminf(ret, i, options, args);
	return (nbr_char);
}