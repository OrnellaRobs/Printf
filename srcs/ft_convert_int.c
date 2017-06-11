/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:15:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 19:53:26 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		display_flag_plusspace(t_option *option, char *tab)
{
	int result;

	result = 0;
	if (option->pluspace == '+' && *tab != '-')
		result += ft_putchar_int('+');
	else if (option->pluspace == 's' && option->padding == -1
	&& *tab != '-')
		result += ft_putchar_int(' ');
	else if (option->pluspace == 's' && *tab != '-' && option->minuszero == '-')
	{
		result += ft_putchar_int(' ');
		option->padding = option->padding - 1;
	}
	else if (option->pluspace == 's' && *tab != '-' &&
	option->padding < option->precision)
		result += ft_putchar_int(' ');
	if (*tab == '0' && option->padding == -1)
		result += ft_putstr_int(tab);
	return (result);
}

static int		display_flag_zero(char *tab, t_option *option, int un_sign)
{
	int i;
	int plus;
	int result;

	i = 0;
	result = 0;
	plus = (option->pluspace != '\0' && un_sign == 0) ? 1 : 0;
	plus = (*tab == '-') ? 0 : plus;
	if (option->minuszero == '0')
	{
		result += display_flag_plusspace(option, tab);
		while (i < option->zero_nb - ((int)ft_strlen(tab)) - plus)
		{
			result += ft_putchar_int('0');
			i++;
		}
	}
	return (result);
}

int				display_precision_int(t_option *option, char *tab, int un_sign)
{
	int i;
	int result;
	int negatif;

	i = -1;
	result = 0;
	negatif = (*tab == '-') ? 1 : 0;
	if (*tab != '-' && un_sign == 0 && option->minuszero != '0')
		result += display_flag_plusspace(option, tab);
	else if (*tab == '-' && option->padding != -1)
		result += ft_putchar_int('-');
	while (++i < option->precision - (int)ft_strlen(tab) + negatif)
		result += ft_putchar_int('0');
	return (result);
}

int				ft_convert_int(t_option *option, char *tab)
{
	int sign;
	int result;

	sign = (*tab == '-') ? 1 : 0;
	result = 0;
	if (*tab == '-' && option->padding == -1)
		result += ft_putchar_int('-');
	if (option->precision == -1)
		result += display_flag_zero(tab, option, 0);
	if (option->minuszero == '-')
		result += ft_is_flag_minus_int(option, tab, 0);
	if (*tab == '-' && option->minuszero == '-')
		tab++;
	result += display_padding_and_precision_int(tab, option, sign, 0);
	if (*tab == '-' && option->minuszero != '-')
	{
		tab++;
		if (*tab != '0')
			result += ft_putstr_int(tab);
	}
	else if ((option->minuszero != '-' && *tab != '0') || ((*tab == '0'
	&& option->padding != -1 && option->precision != 0) &&
	(option->minuszero != '-')))
		result += ft_putstr_int(tab);
	return (result);
}

int				ft_convert_unsigned_int(t_option *option, char *tab)
{
	int sign;
	int result;
	int un_sign;

	sign = 0;
	result = 0;
	un_sign = 1;
	result += display_flag_zero(tab, option, un_sign);
	if (option->minuszero == '-' && option->padding != -1)
		result += ft_is_flag_minus_int(option, tab, un_sign);
	result += display_padding_and_precision_int(tab, option, sign, un_sign);
	if (option->minuszero != '-')
		result += ft_putstr_int(tab);
	return (result);
}
