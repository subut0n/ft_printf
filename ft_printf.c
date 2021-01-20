/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:31:36 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/20 15:42:45 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list args;
	t_options options;
	const char *ret;

	ret = ft_strdup(format);
	va_start(args, format);
	define_struct(ret, 0, &options, args);
	va_end(args);
	return(0);
}