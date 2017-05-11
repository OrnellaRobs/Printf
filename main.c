/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:19:33 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/11 14:52:14 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	// char	*str = "bonjour";

	printf("%s\n", ft_itoa_base_printf(25, 8));
		printf("%o\n", 25));
	// printf("--------- conversion c ---------\n\n");

	// printf("%d\n", -2147483649);
	// printf("%c\n\n", '\0');

	// ft_printf("%04c\n", 'b');
	// printf("%04c\n", 'b');

	// ft_printf("%7.5c\n", 'b');
	// printf("%7.5c\n\n", 'b');
	//
	// ft_printf("%-7.5c\n", 'b');
	// printf("%-7.5c\n\n", 'b');
	//
	// ft_printf("%5.5c\n", 'b');
	// printf("%5.5c\n\n", 'b');
	//
	// ft_printf("%-1.5c\n", 'b');
	// printf("%-1.5c\n\n", 'b');
	//
	// ft_printf("%1.5c\n", 'b');
	// printf("%1.5c\n\n", 'b');

	// printf("--------- conversion s ---------\n\n");
	//
	// ft_printf("%s\n", NULL);
	// printf("%s\n\n", NULL);
	//
	// ft_printf("%-s\n", NULL);
	// printf("%-s\n\n", NULL);
	//
	// ft_printf("%s\n", NULL);
	// printf("%s\n\n", NULL);
	//
	// ft_printf("%04s\n", NULL);
	// printf("%04s\n\n", NULL);
	// //
	// ft_printf("%04s\n", NULL);
	// printf("%04s\n\n", NULL);

	// ft_printf("%013s\n", NULL);
	// printf("%013s\n\n", NULL);

	// ft_printf("%013s\n", NULL);
	// printf("%013s\n\n", NULL);
	//
	// ft_printf("%013s\n", NULL);
	// printf("%013s\n\n", NULL);

	// ft_printf("%-9.8s\n", NULL);
	// printf("%-9.8s\n\n", NULL);
	//
	// ft_printf("%7.5s\n", NULL);
	// printf("%7.5s\n\n", NULL);
	//
	// ft_printf("%-7.5s\n", NULL);
	// printf("%-7.5s\n\n", NULL);
	//
	// ft_printf("%7.5s\n", NULL);
	// printf("%7.5s\n\n", NULL);
	//
	// ft_printf("%5.5s\n", NULL);
	// printf("%5.5s\n\n", NULL);
	//
	// ft_printf("%5.5s\n", NULL);
	// printf("%5.5s\n\n", NULL);
	//
	// ft_printf("%-5.5s\n", NULL);
	// printf("%-5.5s\n\n", NULL);
	//
	// ft_printf("%-5.5s\n", NULL);
	// printf("%-5.5s\n\n", NULL);
	//
	// ft_printf("%-1.5s\n", NULL);
	// printf("%-1.5s\n\n", NULL);
	//
	// ft_printf("%1.5s\n", NULL);
	// printf("%1.5s\n\n", NULL);
	//
	// ft_printf("%-1.5s\n", NULL);
	// printf("%-1.5s\n\n", NULL);
	//
	// ft_printf("%1.5s\n", NULL);
	// printf("%1.5s\n\n", NULL);

	// printf("--------- conversion d ---------\n\n");
	//
	//
	// ft_printf("%+d\n", 12);
	// printf("%+u\n\n", 12);

	// ft_printf("%d\n", 12);
	// printf("%d\n\n", 12);
	//
	// ft_printf("%d\n", -12);
	// printf("%d\n\n", -12);
	//
	// ft_printf("%04d\n", -12);
	// printf("%04d\n\n", -12);
	//
	// ft_printf("%04d\n", 12);
	// printf("%04d\n\n", 12);
	//
	// ft_printf("%013d\n", -12);
	// printf("%013d\n\n", -12);
	//
	// ft_printf("%013d\n", 12);
	// printf("%013d\n\n", 12);
	//
	// ft_printf("%-7.5d\n", -12);
	// printf("%-7.5d\n\n", -12);
	//
	// ft_printf("%7.5d\n", -12);
	// printf("%7.5d\n\n", -12);
	//
	// ft_printf("%-7.5d\n", -12);
	// printf("%-7.5d\n\n", -12);
	//
	// ft_printf("%7.5d\n", 12);
	// printf("%7.5d\n\n", 12);
	//
	// ft_printf("%5.5d\n", -12);
	// printf("%5.5d\n\n", -12);
	//
	// ft_printf("%5.5d\n", 12);
	// printf("%5.5d\n\n", 12);
	//
	// ft_printf("%-5.5d\n", 12);
	// printf("%-5.5d\n\n", 12);
	//
	// ft_printf("%-5.5d\n", -12);
	// printf("%-5.5d\n\n", -12);
	//
	// ft_printf("%-1.5d\n", -12);
	// printf("%-1.5d\n\n", -12);
	//
	// ft_printf("%1.5d\n", 12);
	// printf("%1.5d\n\n", 12);
	//
	// ft_printf("%-1.5d\n", 12);
	// printf("%-1.5d\n\n", 12);
	//
	// ft_printf("%1.5d\n", -12);
	// printf("%1.5d\n\n", -12);

	// printf("--------- conversion u ---------\n\n");
	//
	// ft_printf("%u\n", 12);
	// printf("%u\n\n", 12);
	//
	// ft_printf("%-u\n", -12);
	// printf("%-u\n\n", -12);
	//
	// ft_printf("%u\n", -12);
	// printf("%u\n\n", -12);
	//
	// ft_printf("%04u\n", -12);
	// printf("%04u\n\n", -12);
	//
	// ft_printf("%04u\n", 12);
	// printf("%04u\n\n", 12);
	//
	// ft_printf("%013u\n", -12);
	// printf("%013u\n\n", -12);
	//
	// ft_printf("%013u\n", 12);
	// printf("%013u\n\n", 12);
	//
	// ft_printf("%-7.5u\n", -12);
	// printf("%-7.5u\n\n", -12);
	//
	// ft_printf("%7.5u\n", -12);
	// printf("%7.5u\n\n", -12);
	//
	// ft_printf("%-7.5u\n", -12);
	// printf("%-7.5u\n\n", -12);
	//
	// ft_printf("%7.5u\n", 12);
	// printf("%7.5u\n\n", 12);
	//
	// ft_printf("%5.5u\n", -12);
	// printf("%5.5u\n\n", -12);
	//
	// ft_printf("%5.5u\n", 12);
	// printf("%5.5u\n\n", 12);
	//
	// ft_printf("%-5.5u\n", 12);
	// printf("%-5.5u\n\n", 12);
	//
	// ft_printf("%-5.5u\n", -12);
	// printf("%-5.5u\n\n", -12);
	//
	// ft_printf("%-1.5u\n", -12);
	// printf("%-1.5u\n\n", -12);
	//
	// ft_printf("%1.5u\n", 12);
	// printf("%1.5u\n\n", 12);
	//
	// ft_printf("%-1.5u\n", 12);
	// printf("%-1.5u\n\n", 12);
	//
	// ft_printf("%1.5u\n", -12);
	// printf("%1.5u\n\n", -12);


	return 0;
}
