/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:50:19 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/13 00:51:44 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_display_pointer(t_option *option, char *tab)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->precision > (int)ft_strlen(tab))
		while (++i < option->precision - (int)ft_strlen(tab))
			result += ft_putchar_int('0');
	result += ft_putstr_int(tab);
	return (result);
}

int		ft_convert_pointer(va_list lst, t_option *option)
{
	int				result;
	int				i;
	char			*tab;
	unsigned int	nb;

	i = -1;
	result = 0;
	nb = va_arg(lst, int);
	tab = ft_itoa_base_printf(nb, 16, 0);
	tab = ft_strjoin("0x", tab);
	if (option->minuszero == '-')
		result += ft_display_pointer(option, tab);
	if (option->padding != -1 && option->precision > (int)ft_strlen(tab))
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	else if (option->padding != -1 && option->precision <= (int)ft_strlen(tab))
		while (++i < option->padding - (int)ft_strlen(tab))
			result += ft_putchar_int(' ');
	if (option->minuszero != '-')
		result += ft_display_pointer(option, tab);
	return (result);
}
