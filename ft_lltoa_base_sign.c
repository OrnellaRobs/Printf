/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:29:01 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/23 14:28:56 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_size_for_malloc(long long value, int base)
{
	int total_number;
	total_number = 0;
	while (value != 0)
	{
		total_number++;
		value = value / base;
	}
	return (total_number);
}

int		ft_intlen_long(long long n)
{
	int i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}

static int		get_last_number(int number)
{
	if (number < 0)
		return (0 - number);
	return (number);
}

char			*ft_lltoa_base_sign(long long value, int base, int sign)
{
	char	*tab;
	int		total_number;
	int		negatif;

	if (base < 2 || base > 16)
		return (NULL);
	else if (base == 10 && sign == 0)
		return (ft_itoa((int)value));
	if (value == 0)
		return ("0");
	negatif = (value < 0) ? 1 : 0;
	total_number = ft_get_size_for_malloc(value, base) + negatif;
	if (!(tab = malloc(sizeof(char) * (total_number + 1))))
		return (NULL);
	tab[total_number--] = '\0';
	while (total_number >= negatif)
	{
		tab[total_number] = (char)(get_last_number(value % 10) + '0');
		total_number--;
		value = value / base;
	}
	if (negatif == 1)
		tab[total_number] = '-';
	return (tab);
}
