/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:35:38 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/22 16:41:44 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

#include <stdio.h> //ATTENTION

typedef struct s_options
{
	char specifier;
	unsigned int width;
	int minus;
	int zero;
	int dot;
	unsigned int precision;
	int error;
}	t_options;

int		is_in_flags(char c);
int 	is_specifier(char c);
void	init_struct(t_options *options);
void	define_flags(const char *ret, size_t i, t_options *options);
void	define_width(const char *ret, size_t i, t_options *options, va_list args);
void	define_precision(const char *ret, size_t i, t_options *options, va_list args);
void	define_specifier(const char *ret, size_t i, t_options *options);
void	define_struct(const char *ret, size_t i, t_options *options, va_list args);
int		ft_printf(const char *format, ...);

#endif