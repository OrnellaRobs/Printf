/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:19:33 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/12 22:38:59 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(void)
{
	char	*str = "bonjour";
	char 	*test2 = "tsst";

	int a;
	int *b;
	a = 1;
	b = &a;

	printf("vrai%p\n", test2);
	printf("vrai chiffre %p\n", b);
	printf("%x\n", b);
	printf("%x", test2);
	// ft_printf("mien%#o\n\n", -12);

	// printf("vrai%#o\n", -12);
	// ft_printf("mien%#o\n\n", -12);

	// printf("vrai%o\n", -12);
	// ft_printf("mien%o\n\n", -12);
	//
	// printf("vrai%#15.9o\n", -12);
	// ft_printf("mien%#15.9o\n\n", -12);
	//
	// printf("vrai%15.11o\n", -12);
	// ft_printf("mien%15.11o\n\n", -12);
	// //
	// printf("vrai%#15.11o\n", -12);
	// ft_printf("mien%#15.11o\n\n", -12);
	//
	// printf("vrai%#15.14o\n", -12);
	// ft_printf("mien%#15.14o\n\n", -12);
	//
	// printf("vrai%15.14o\n", -12);
	// ft_printf("mien%15.14o\n\n", -12);

	// printf("vrai%15.18o\n", -12);
	// ft_printf("mien%15.18o\n\n", -12);
			// printf("%p\n\n", str);
			// printf("%25o\n\n", -2);
				// printf("%llp\n\n", str);
				// printf("%p\n\n", str);
				// ft_printf("%p\n\n", str);
		// ft_printf("%#o\n", 9);
		// printf("%#x\n", -25);
		// printf("%7.4x\n, -25");
		// printf("%8.6x\n", -25);
		// printf("%6.6x\n", -25);
		// printf("%4.6x\n", -25);
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
