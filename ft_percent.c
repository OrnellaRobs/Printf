/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 22:01:20 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/02 22:01:57 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent(t_option *option)
{
	int result;

	result = 0;
	if (option->padding != -1)
	{
		if (option->minuszero == '-')
			result += ft_putchar_int('%');
		while (++i < option->padding - 1)
			result += ft_putchar_int(' ');
		if (option->minuszero != '-')
			result += ft_putchar_int('%');
	}
	else
		result += ft_putchar_int('%');
	return (result);
}
