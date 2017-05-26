/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:29:33 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/26 18:27:58 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_display_hexa(t_option *option, char *tab, int upper_case,
int len)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->hash == '#' && *tab != '0')
		result += (upper_case == 0) ? ft_putstr_int("0x") : ft_putstr_int("0X");
	if (option->precision > len)
		while (++i < option->precision - len)
			result += ft_putchar_int('0');
	if (*tab != '0' || option->zero_nb == 0 || (*tab == '0' && option->padding == -1 &&
	option->precision == -1))
		result += ft_putstr_int(tab);
	return (result);
}

int				ft_convert_hexa(t_option *option, char *tab, char *format)
{
	int		result;
	int		i;
	int		size_hash;
	int		upper_case;
	int 	len;

	i = -1;
	result = 0;
	len = (*tab == '0') ? 0 : (int)ft_strlen(tab);
	upper_case = (*format == 'X') ? 1 : 0;
	size_hash = (option->hash == '#') ? 2 : 0;
	size_hash = (*tab == '0') ? 0 : size_hash;
	if (option->minuszero == '-')
		result += ft_display_hexa(option, tab, upper_case, len);
	else if (option->minuszero == '0')
		result += ft_display_flag_zero_str(option, tab);
	if (option->padding != -1 && option->precision > len)
		while (++i < option->padding - (option->precision + size_hash))
			result += ft_putchar_int(' ');
	else if (option->padding != -1 && option->precision <= len)
		while (++i < option->padding - len + size_hash)
			result += ft_putchar_int(' ');
	if (option->minuszero != '-')
		result += ft_display_hexa(option, tab, upper_case, len);
	return (result);
}
