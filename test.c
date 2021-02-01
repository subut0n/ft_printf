/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 12:40:12 by addzikow          #+#    #+#             */
/*   Updated: 2021/02/01 14:37:24 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

//cspdiuxX%
//-0.*

int main (void)
{
	int nbr1;
	int nbr2;

	nbr1 = ft_printf("%-15d", 125);
	printf("\n");
	nbr2 = printf("%-15d", 125);
	printf("\n");
	printf("nbr1 = %d\n", nbr1);
	printf("nbr2 = %d\n", nbr2);

	// int nbr1;
	// int nbr2;

	// nbr1 = ft_printf("coucou %*s moi", 7, "Hello");
	// printf("\n");
	// nbr2 = printf("coucou %*s moi", 7, "Hello");
	// printf("\n");
	// printf("nbr1 = %d\n", nbr1);
	// printf("nbr2 = %d\n", nbr2);
}