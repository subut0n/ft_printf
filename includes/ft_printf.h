/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:35:38 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/24 14:34:36 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

# include <stdio.h> //ATTENTION

typedef struct s_options
{
	char			specifier;
	unsigned int	width;
	int				minus;
	int				zero;
	int				dot;
	unsigned int	precision;
	int				neg_prec;
	int				error;
}	t_options;

int		is_in_flags(char c);
int		is_specifier(char c);
void	init_struct(t_options *opt);
void	define_flags(const char *ret, size_t i, t_options *opt);
void	define_width(const char *ret, size_t i, t_options *opt, va_list args);
void	define_prec(const char *ret, size_t i, t_options *opt, va_list args);
void	define_specifier(const char *ret, size_t i, t_options *opt);
void	redefine_struct(t_options *opt);
void	define_struct(const char *ret, size_t i, t_options *opt, va_list args);
int		print_formated(t_options *options, va_list args);
int		ft_printf(const char *format, ...);
int		execution(const char *ret, t_options *options, va_list args);
int		intf(t_options *options, va_list args);
int		uintf(t_options *options, va_list args);
int		charf(t_options *options, va_list args);
int		strf(t_options *options, va_list args);
int		uhexaminf(t_options *options, va_list args);
int		uhexamajf(t_options *options, va_list args);
int		pointerf(t_options *options, va_list args);
int		percentf(t_options *options);

#endif