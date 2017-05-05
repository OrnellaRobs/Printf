/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:46:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/06 00:36:06 by orazafin         ###   ########.fr       */
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
	if (option->padding > option->precision)
		display_space(option, res);
	if (option->precision > 0 && option->precision < (int)ft_strlen(res))
		while (++i < option->precision)
			ft_putchar(res[i]);
	else if (option->precision != 0)
		ft_putstr(res);
	return (result);
}
