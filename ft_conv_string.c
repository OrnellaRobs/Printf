/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:46:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/11 15:38:38 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* FLAG 0 à gérer !!!*/

#include "ft_printf.h"

static int 	display_space(t_option *option, char *res)
{
	int i;
	int result;

	result = 0;
	i = -1;
	if (option->precision < (int)ft_strlen(res))
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - (int)ft_strlen(res))
			result += ft_putchar_int(' ');
	return (result);
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

int				ft_conv_string(va_list lst, t_option *option)
{
	char *res;
	int result;
	int i;

	result = 0;
	i = -1;
	if (!(res = va_arg(lst, char *)))
		res = "(null)";
	if (option->minuszero != '-')
		if (option->padding > option->precision)
			result += display_space(option, res);
	if (option->precision > 0 && option->precision < (int)ft_strlen(res))
		while (++i < option->precision)
			result += ft_putchar_int(res[i]);
	else if (option->precision != 0 || option->minuszero == '-')
		result += ft_putstr_int(res);
	return (result);
}
