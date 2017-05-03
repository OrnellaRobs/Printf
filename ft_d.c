/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:23:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/03 16:01:20 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		display_flag(int nb, t_option *option)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (option->pluspace == '+')
		result += ft_putchar_int('+');
	else if (option->pluspace == 's')
		result += ft_putchar_int(' ');
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

static int		precision_greater_than_zero(t_option *option, int nb)
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

static int		display_padding_and_precision(int nb, t_option *option)
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

int				ft_convert_d(va_list lst, t_option *option)
{
	int nb;
	int result;
	int state;

	state = 0;
	result = 0;
	nb = va_arg(lst, int);
	result += display_flag(nb, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		ft_putnbr(nb);
		state = 1;
	}
	result += display_padding_and_precision(nb, option);
	result += ft_intlen(nb);
	if (state == 0)
		ft_putnbr(nb);
	return (result);
}
