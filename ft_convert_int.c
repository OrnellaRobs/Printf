/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:15:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/24 20:38:21 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		display_flag_zero(char *tab, t_option *option)
{
	int result;
	int i;
	int negatif;

	i = 0;
	result = 0;
	negatif = (*tab == '-') ? 1 : 0;
	if (option->minuszero == '0')
	{
		while (i < option->zero_nb - ((int)ft_strlen(tab)))
		{
			result += ft_putchar_int('0');
			i++;
		}
	}
	return (result);
}

static int		display_flag_plusspace(t_option *option)
{
	int result;

	result = 0;
	if (option->pluspace == '+')
		result += ft_putchar_int('+');
	else if (option->pluspace == 's')
		result += ft_putchar_int(' ');
	return (result);
}

int				display_precision(t_option *option, char *tab)
{
	int i;
	int result;
	int negatif;

	negatif = (*tab == '-') ? 1 : 0;
	result = 0;
	i = -1;
	if (*tab == '-')
		result += ft_putchar_int('-');
	while (++i < option->precision - (int)ft_strlen(tab) + negatif)
		result += ft_putchar_int('0');
	return (result);
}

int				ft_conv_int(t_option *option, char *tab)
{
	int result;
	int sign;

	sign = (*tab == '-') ? 1 : 0;
	result = display_flag_plusspace(option);
	if (*tab == '-' && option->padding == -1)
		result += ft_putchar_int('-');
	result += display_flag_zero(tab, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		sign = 1;
		result += display_precision(option, tab);
		if (*tab == '-')
			tab++;
		result += ft_putstr_int(tab);
	}
	result += display_padding_and_precision(tab, option, sign);
	if (*tab == '-' && option->minuszero != '-')
	{
		tab++;
		result += ft_putstr_int(tab);
	}
	else if (option->minuszero != '-')
		result += ft_putstr_int(tab);
	return (result);
}

int				ft_conv_unsigned_int(t_option *option, char *tab)
{
	int result;
	int sign;

	sign = 0;
	result = 0;
	result += display_flag_zero(tab, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		sign = 1;
		result += display_precision(option, tab);
		result += ft_putstr_int(tab);
	}
	result += display_padding_and_precision(tab, option, sign);
	if (sign == 0)
		result += ft_putstr_int(tab);
	return (result);
}
