/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_padding_precision_zero.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:51:07 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 11:57:49 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		display_flag_zero(int nb, t_option *option)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (option->minuszero == '0')
	{
		while (i < option->zero_nb - ft_intlen(nb))
		{
			result += ft_putchar_int('0');
			i++;
		}
	}
	return (result);
}

int		precision_greater_than_zero(t_option *option, int nb)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->precision < ft_intlen(nb))
		while (++i < option->padding - ft_intlen(nb))
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	i = -1;
	while (++i < option->precision - ft_intlen(nb))
		result += ft_putchar_int('0');
	return (result);
}

int		display_padding_and_precision(int nb, t_option *option, int diff)
{
	int result;
	int i;
	
	result = 0;
	i = -1;
	if (option->padding > option->precision && option->precision < 1)
		while (++i < option->padding - ft_intlen(nb))
			result += ft_putchar_int(' ');
	else if (option->padding > option->precision && option->precision > 0)
		result += precision_greater_than_zero(option, nb);
	else if (option->padding <= option->precision)
		while (++i < option->precision - ft_intlen(nb))
			result += ft_putchar_int('0');
	return (result);
}
