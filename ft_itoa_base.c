/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:34:52 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/21 17:28:21 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include 	<stdlib.h>

int		ft_count_number(int n, int base)
{
	int count;

	count = 1;
	count = (n < 0) ? count + 1 : count;
	printf("n = %d\n",n);
	while (n % base != 0)
	{
		printf("n = %d\n",n);
		n = n / base;
		count++;
	}
	return (count);
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

	negatif = 0;
	if (base < 2 || base > 16)
		return (NULL);
	if (n < 0)
		negatif = 1;
	total_number = ft_count_number(n, base);
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
