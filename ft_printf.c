/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:31:36 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/29 11:54:38 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

#include <stdio.h>

int	execution(const char *ret, t_options *options, va_list args)
{
	size_t i;
	int nbr_char;

	i = 0;
	nbr_char = 0;
	while (ret[i])
	{
		if (ret[i] != '%')
		{
			ft_putchar(ret[i]);
			nbr_char += 1;
		}
		if (ret[i] == '%')
		{
			define_struct(ret, i, options, args);
			nbr_char += print_formated(ret, i, options, args);
			i = i + 1;
			while (!is_specifier(ret[i]))
				i++;
		}
		i++;
	}
	return (nbr_char);
}


int	ft_printf(const char *format, ...)
{
	va_list args;
	t_options options;
	int nbr;
	const char *ret;


	ret = ft_strdup(format);
	va_start(args, format);
	nbr = execution(ret, &options, args);
	va_end(args);
	return(nbr);
}