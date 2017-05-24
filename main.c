/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:19:33 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/24 20:05:15 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>
int		main(void)
{
	setlocale(P_ALL, "");

	int i;
	int j;

	// printf("vrai : %lx|\n", 17);
	// ft_printf("mien : %lx|\n", 17);
	// printf("%%%%C\n", °);

	// printf("vrai : %20%20%20%d|\n", 10);
	// ft_printf("mien : %20%20%20%d|\n", 10);
/* 	flag 0 PAREIL */
	// printf("vrai : %05.2C|\n", 10);
	// ft_printf("mien : %05.2C|\n", 10);
	// printf("vrai : %.5d|\n", 10);
	// ft_printf("mien : %.5d|\n", 10);
	// printf("vrai : %5.2C|\n", 'a');
	// ft_printf("mien : %5.2C|\n", 'a');
	/*TEST A GERER !!!!!!!!!!!!!!!!!!!*/
	// printf("Vrai %d\n",printf("%#o|",  10));
	// printf("Mien %d\n",ft_printf("%#o|", 10));
	/*FIN TEST A GERER !!!!!!!!!!!!!!!!!!!*/
	//printf("vrai = %10S|\n", L"°ασΠ");
	//ft_printf("mien = %10s|\n", "abcd");
 	//printf("vrai = %10s|\n", "abcd");
	//ft_printf("mien = %10S|\n", L"°ασΠ");
	//printf("vrai : %5.2C|\n", L"°°°°°");
	//ft_printf("mien : %5.2C|\n", L"°°°°°");

	// ft_printf("%%%%d", 8);
	// printf("vrai %s d'accard Nobila %20.19u\n", str, -12);
	// printf("vrai %p\n", b);
	// ft_printf("mien %s d'accord Nobila %20.19u", str, -12);
	// ft_printf("mien %p\n", b);
	// printf("%x\n", b);
	// printf("%x", test2);
	// ft_printf("mien%#o\n\n", -12);

	// printf("%p\n\n", str);
	// printf("%25o\n\n", -2);
		// printf("%llp\n\n", str);
		// printf("%p\n\n", str);
		// ft_printf("%p\n\n", str);
	//
		printf("--------- conversion x et X ---------\n\n");
	//
	// i = printf("vrai%-.x|\n", 0);
	// j = ft_printf("mien%-.x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-#x|\n", -12);
	// j = ft_printf("mien %-#x|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// printf("----> DEBUT BUG <----\n\n");
	// i = printf("vrai %-0x|\n", 0);
	// j = ft_printf("mien %-0x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i =	printf("vrai %#-0x|\n", 0);
	// j = ft_printf("mien %#-0x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-#.2X|\n", 0);
	// j = ft_printf("mien %-#.2X|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// printf("----> FIN BUG <----\n\n");
	// i = printf("vrai %-10.X|\n", 0);
	// j = ft_printf("mien %-10.X|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#10.4X|\n", 1);
	// j = ft_printf("mien %#10.4X|\n", 1);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0x|\n", 0);
	// j = ft_printf("mien %0x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %-0x|\n", 0);
	// j = ft_printf("mien %-0x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#-0x|\n", 0);
	// j = ft_printf("mien %#-0x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#-0x|\n", -12);
	// j = ft_printf("mien %#-0x|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-10.x|\n", 0);
	// j = ft_printf("mien %-10.x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#.x|\n", 0);
	// j = ft_printf("mien %#.x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#10.x|\n", 0);
	// j = ft_printf("mien %#10.x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%#jx|\n", -25);
	// j = ft_printf("%#jx|\n", -25);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("|%7.4lx|\n", -25);
	// j = ft_printf("|%7.4lx|\n", -25);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%8.6lx|\n", -25);
	// j = ft_printf("%8.6lx|\n", -25);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%6.6lx|\n", -25);
	// j = ft_printf("%6.6lx|\n", -25);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%4.6lx|\n", -25);
	// j = ft_printf("%4.6lx|\n", -25);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

printf("--------- conversion o ---------\n\n");

	// i = printf("vrai%#.o\n", 0);
	// j = ft_printf("mien%#.o\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%.o|\n", 0);
	// j = ft_printf("mien%.o|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%o\n", 0);
	// j = ft_printf("mien%o\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// printf("----> BUG PROCHAIN <----\n\n");
	//
	// i = printf("vrai %10.o|\n", 0);
	// j = ft_printf("mien %10.o|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#10.o|\n", 0);
	// j = ft_printf("mien %#10.o|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#10.o|\n", -12);
	// j = ft_printf("mien %#10.o|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%#o\n", -12);
	// j = ft_printf("mien%#o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%o\n", -12);
	// j = ft_printf("mien%o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%#15.9o\n", -12);
	// j = ft_printf("mien%#15.9o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%15.11o\n", -12);
	// j = ft_printf("mien%15.11o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%#15.11o\n", -12);
	// j = ft_printf("mien%#15.11o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%#15.14o\n", -12);
	// j = ft_printf("mien%#15.14o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%15.14o\n", -12);
	// j = ft_printf("mien%15.14o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%15.18o\n", -12);
	// j = ft_printf("mien%15.18o\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#.o|\n", 0);
	// j = ft_printf("mien %#.o|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %o|\n", 0);
	// j = ft_printf("mien %o|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %#o|\n", 0);
	// j = ft_printf("mien %#o|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%#o|\n", 9);
	// j = ft_printf("%#o|\n", 9);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%#lo|\n", -1);
	// j = ft_printf("%#lo|\n", -1);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	printf("--------- conversion c ---------\n\n");

	ft_printf("mien %04c|\n", 'b');
	printf("vrai %04c|\n", 'b');

	ft_printf("%7.5c|\n", 'b');
	printf("%7.5c|\n\n", 'b');

	ft_printf("%-7.5c|\n", 'b');
	printf("%-7.5c|\n\n", 'b');

	ft_printf("%5.5c|\n", 'b');
	printf("%5.5c|\n\n", 'b');

	ft_printf("%-1.5c|\n", 'b');
	printf("%-1.5c|\n\n", 'b');

	ft_printf("vrai %1.0c|\n", 'b');
	printf("mien %1.0c|\n\n", 'b');

	ft_printf("vrai %1.5c|\n", 'b');
	printf("mien %1.5c|\n\n", 'b');

	printf("--------- conversion s ---------\n\n");

	// ft_printf("mien %-s|\n", NULL);
	// printf("vrai %-s|\n\n", NULL);
	//
	//  ft_printf("mien %-s|\n", "");
	//  printf("vrai %-s|\n\n", "");
	//
	// ft_printf("mien %s|\n", NULL);
	// printf("vrai %s|\n\n", NULL);
	//
	// ft_printf("mien %04s|\n", NULL);
	// printf("vrai %04s|\n\n", NULL);

	// ft_printf("mien %-013s|\n", NULL);
	// printf("vrai %-013s|\n\n", NULL);

	// ft_printf("mien %-9.8s|\n", NULL);
	// printf("vrai %-9.8s|\n\n", NULL);
	//
	// ft_printf("mien %7.5s|\n", NULL);
	// printf("vrai %7.5s|\n\n", NULL);
	//
	// ft_printf("mien %-7.5s|\n", NULL);
	// printf("vrai %-7.5s|\n\n", NULL);
	//
	// ft_printf("mien %5.5s|\n", NULL);
	// printf("vrai %5.5s|\n\n", NULL);
	//
	// ft_printf("mien %-5.5s|\n", NULL);
	// printf("vrai %-5.5s|\n\n", NULL);
	//
	// ft_printf("mien %-1.5s|\n", NULL);
	// printf("vrai %-1.5s|\n\n", NULL);
	//
	// ft_printf("mien %1.5s|\n", NULL);
	// printf("vrai %1.5s|\n\n", NULL);

	printf("--------- conversion d et i ---------\n\n");

	// printf("vrai %0d|\n", 0);
	// ft_printf("mien %0d|\n\n", 0);

	// printf("vrai %0i|\n", 0);
	// ft_printf("mien %0i|\n\n", 0);

	// printf("vrai %d|\n", printf("%.i", 0));
	// printf("mien %d|\n\n", ft_printf("%.i", 0));

	// printf("vrai %.d|\n", 0);
	// ft_printf("mien %.d|\n\n", 0);

	// ft_printf("mien %+d|\n", 12);
	// printf("vrai %+d|\n\n", 12);
	//
	// ft_printf("mien %d|\n", 12);
	// printf("vrai %d|\n\n", 12);
	//
	// ft_printf("mien %d|\n", -12);
	// printf("vrai %d|\n\n", -12);
	//
	// ft_printf("mien %04d|\n", -12);
	// printf("vrai %04d|\n\n", -12);
	//
	// ft_printf("mien %04d|\n", 12);
	// printf("vrai %04d|\n\n", 12);
	//
	// ft_printf("mien %013d|\n", -12);
	// printf("vrai %013d|\n\n", -12);
	//
	// ft_printf("mien %013d|\n", 12);
	// printf("vrai %013d|\n\n", 12);
	//
	// ft_printf("mien%8.5d|\n", -12);
	// printf("vrai%8.5d|\n\n", -12);
	//
	// ft_printf("mien %-7.5d|\n", -12);
	// printf("vrai %-7.5d|\n\n", -12);
	//
	// ft_printf("mien %7.5d|\n", 12);
	// printf("vrai %7.5d|\n\n", 12);
	//
	// ft_printf("mien %5.5d|\n", -12);
	// printf("vrai %5.5d|\n\n", -12);
	//
	// ft_printf("mien %5.5d|\n", 12);
	// printf("vrai %5.5d|\n\n", 12);
	//
	// ft_printf("mien %-5.5d|\n", 12);
	// printf("vrai %-5.5d|\n\n", 12);
	// //
	// ft_printf("mien %-5.5d|\n", -12);
	// printf("vrai %-5.5d|\n\n", -12);
	//
	// ft_printf("mien %-1.5d|\n", -12);
	// printf("vrai %-1.5d|\n\n", -12);
	//
	// ft_printf("mien %1.5d|\n", 12);
	// printf("vrai %1.5d|\n\n", 12);
	//
	// ft_printf("mien %-1.5d|\n", 12);
	// printf("vrai %-1.5d|\n\n", 12);
	//
	// ft_printf("mien %1.5d|\n", -12);
	// printf("vrai %1.5d|\n\n", -12);

	// printf("--------- conversion u ---------\n\n");
	//
	// printf("vrai %0u|\n", 0);
	// ft_printf("mien %0u|\n\n", 0);

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
