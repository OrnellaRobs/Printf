/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:15:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/14 03:10:53 by orazafin         ###   ########.fr       */
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

static int		display_precision(t_option *option, char *tab)
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

static int		padding_greater_than_precision(t_option *option, char *tab,
	int state)
{
	int result;
	int i;
	int negatif;

	negatif = (*tab == '-') ? 1 : 0;
	i = -1;
	result = 0;
	if (option->precision < (int)ft_strlen(tab) || option->precision < 1)
		while (++i < option->padding - ((int)ft_strlen(tab)))
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - option->precision - negatif)
			result += ft_putchar_int(' ');
	if (state == 0)
		result += display_precision(option, tab);
	return (result);
}

static int		display_padding_and_precision(char *tab, t_option *option,
	int state)
{
	int result;
	int	i;

	i = -1;
	result = 0;
	if (option->padding > option->precision)
		result += padding_greater_than_precision(option, tab, state);
	else if (option->padding <= option->precision && state == 0
		&& option->padding != -1)
		result += display_precision(option, tab);
	return (result);
}

int				ft_conv_int(t_option *option, char *tab)
{
	int result;
	int state;

	state = 0;
	result = 0;
	result += display_flag_plusspace(option);
	if (*tab == '-' && option->padding == -1)
		result += ft_putchar_int('-');
	result += display_flag_zero(tab, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		state = 1;
		result += display_precision(option, tab);
		if (*tab == '-')
			tab++;
		ft_putstr_int(tab);
	}
	result += display_padding_and_precision(tab, option, state);
	if (*tab == '-' && state == 0)
	{
		tab++;
		result += ft_putstr_int(tab);
	}
	else if (state == 0)
		result += ft_putstr_int(tab);
	return (result);
}

int				ft_conv_unsigned_int(t_option *option, char *tab)
{
	int result;
	int state;

	state = 0;
	result = 0;
	result += display_flag_zero(tab, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		state = 1;
		result += display_precision(option, tab);
		ft_putstr_int(tab);
	}
	result += display_padding_and_precision(tab, option, state);
	if (state == 0)
		result += ft_putstr_int(tab);
	return (result);
}
