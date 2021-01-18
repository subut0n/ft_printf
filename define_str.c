/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:53:40 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/18 16:34:28 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_in_flags(char c)
{
	if (c == '0' || c == '-')
		return (1);
	return (0);
}

int is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void define_flags(const char *ret, size_t i, t_options options)
{
	while (is_in_flags(ret[i]))
	{
		if (ret[i] == '-')
			options.minus = 1;
		if (ret[i] == '0')
			options.zero = 1;
		i++;
	}
	if (options.zero == 1 && options.minus == 1)
		options.minus = 0;
}

void define_width(const char *ret, size_t i, t_options options, va_list args)
{
	unsigned int width;

	width = 0;
	while (is_in_flags(ret[i]))
		i++;
	if (ret[i] == '*')
	{
		if (ft_isdigit(ret[i - 1])|| ft_isdigit(ret[i + 1]))
			options.error = 1;
		width = args;
	}
	while (ret[i] >= '0' && ret[i] <= '9')
	{
		width = (width * 10) + (unsigned int)ret[i] - 48;
		i++;
	}
	options.width = width;
}

void define_precision(const char *ret, size_t i, t_options options, va_list args)
{
	unsigned int numb;

	numb = 0;
	while (ret[i] != '.' && !is_specifier(ret[i]))
		i++;
	if (ret[i] == '.')
		numb = 1;
	i = i + 1;
	if (ret[i] == '*')
	{
		if (ft_isdigit(ret[i - 1])|| ft_isdigit(ret[i + 1]))
			options.error = 1;
		numb = args;
	}
	while (ret[i] >= '0' && ret[i] <= '9')
	{
		numb = (numb * 10) + (unsigned int)ret[i] - 48;
		i++;
	}
	options.dot = numb;
}

void define_specifier(const char *ret, size_t i, t_options options)
{
	while (!is_specifier(ret[i]) && ret[i])
		i++;
	if (ret[i] == 'c' || ret[i] == 's' || ret[i] == 'p' || ret[i] == 'd' || ret[i] == 'i'
	|| ret[i] == 'u' || ret[i] == 'x' || ret[i] == 'X' || ret[i] == '%')
		options.specifier = ret[i];
	else
		options.error = 1;
}

void define_struct(const char *ret, size_t i, t_options options, va_list args)
{
	if (ret[i] != '%' && ret[i + 1])
		i = i + 1;
		define_flags(ret, i, options);
		define_width(ret, i, options, args);
		define_precision(ret, i, options, args);
		define_specifier(ret, i, options);
}