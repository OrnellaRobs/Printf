/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_padding_long_string.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 01:07:31 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/10 22:27:33 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_is_precision_equal_minus_one(t_option *option, int len)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->padding != -1)
		while (++i < option->padding - len)
			result += ft_putchar_int(' ');
	else if (option->zero_nb != -1)
		while (++i < option->zero_nb - len)
			result += ft_putchar_int('0');
	return (result);
}

static int	ft_is_precision_equal_zero(t_option *option)
{
	int result;
	int i;

	i = -1;
	result = 0;
	while (++i < option->padding)
	{
		if (option->minuszero != '0')
			result += ft_putchar_int(' ');
		else if (option->minuszero == '0')
			result += ft_putchar_int('0');
	}
	return (result);
}

int			ft_display_padding_long_string(t_option *option, int len, int count)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->precision == -1)
		result += ft_is_precision_equal_minus_one(option, len);
	else if (option->precision == 0)
		result += ft_is_precision_equal_zero(option);
	else if (option->precision > 0)
	{
		while (++i < option->padding - count)
		{
			if (option->minuszero != '0')
				result += ft_putchar_int(' ');
			else if (option->minuszero == '0')
				result += ft_putchar_int('0');
		}
		if (option->minuszero != '0')
			result += count - option->precision;
	}
	return (result);
}
