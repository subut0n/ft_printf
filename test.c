/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:40:12 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/11 15:33:23 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"

//cspdiuxX%
//-0.*

int main (void)
{
	int nbr1;
	int nbr2;
	int a;

	a = 5;

	nbr1 = ft_printf("%p", NULL);
	printf("\n");
	nbr2 = printf("%p", NULL);
	printf("\n");
	printf("nbr1 = %d\n", nbr1);
	printf("nbr2 = %d\n", nbr2);

	// int nbr1;
	// int nbr2;

	// nbr1 = ft_printf("%-.09s", "hi low");
	// printf("\n");
	// nbr2 = printf("%-.09s", "hi low");
	// printf("\n");
	// printf("nbr1 = %d\n", nbr1);
	// printf("nbr2 = %d\n", nbr2);
}