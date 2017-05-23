/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base_unsigned.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 19:28:49 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/23 17:54:47 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_size_for_malloc(unsigned long long value, int base)
{
	int total_number;

	total_number = 0;
	while (value > 0)
	{
		total_number++;
		value = value / base;
	}
	return (total_number);
}

char			*ft_lltoa_base_unsigned(unsigned long long value, int base,
	int upper_case, int sign)
{
	char	*tab;
	int		total_number;
	char	*alpha;

	alpha = (upper_case < 1) ? "0123456789abcdef" : "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	else if (base == 10 && sign == 0)
		return (ft_itoa((int)value));
	if (value == 0)
		return ("0");
	total_number = ft_get_size_for_malloc(value, base);
	if (!(tab = malloc(sizeof(char) * (total_number + 1))))
		return (NULL);
	tab[total_number] = '\0';
	total_number--;
	while ((value = value / 10) > 0)
	{
		if (base == 16 || base == 8)
			tab[total_number] = alpha[value % base];
		else
			tab[total_number] = ((value % 10) + '0');
		total_number--;
	}
	return (tab);
}
