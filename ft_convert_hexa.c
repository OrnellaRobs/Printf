/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/12 19:29:33 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/12 22:13:54 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_display_hexa(t_option *option, char *tab, int upper_case)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->hash == '#')
		result += (upper_case == 0) ? ft_putstr_int("0x") : ft_putstr_int("0X");
	if (option->precision > (int)ft_strlen(tab))
		while (++i < option->precision - (int)ft_strlen(tab))
			result += ft_putchar_int('0');
	result += ft_putstr_int(tab);
	return (result);
}

int		ft_convert_hexa(t_option *option, unsigned int nb, char *format)
{
	int		upper_case;
	int		result;
	int		i;
	int		size_hash;
	char	*tab;

	i = -1;
	result = 0;
	upper_case = (*format == 'x') ? 0 : 1;
	tab = ft_itoa_base_printf(nb, 16, upper_case);
	size_hash = (option->hash == '#') ? 2 : 0;
	if (option->minuszero == '-')
		result += ft_display_hexa(option, tab, upper_case);
	if (option->padding != -1 && option->precision > (int)ft_strlen(tab))
		while (++i < option->padding - (option->precision + size_hash))
			result += ft_putchar_int(' ');
	else if (option->padding != -1 && option->precision <= (int)ft_strlen(tab))
		while (++i < option->padding - ((int)ft_strlen(tab) + size_hash))
			result += ft_putchar_int(' ');
	if (option->minuszero != '-')
		result += ft_display_hexa(option, tab, upper_case);
	printf("\nresult = %d\n", result);
	return (result);
}
