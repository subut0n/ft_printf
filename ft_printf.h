/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:35:38 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/18 16:37:16 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include "libft/libft.h"
#include <stdarg.h>

typedef struct s_options
{
	char specifier;
	unsigned int width;
	int minus;
	int zero;
	unsigned int dot;
	int error;
}	t_options;

#endif