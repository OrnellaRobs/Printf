/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 10:19:33 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/30 19:01:40 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf_last/ft_printf.h"
#include <locale.h>
#include <limits.h>
int		main(void)
{
	 setlocale(LC_ALL, "");

	int i;
	int j;


	// printf("%C\n", °);

	// printf("\nk = %d\n", i);
/* 	flag 0 PAREIL */
	// printf("vrai : %05.2C|\n", 10);
	// ft_printf("mien : %05.2C|\n", 10);
	// printf("vrai : %.5d|\n", 10);
	// ft_printf("mien : %.5d|\n", 10);
	// printf("vrai : %5.2C|\n", 'a');
	// ft_printf("mien : %5.2C|\n", 'a');
	// i = printf("vrai = %10S|\n", L"°ασΠ");
	// j = ft_printf("mien = %10S|\n", L"°ασΠ");

	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// printf("vrai : %C\n", 945);
	// ft_printf("mien : %C\n", 945);
	//ft_printf("mien = %10s|\n", "abcd");
 	//printf("vrai = %10s|\n", "abcd");

	// printf("vrai : %5.2C|\n", L"°°°°°");
	// ft_printf("mien : %5.2C|\n", L"°°°°°");

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
	printf("\n--------- undefined behavior Moulitest qui ne passent pas ---------\n\n");

	i = printf("vrai %5.d %5.0d|\n", 0, 0);
	j = ft_printf("mien %5.d %5.0d|\n", 0, 0);

	printf("i = %d\n", i);
	printf("j = %d\n\n", j);

	i = printf("vrai {%0-3d}|\n", 0);
	j = ft_printf("mien {%0-3d}|\n", 0);

	printf("i = %d\n", i);
	printf("j = %d\n\n", j);
	
	i = printf("vrai %####0000 33..1..#00d|\n", 256);
	j = ft_printf("mien %####0000 33..1..#00d|\n", 256);

	printf("i = %d\n", i);
	printf("j = %d\n\n", j);

	i = printf("vrai %####0000 33..1d|\n", 256);
	j = ft_printf("mien %####0000 33..1d|\n", 256);

	printf("i = %d\n", i);
	printf("j = %d\n\n", j);

	i = printf("vrai %.0d|\n", 0);
	j = ft_printf("mien %.0d|\n", 0);

	printf("i = %d\n", i);
	printf("j = %d\n\n", j);

	i = printf("vrai %###-#0000 33...12..#0+0d|\n", 256);
	j = ft_printf("mien %###-#0000 33...12..#0+0d|\n", 256);

	printf("i = %d\n", i);
	printf("j = %d\n\n", j);

	printf("\n--------- conversion p ---------\n\n");


	// i = printf("vrai {%5.2p}|\n", 0);
	// j = ft_printf("mien {%5.2p}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("mien %2.9p|\n", 1234);
	// j = ft_printf("mien %2.9p|\n", 1234);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien %2.3p|\n", 1234);
	// j = ft_printf("mien %2.3p|\n", 1234);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %.5p|\n", 0);
	// j = ft_printf("mien %.5p|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%5p}|\n", 0);
	// j = ft_printf("mien {%5p}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %.0p, %.p|\n", 0, 0);
	// j = ft_printf("mien %.0p, %.p|\n", 0, 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %.p, %.0p|\n", 0, 0);
	// j = ft_printf("mien %.p, %.0p|\n", 0, 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	printf("\n--------- conversion S ---------\n\n");

	// i = printf("mien %4.1S|\n", L"Jambon ok");
	// j = ft_printf("mien %4.1S|\n", L"Jambon ok");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %.6S|\n", L"我是一只猫。");
	// j = ft_printf("vrai %.6S|\n", L"我是一只猫。");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai {%030S}|\n", L"我是一只猫。");
	// j = ft_printf("mien {%030S}|\n", L"我是一只猫。");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %12.3S|\n", L"°°°°°");
	// j = ft_printf("mien : %12.3S|\n", L"°°°°°");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %7S|\n", L"°°°°°");
	// j = ft_printf("mien : %7S|\n", L"°°°°°");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %9.S|\n", 0);
	// j = ft_printf("mien : %9.S|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%5.8S}|\n", L"42 c est cool");
	// j = ft_printf("mien {%5.8S}|\n", L"42 c est cool");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	printf("\n--------- conversion C ---------\n\n");
	// i = printf("mien %lc, %lc|\n", L'暖', L'ح');
	// j = ft_printf("mien %lc, %lc|\n", L'暖', L'ح');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	// //
	// // i = printf("vrai {% C}|\n", 0);
	// // j = ft_printf("mien {% C}|\n", 0);
	// //
	// // printf("i = %d\n", i);
	// // printf("j = %d\n\n", j);
	// //
	// // i = printf("vrai %+C|\n", 0);
	// // j = ft_printf("mien %+C|\n", 0);
	// //
	// // printf("i = %d\n", i);
	// // printf("j = %d\n\n", j);
	// //
	// // i = printf("vrai : %C|\n", 945);
	// // j = ft_printf("mien : %C|\n", 945);
	// //
	// // printf("i = %d\n", i);
	// // printf("j = %d\n\n", j);
	// // //
	// // i = printf("vrai : %C|\n", 0);
	// // j = ft_printf("mien : %C|\n", 0);
	// //
	// // printf("i = %d\n", i);
	// // printf("j = %d\n\n", j);

	printf("--------- CAS %% ---------\n\n");
	//
	// i = printf("mien {%05.Z}|\n", 0);
	// j = ft_printf("mien {%05.Z}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien {%05.c}|\n", 0);
	// j = ft_printf("mien {%05.c}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien {%05.%}|\n", 0);
	// j = ft_printf("mien {%05.%}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-05%|\n");
	// j =  ft_printf("mien %-05%|\n");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %20%20%20%d|\n", 10);
	// j = ft_printf("mien : %20%20%20%d|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %-25%|\n", 10);
	// j = ft_printf("mien : %-25%|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %25%|\n", 10);
	// j = ft_printf("mien : %25%|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %%%25|\n", 10);
	// j = ft_printf("mien : %%%25|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %%%-25|\n", 10);
	// j = ft_printf("mien : %%%-25|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %%%%25|\n", 10);
	// j = ft_printf("mien : %%%%25|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %%%%-25|\n", 10);
	// j = ft_printf("mien : %%%%-25|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : |% #-12Zoooo|\n", 10);
	// j = ft_printf("mien : |% #-12Zoooo|\n", 10);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

		printf("--------- conversion x et X ---------\n\n");

	// i = printf("vrai {%04.x}|\n", 0);
	// j = ft_printf("mien {%04.x}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%04.0x}|\n", 0);
	// j = ft_printf("mien {%04.0x}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %#08x|\n", 42);
	// j = ft_printf("mien %#08x|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %#8x|\n", 42);
	// j = ft_printf("mien %#8x|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %x|\n", 0);
	// j = ft_printf("mien %x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %013x|\n", -12);
	// j = ft_printf("mien %013x|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%-.x|\n", 0);
	// j = ft_printf("mien%-.x|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %-#x|\n", -12);
	// j = ft_printf("mien %-#x|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
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
	//
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

	// i = printf("vrai %#.O|\n", 0);
	// j = ft_printf("mien %#.O|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
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
	// i = printf("vrai%.O|\n", 0);
	// j = ft_printf("mien%.O|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %05o|\n", 42);
	// j = ft_printf("mien %05o|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai : %jd\n", LLONG_MAX);
	// j = ft_printf("mien : %jd\n", LLONG_MAX);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %hhO\n", SHRT_MAX);;
	// j = ft_printf("mien : %hhO\n", SHRT_MAX);
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %hhO\n", USHRT_MAX);;
	// j = ft_printf("mien : %hhO\n", USHRT_MAX);
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
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
	//
	// //
	// i = printf("mien {%05.c}|\n", 0);
	// j = ft_printf("mien {%05.c}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien {%c}|\n", 0);
	// j = ft_printf("mien {%c}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien {%3c}|\n", 0);
	// j = ft_printf("mien {%3c}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien {%3.2c}|\n", 0);
	// j = ft_printf("mien {%3.2c}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%05.c}|\n", 0);
	// j = ft_printf("mien {%05.c}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %.c|\n", '\0');
	// j = ft_printf("mien %.c|\n", '\0');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %013c|\n", 'b');
	// j = ft_printf("mien %013c|\n", 'b');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %7.5c|\n", 'b');
	// j = ft_printf("mien %7.5c|\n", 'b');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	// //
	// i = printf("vrai %-7.5c|\n", 'b');
	// j = ft_printf("mien %-7.5c|\n", 'b');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %5.5c|\n", 'b');
	// j = ft_printf("mien %5.5c|\n", 'b');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-1.5c|\n", 'b');
	// j = ft_printf("mien %-1.5c|\n", 'b');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %1.0c|\n", 'b');
	// j = ft_printf("mien %1.0c|\n", 'b');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %1.5c|\n", 'b');
	// j = ft_printf("mien %1.5c|\n", 'b');
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	printf("--------- conversion s ---------\n\n");
	//

	// i = printf("vrai %-013s|\n", NULL);
	// j = ft_printf("mien %-013s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%5.s}|\n", 0);
	// j = ft_printf("mien {%5.s}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %04s|\n", NULL);
	// j = ft_printf("mien %04s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
// //DEBUT BUG
	//
	// i = printf("vrai %10s is a string|\n", "");
	// j = ft_printf("mien %10s is a string|\n", "");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	// //
	// i = printf("vrai {%05.2s}|\n", "oui");
	// j = ft_printf("mien {%05.2s}|\n", "oui");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%5.2s}|\n", "oui");
	// j = ft_printf("mien {%5.2s}|\n", "oui");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%05.0s}|\n", 0);
	// j = ft_printf("mien {%05.0s}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%05.s}|\n", 0);
	// j = ft_printf("mien {%05.s}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai {%07s}|\n", 0);
	// j = ft_printf("mien {%07s}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//FIN BUG
	// i = printf("vrai {%5.3s}|\n", 0);
	// j = ft_printf("mien {%5.3s}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %4.15s|\n", "42");
	// j = ft_printf("mien %4.15s|\n", "42");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %4.5s|\n", "42");
	// j = ft_printf("mien %4.5s|\n", "42");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %7.5s|\n", NULL);
	// j = ft_printf("mien %7.5s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %5.5s|\n", NULL);
	// j = ft_printf("mien %5.5s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-s|\n", NULL);
	// j = ft_printf("mien %-s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-s|\n", "");
	// j = ft_printf("mien %-s|\n", "");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %s|\n", NULL);
	// j = ft_printf("mien %s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-9.8s|\n", NULL);
	// j = ft_printf("mien %-9.8s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-7.5s|\n", NULL);
	// j = ft_printf("mien %-7.5s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-5.5s|\n", NULL);
	// j = ft_printf("mien %-5.5s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-1.5s|\n", NULL);
	// j = ft_printf("mien %-1.5s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %1.5s|\n", NULL);
	// j = ft_printf("mien %1.5s|\n", NULL);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	printf("--------- conversion d et i ---------\n\n");
	// //
	// i = printf("vrai {% 03d}|\n", 0);
	// j = ft_printf("mien {% 03d}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("mien {%0-3d}|\n", 0);
	// j = ft_printf("mien {%0-3d}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai %+10.5d|\n", 4242);
	// j = ft_printf("mien %+10.5d|\n", 4242);
	// i = printf("vrai %03.2d|\n", 0);
	// j = ft_printf("mien %03.2d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien %03.2d|\n", -1);
	// j = ft_printf("mien %03.2d|\n", -1);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);


	// //TESTS QUI BUG
	// i = printf("vrai {% 03d}|\n", 0);
	// j = ft_printf("mien {% 03d}|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("mien %05.d|\n", -1);
	// j = ft_printf("mien %05.d|\n", -1);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0+5.d|\n", 1);
	// j = ft_printf("mien %0+5.d|\n", 1);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// printf("\n----> BUG PROCHAIN TEST (UNDEFINED BEHAVIOR NON TRAITÉ)<----\n\n");
	// i = printf("vrai @main_ftprintf: %####0000 33..1d|\n", 256);
	// j = ft_printf("mien @main_ftprintf: %####0000 33..1d|\n", 256);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %15.4d|\n", -424242);
	// j = ft_printf("mien %15.4d|\n", -424242);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0+5d|\n", 42);
	// j = ft_printf("mien %0+5d|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-05d|\n", -42);
	// j = ft_printf("mien %-05d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-5d|\n", -42);
	// j = ft_printf("mien %-5d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai % 0d|\n", 42);
	// j = ft_printf("mien % 0d|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %+d|\n", -42);
	// j = ft_printf("mien %+d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %ld\n", LLONG_MAX);
	// j = ft_printf("mien : %ld\n", LLONG_MAX);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %zhd|\n", "4294967296");
	// j = ft_printf("mien %zhd|\n", "4294967296");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %jhd|\n", "9223372036854775807");
	// j = ft_printf("mien %jhd|\n", "9223372036854775807");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai % 0d|\n", -42);
	// j = ft_printf("mien % 0d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0 d|\n", -42);
	// j = ft_printf("mien %0 d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai % 0d|\n", 42);
	// j = ft_printf("mien % 0d|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %3d|\n", 0);
	// j = ft_printf("mien %3d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %5.d|\n", 0);
	// j = ft_printf("mien @moulitest: %5.d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %5.0d|\n", 0);
	// j = ft_printf("mien @moulitest: %5.0d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %5.d %5.0d|\n", 0, 0);
	// j = ft_printf("mien @moulitest: %5.d %5.0d|\n", 0, 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %-2.d|\n", 0);
	// j = ft_printf("mien @moulitest: %-2.d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0+5d|\n", 42);
	// j = ft_printf("mien %0+5d|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %5.d|\n", 0);
	// j = ft_printf("mien @moulitest: %5.d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0+5d|\n", -42);
	// j = ft_printf("mien %0+5d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %.d|\n", 42);
	// j = ft_printf("mien @moulitest: %.d|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %.d %.0d|\n", 42, 43);
	// j = ft_printf("mien @moulitest: %.d %.0d|\n", 42, 43);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %+d|\n", 0);
	// j = ft_printf("mien %+d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %+i|\n", 0);
	// j = ft_printf("mien %+i|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	// //
	// i = printf("vrai %.10d|\n", 4242);
	// j = ft_printf("mien %.10d|\n", 4242);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai % 10.5d|\n", 4242);
	// j = ft_printf("mien % 10.5d|\n", 4242);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	// //
	// i = printf("vrai %+10.5d|\n", 4242);
	// j = ft_printf("mien %+10.5d|\n", 4242);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-+10.5d|\n", 4242);
	// j = ft_printf("mien %-+10.5d|\n", 4242);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %03.2d|\n", 1);
	// j = ft_printf("mien %03.2d|\n", 1);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %.2d|\n", 1);
	// j = ft_printf("mien %.2d|\n", 1);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai @moulitest: %.10d|\n", -42);
	// j = ft_printf("mien @moulitest: %.10d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %5d|\n", -42);
	// j = ft_printf("mien %5d|\n", -42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai%8.5d|\n", -12);
	// j = ft_printf("mien%8.5d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-7.5d|\n", -12);
	// j = ft_printf("mien %-7.5d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-5d|\n", 42);
	// j = ft_printf("mien %-5d|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %-05d|\n", 42);
	// j = ft_printf("mien %-05d|\n", 42);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %D\n", LLONG_MAX);
	// j = ft_printf("mien : %D\n", LLONG_MAX);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %hhd\n", SHRT_MAX);;
	// j = ft_printf("mien : %hhd\n", SHRT_MAX);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %hhd\n", USHRT_MAX);
	// j = ft_printf("mien : %hhd\n", USHRT_MAX);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0d|\n", 0);
	// j = ft_printf("mien %0d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0i|\n", 0);
	// j = ft_printf("mien %0i|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %.i\n", 0);
	// j = ft_printf("mien %.i\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %.d|\n", 0);
	// j = ft_printf("mien %.d|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %+d|\n", 12);
	// j = printf("vrai %+d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %d|\n", 12);
	// j = printf("vrai %d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %d|\n", -12);
	// j = printf("vrai %d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %04d|\n", -12);
	// j = printf("vrai %04d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %04d|\n", 12);
	// j = printf("vrai %04d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %013d|\n", -12);
	// j = printf("vrai %013d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %013d|\n", 12);
	// j = printf("vrai %013d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %7.5d|\n", 12);
	// j = printf("vrai %7.5d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %5.5d|\n", -12);
	// j = printf("vrai %5.5d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %5.5d|\n", 12);
	// j = printf("vrai %5.5d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %-5.5d|\n", 12);
	// j = printf("vrai %-5.5d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %-5.5d|\n", -12);
	// j = printf("vrai %-5.5d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %-1.5d|\n", -12);
	// j = printf("vrai %-1.5d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %1.5d|\n", 12);
	// j = printf("vrai %1.5d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %-1.5d|\n", 12);
	// j = printf("vrai %-1.5d|\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = ft_printf("mien %1.5d|\n", -12);
	// j = printf("vrai %1.5d|\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	printf("--------- conversion u et U ---------\n\n");

	// i = printf("vrai %-15u|\n", "4294967295");
	// j = ft_printf("mien %-15u|\n", "4294967295");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai % u|\n", "4294967295");
	// j = ft_printf("mien % u|\n", "4294967295");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %+u|\n", "4294967295");
	// j = ft_printf("mien %+u|\n", "4294967295");
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);

	// i = printf("vrai : %lu\n", LLONG_MAX);
	// j = ft_printf("mien : %lu\n", LLONG_MAX);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %U\n", LLONG_MAX);
	// j = ft_printf("mien : %U\n", LLONG_MAX);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %hhu\n", SHRT_MAX);;
	// j = ft_printf("mien : %hhu\n", SHRT_MAX);
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai : %hhu\n", USHRT_MAX);;
	// j = ft_printf("mien : %hhu\n", USHRT_MAX);
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %+u|\n", 11);
	// j = ft_printf("mien %+u|\n", 11);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("vrai %0u|\n", 0);
	// j = ft_printf("mien %0u|\n", 0);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%u\n", 12);
	// j = ft_printf("%u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%-u\n", -12);
	// j = ft_printf("%-u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%u\n", -12);
	// j = ft_printf("%u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%04u\n", -12);
	// j = ft_printf("%04u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%04u\n", 12);
	// j = ft_printf("%04u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%013u\n", -12);
	// j = ft_printf("%013u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%013u\n", 12);
	// j = ft_printf("%013u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%-7.5u\n", -12);
	// j = ft_printf("%-7.5u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%7.5u\n", -12);
	// j = ft_printf("%7.5u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%-7.5u\n", -12);
	// j = ft_printf("%-7.5u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%7.5u\n", 12);
	// j = ft_printf("%7.5u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%5.5u\n", -12);
	// j = ft_printf("%5.5u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%5.5u\n", 12);
	// j = ft_printf("%5.5u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%-5.5u\n", 12);
	// j = ft_printf("%-5.5u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%-5.5u\n", -12);
	// j = ft_printf("%-5.5u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%-1.5u\n", -12);
	// j = ft_printf("%-1.5u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%1.5u\n", 12);
	// j = ft_printf("%1.5u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%-1.5u\n", 12);
	// j = ft_printf("%-1.5u\n", 12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	//
	// i = printf("%1.5u\n", -12);
	// j = ft_printf("%1.5u\n", -12);
	//
	// printf("i = %d\n", i);
	// printf("j = %d\n\n", j);
	return 0;
}
