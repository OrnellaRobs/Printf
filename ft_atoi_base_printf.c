/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_printf.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/22 18:59:56 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/22 19:00:09 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi_base_printf(const char *str, int base)
{
	int i;
	int res;
	int negatif;

	i = 0;
	res = 0;
	negatif = 1;
	while (ft_is_space(str) == 1)
		str++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			negatif = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * base + str[i] - '0';
		i++;
	}
	return (res * negatif);
}
