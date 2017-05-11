/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 11:25:03 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/11 15:30:31 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_get_size_for_malloc(unsigned int value, int base)
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

char			*ft_itoa_base_printf(unsigned int value, int base,
	int upper_case)
{
	char	*tab;
	int		total_number;
	char	*alpha;

	alpha = (upper_case < 1) ? "0123456789abcdef" : "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	else if (base == 10)
		return (ft_itoa((int)value));
	if (value == 0)
		return ("0");
	total_number = ft_get_size_for_malloc(value, base);
	if (!(tab = malloc(sizeof(char) * (total_number + 1))))
		return (NULL);
	tab[total_number] = '\0';
	total_number--;
	while (value > 0)
	{
		tab[total_number] = alpha[value % base];
		total_number--;
		value = value / base;
	}
	return (tab);
}
