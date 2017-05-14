/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 20:58:53 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/13 18:56:07 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_display_octal(t_option *option, char *tab, int len_hash)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->hash == '#')
		result += ft_putchar_int('0');
	if (option->precision > (int)ft_strlen(tab) + len_hash)
		while (++i < option->precision - (int)ft_strlen(tab) - len_hash)
			result += ft_putchar_int('0');
	result += ft_putstr_int(tab);
	return (result);
}

int		ft_convert_octal(t_option *option, char *tab)
{
	int result;
	int len;
	int i;

	i = -1;
	result = 0;
	len = (option->hash == '#') ? 1 : 0;
	if (option->minuszero == '-')
		result += ft_display_octal(option, tab, len);
	if (option->padding != -1 && option->precision > ((int)ft_strlen(tab) + len))
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	else if (option->padding != -1 && option->precision <= (int)ft_strlen(tab) + len)
		while (++i < option->padding - (int)ft_strlen(tab) - len)
			result += ft_putchar_int(' ');
	if (option->minuszero != '-')
		result += ft_display_octal(option, tab, len);
	return (result);
}
