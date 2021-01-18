/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:40:12 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/18 16:17:32 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

//cspdiuxX%
//-0.*

int main (void)
{
	char *str = "1235";
	int width;
	int i = 0;

	width = 0;
	while (str[i])
	{
		width = (width * 10) + (int)str[i] - 48;
		i++;
	}
	printf("%d\n", width);
	printf("%*.*d\n", 10, 5, 530);
}