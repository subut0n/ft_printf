/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:53:40 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/23 15:04:56 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	is_in_flags(char c)
{
	if (c == '0' || c == '-')
		return (1);
	return (0);
}

int	is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u' || c == 'i'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	init_struct(t_options *opt)
{
	opt->width = 0;
	opt->minus = 0;
	opt->zero = 0;
	opt->precision = 0;
	opt->neg_prec = 0;
	opt->dot = 0;
	opt->error = 0;
}

void	define_struct(const char *ret, size_t i, t_options *opt, va_list args)
{
	if (ret[i] == '%' && ret[i + 1])
	{
		i = i + 1;
		init_struct(opt);
		define_flags(ret, i, opt);
		define_width(ret, i, opt, args);
		define_prec(ret, i, opt, args);
		define_specifier(ret, i, opt);
		redefine_struct(opt);
	}
}
