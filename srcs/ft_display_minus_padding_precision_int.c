/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_padd_prec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:39:00 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 19:53:47 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				ft_is_flag_minus_int(t_option *option, char *tab, int unsign)
{
	int result;

	result = 0;
	result += display_precision_int(option, tab, unsign);
	if (*tab == '-' && unsign == 0)
		tab++;
	result += ft_putstr_int(tab);
	return (result);
}

static int		padding_greater_than_precision(t_option *option, char *tab,
	int sign, int un_sign)
{
	int i;
	int result;

	i = -1;
	result = 0;
	if ((sign == 1 && option->minuszero != '-' && option->precision == -1) ||
	(option->precision < (int)ft_strlen(tab) && option->precision != -1 &&
	option->minuszero != '0'))
		sign = 0;
	else if (option->pluspace == '+' && un_sign == 0)
		sign = 1;
	if (option->precision < (int)ft_strlen(tab) && option->precision != 0)
		while (++i < option->padding - (int)ft_strlen(tab) - sign)
			result += ft_putchar_int(' ');
	else
	{
		while (++i < option->padding - option->precision - sign)
			result += ft_putchar_int(' ');
	}
	if (option->minuszero != '-')
		result += display_precision_int(option, tab, un_sign);
	return (result);
}

int				display_padding_and_precision_int(char *tab, t_option *option,
	int sign, int un_sign)
{
	int	i;
	int result;

	i = -1;
	result = 0;
	if (option->padding > option->precision)
		result += padding_greater_than_precision(option, tab, sign, un_sign);
	else if (option->padding <= option->precision && option->minuszero != '-')
		result += display_precision_int(option, tab, un_sign);
	return (result);
}
