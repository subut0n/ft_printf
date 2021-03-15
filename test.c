/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:40:12 by addzikow          #+#    #+#             */
/*   Updated: 2021/03/12 16:53:54 by addzikow         ###   ########lyon.fr   */
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
	int free;

	free = 5;

	nbr1 = ft_printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);
	printf("\n");
	nbr2 = printf("%s %d %p %% %x", "bonjour ", 42, &free, 42);
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