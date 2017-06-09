/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_octal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 20:58:53 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/10 01:29:04 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_display_octal(t_option *option, char *tab, int len_hash)
{
	int i;
	int result;

	i = -1;
	result = 0;
	if (option->hash == '#')
		result += ft_putchar_int('0');
	else if (*tab == '0' && option->padding == -1)
		result += ft_putchar_int('0');
	if (option->precision > (int)ft_strlen(tab) + len_hash)
		while (++i < option->precision - (int)ft_strlen(tab) - len_hash)
			result += ft_putchar_int('0');
	if (*tab != '0')
		result += ft_putstr_int(tab);
	return (result);
}

int				ft_display_padding_and_precision_octal(t_option *option,
	int len, int size_hash)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->padding != -1 &&
		option->precision > (len + size_hash))
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	else if (option->padding != -1 &&
	option->precision <= len + size_hash)
		while (++i < option->padding - len - size_hash)
			result += ft_putchar_int(' ');
	return (result);
}

int				ft_convert_octal(t_option *option, char *tab)
{
	int len;
	int result;
	int size_hash;

	result = 0;
	len = (*tab == '0') ? 0 : (int)ft_strlen(tab);
	size_hash = (option->hash == '#') ? 1 : 0;
	if (option->hash != '#')
		size_hash = (*tab == '0') ? 0 : size_hash;
	if (option->minuszero == '-')
		result += ft_display_octal(option, tab, size_hash);
	else if (option->minuszero == '0')
		result += ft_display_flag_zero_str(option, tab);
	result += ft_display_padding_and_precision_octal(option, len, size_hash);
	if (option->minuszero != '-')
		result += ft_display_octal(option, tab, size_hash);
	return (result);
}
