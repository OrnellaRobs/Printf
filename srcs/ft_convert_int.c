/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:15:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/31 00:12:27 by orazafin         ###   ########.fr       */
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
	if (*tab == '0' && option->padding == -1)
		result += ft_putstr_int(tab);
	return (result);
}

static int		display_flag_zero(char *tab, t_option *option, int un_sign)
{
	int result;
	int i;
	int plus;

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

int				display_precision(t_option *option, char *tab, int un_sign)
{
	int i;
	int result;
	int negatif;

	negatif = (*tab == '-') ? 1 : 0;
	result = 0;
	i = -1;
	if (*tab != '-' && un_sign == 0 && option->minuszero != '0')
		result += display_flag_plusspace(option, tab);
	else if (*tab == '-' && option->padding != -1)
		result += ft_putchar_int('-');
	while (++i < option->precision - (int)ft_strlen(tab) + negatif)
		result += ft_putchar_int('0');
	return (result);
}

int				ft_conv_int(t_option *option, char *tab)
{
	int result;
	int sign;

 // printf("zero_nb = %d | padding = %d | precision = %d | minuszero = {%c} | pluspace = {%c}\n", option->zero_nb, option->padding, option->precision,
 // option->minuszero, option->pluspace);
	sign = (*tab == '-') ? 1 : 0;
	result = 0;
	if (*tab == '-' && option->padding == -1)
		result += ft_putchar_int('-');
	if (option->precision == -1)
		result += display_flag_zero(tab, option, 0);
	if (option->minuszero == '-')
	{
		result += display_precision(option, tab, 0);
		if (*tab == '-')
			tab++;
		result += ft_putstr_int(tab);
	}
	result += display_padding_and_precision(tab, option, sign, 0);
	if (*tab == '-' && option->minuszero != '-')
	{
		tab++;
		if (*tab != '0')
			result += ft_putstr_int(tab);
	}
	else if ((option->minuszero != '-' && *tab != '0') || ((*tab == '0'
	&& option->padding != -1 && option->precision != 0) && (option->minuszero != '-')))
		result += ft_putstr_int(tab);
	return (result);
}

int				ft_conv_unsigned_int(t_option *option, char *tab)
{
	int result;
	int sign;
	int un_sign;

	un_sign = 1;
	sign = 0;
	result = 0;
	result += display_flag_zero(tab, option, un_sign);
	if (option->minuszero == '-' && option->padding != -1)
	{
		// sign = 1;
		result += display_precision(option, tab, un_sign);
		result += ft_putstr_int(tab);
	}
	result += display_padding_and_precision(tab, option, sign, un_sign);
	if (option->minuszero != '-')
		result += ft_putstr_int(tab);
	return (result);
}
