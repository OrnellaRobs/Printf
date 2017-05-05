/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 15:27:58 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 23:18:18 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "ft_printf.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>

#include 	<stdlib.h>

int		ft_intlen(int n int base)
{
	int i;

	i = 1;
	while ((n = n / 10) >= base)
		i++;
	return (i);
}

int		get_last_number(int n)
{
	if (n < 0)
		return (0 - n);
	return (n);
}

char	*ft_itoa_base(int n, int base)
{
	char	*tab;
	int		total_number;
	int		negatif;
	char	alpha[] = "0123456789ABCDEF";

	total_number = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (nb < 0)
	{
		negatif = 1;
		total_number += 1;
	}
	total_number += ft_intlen(n, base);
	if (!(tab = malloc(sizeof(char) * total_number + 1)))
		return (NULL);
	tab[total_number] = '\0';
	total_number--;
	while (total_number >= negatif)
	{
		tab[total_number] = (char)(alpha[get_last_number(n % base)]);
		n = n / base;
		total_number--;
	}
	if (negatif == 1)
		tab[total_number] = '-';
	return (tab);
}

#include <stdio.h>

int main(void)
{
	printf("%s\n", ft_itoa_base(-2,16));
	printf("%x\n", -2);

}
/*
int		main(void)
{
	// int i;
	int i = 18;
	int j = 0;


	int nb = -1;
	printf("avant%5%apres");
	// printf("%15.12u", -6);
	// printf("%-5d\n", 10);
	// printf("ok%-20i\n", 10);
	// setlocale(LC_ALL,"");
	// i = 0;
	// char *str;
	//
	// str = malloc(sizeof(char) * 8);
	// str = "bonjour";
	// *str = 'a';
	// ft_putstr(str);
	// ft_putstr("\n");
	// while (i < 2)
	// 	i++;
	// str[i] = '\0';
	// ft_putstr(str);
	// char *format = "test = %d et puis%%d ok %p";
	//printf("count = %d\n", count_how_many_str_to_malloc(format));
	// printf("%10.6sok\n", "bonjour");
	// printf("%d\n",printf("%.1s","bonjours"));
	// printf(" %d\n",printf("%S",L"🦄 "));
	// printf(" %d\n",printf("%x",123456789));
	// printf(" %d\n",printf("%X",123456789));
	// printf("%s\n", ft_itoa_base(-20,16));
	return (0);
}
