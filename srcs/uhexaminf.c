/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uhexaminf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 13:53:00 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/29 14:53:51 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		uhexaminf(const char *ret, size_t i, t_options *options, va_list args)
{
	int nbr_char;
	int nbr_digits;
	unsigned int nbr;

	nbr = va_arg(args, unsigned int);
	ft_putnbr_base(nbr,"0123456789ABCDEF");
	
}