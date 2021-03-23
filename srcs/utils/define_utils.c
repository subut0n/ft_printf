/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 14:37:38 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/23 14:38:49 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	define_flags(const char *ret, size_t i, t_options *options)
{
	while (is_in_flags(ret[i]))
	{
		if (ret[i] == '-')
			options->minus = 1;
		if (ret[i] == '0')
			options->zero = 1;
		i++;
	}
}

void	define_width(const char *ret, size_t i, t_options *options, va_list args)
{
	int width;
	size_t secure_flags;

	width = 0;
	secure_flags = i;
	while (is_in_flags(ret[i]))
	{
		i++;
		secure_flags++;
	}
	while (ret[i] >= '0' && ret[i] <= '9')
	{
		width = (width * 10) + (unsigned int)ret[i] - 48;
		i++;
	}
	if (ret[i] == '*')
	{
		if (ret[i - 1] == '0' && i - 1 >= secure_flags)
			options->error = 1;
		if ((ret[i - 1] != '0' && ft_isdigit(ret[i - 1])) || ft_isdigit(ret[i + 1]))
			options->error = 1;
		width = va_arg(args, int);
		if (width < 0)
		{
			width = -width;
			options->minus = 1;
		}
	}
	options->width = width;
}

void	define_precision(const char *ret, size_t i, t_options *options, va_list args)
{
	int numb;

	numb = 0;
	while (ret[i] != '.' && !is_specifier(ret[i]))
		i++;
	if (ret[i] == '.')
		options->dot = 1;
	i = i + 1;
	if (ret[i] == '-')
		options->error = 1;
	while (ret[i] >= '0' && ret[i] <= '9')
	{
		numb = (numb * 10) + (unsigned int)ret[i] - 48;
		i++;
	}
	if (options->dot == 1 && ret[i] == '*')
	{
		if (ft_isdigit(ret[i - 1]) || ft_isdigit(ret[i + 1]))
			options->error = 1;
		numb = va_arg(args, int);
		if (numb < 0)
		{
			options->neg_prec = numb;
			numb = 1;
		}
	}
	options->precision = numb;
}

void	define_specifier(const char *ret, size_t i, t_options *options)
{
	while (!is_specifier(ret[i]) && ret[i])
		i++;
	if (ret[i] == 'c' || ret[i] == 's' || ret[i] == 'p' || ret[i] == 'd' || ret[i] == 'i'
	|| ret[i] == 'u' || ret[i] == 'x' || ret[i] == 'X' || ret[i] == '%')
		options->specifier = ret[i];
	else
		options->error = 1;
}

void	redefine_struct(t_options *options)
{
	if (options->zero == 1 && options->minus == 1 && options->neg_prec == 0)
		options->zero = 0;
	if (options->zero == 1 && options->minus == 0 && options->precision == 0 && options->dot == 0)
		options->precision = options->width;
}