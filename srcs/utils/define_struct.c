/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:53:40 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/23 14:40:52 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	is_in_flags(char c)
{
	if (c == '0' || c == '-')
		return (1);
	return (0);
}

int is_specifier(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'u' || c == 'i' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void	init_struct(t_options *options)
{
	options->width = 0;
	options->minus = 0;
	options->zero = 0;
	options->precision = 0;
	options->neg_prec = 0;
	options->dot = 0;
	options->error = 0;
}

void	define_struct(const char *ret, size_t i, t_options *options, va_list args)
{
	if (ret[i] == '%' && ret[i + 1])
	{
		i = i + 1;
		init_struct(options);
		define_flags(ret, i, options);
		define_width(ret, i, options, args);
		define_precision(ret, i, options, args);
		define_specifier(ret, i, options);
		redefine_struct(options);
		// printf("\n"); 									//
		// printf("error = %d\n", options->error); 			// ESSAIS DE LA CONFORMITE DU PARSING
		// printf("minus = %d\n", options->minus); 			//
		// printf("zero = %d\n", options->zero); 			//
		// printf("width = %d\n", options->width); 			//
		// printf("dot = %d\n", options->dot);				//
		// printf("precision = %d\n", options->precision);	//
		// printf("neg_prec = %d\n", options->neg_prec);
		// printf("specifier = %c\n", options->specifier);	//
		// printf("\n");									//
	}
}