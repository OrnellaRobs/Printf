/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:46:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/06 10:55:54 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void 	display_space(t_option *option, char *res)
{
	int i;

	i = -1;
	if (option->precision < (int)ft_strlen(res))
		while (++i < option->padding - option->precision)
			ft_putchar(' ');
	else
		while (++i < option->padding - (int)ft_strlen(res))
			ft_putchar(' ');
}

static int		display_precision(t_option *option, char *str)
{
	int i;
	int result;

	result = 0;
	i = -1;
	while (++i < option->precision - (int)ft_strlen(str))
		result += ft_putchar_int('0');
	return (result);
}
/*
static int		display_flag_zero(t_option *option, char *str)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (option->minuszero == '0')
	{
		while (i < option->zero_nb - (int)ft_strlen(str));
		{
			result += ft_putchar_int('0');
			i++;
		}
	}
	return (result);
}
*/
int				ft_conv_string(va_list lst, t_option *option)
{
	char *res;
	int result;
	int i;

	i = -1;
	if (!(res = va_arg(lst, char *)))
		res = "(null)";
	if (option->precision == 0 || (option->precision > 0
	&& (option->padding > option->precision)))
		result = option->padding;
	else if ((option->precision > 0 && option->padding <= option->precision)
	|| (option->precision == -1 && option->padding == -1))
		result = ft_strlen(res);
	// result += display_flag_zero(option, res);
	if (option->minuszero == '-' && option->padding != 01)
		result += display_precision(option, res);
	if (option->padding > option->precision)
		display_space(option, res);
	if (option->precision > 0 && option->precision < (int)ft_strlen(res))
		while (++i < option->precision)
			ft_putchar(res[i]);
	else if (option->precision != 0)
		ft_putstr(res);
	return (result);
}
