/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_padd_prec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:39:00 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/27 17:53:30 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		padding_greater_than_precision(t_option *option, char *tab,
	int sign, int un_sign)
{
	int result;
	int i;

	i = -1;
	result = 0;

	if (sign == 1 && option->minuszero != '-' && option->precision == -1)
		sign = 0;
	else if (option->pluspace == '+' && un_sign == 0)
		sign = 1;
	if ((option->precision < (int)ft_strlen(tab) && option->precision != 0) || option->precision == -1)
	{
		while (++i < option->padding - (int)ft_strlen(tab) - sign)
			result += ft_putchar_int(' ');
	}
	else
	{
		while (++i < option->padding - option->precision - sign)
			result += ft_putchar_int(' ');
	}
	if (option->minuszero != '-')
		result += display_precision(option, tab, un_sign);
	return (result);
}

int				display_padding_and_precision(char *tab, t_option *option,
	int sign, int un_sign)
{
	int result;
	int	i;

	i = -1;
	result = 0;
	if (option->padding > option->precision)
		result += padding_greater_than_precision(option, tab, sign, un_sign);
	else if (option->padding <= option->precision && option->minuszero != '-')
		result += display_precision(option, tab, un_sign);
	return (result);
}
