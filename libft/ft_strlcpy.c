/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:06:05 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/15 12:31:18 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t len_s;

	if (!src)
		return (0);
	len_s = ft_strlen(src);
	if (size)
	{
		size = len_s + 1 < size ? len_s + 1 : size;
		ft_bzero(dst, size);
		ft_memmove(dst, src, size - 1);
	}
	return (len_s);
}
