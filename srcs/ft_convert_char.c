/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:34:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 18:41:11 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		display_flag_zero(t_option *option)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < option->zero_nb - 1)
	{
		result += ft_putchar_int('0');
		i++;
	}
	return (result);
}

static int		display_padding(t_option *option)
{
	int i;
	int result;

	i = 1;
	result = 0;
	while (i < option->padding)
	{
		result += ft_putchar_int(' ');
		i++;
	}
	return (result);
}

static int		display_padding_other_char(t_option *option)
{
	int i;
	int result;

	i = 1;
	result = 0;
	while (i < option->padding)
	{
		if (option->minuszero == '0' && option->zero_nb == -1)
			result += ft_putchar_int('0');
		else
			result += ft_putchar_int(' ');
		i++;
	}
	return (result);
}

int				ft_other_char(va_list get, t_option *option)
{
	int		result;
	char	c;

	result = 0;
	if (!(c = (char)va_arg(get, unsigned int)))
	{
		if (option->padding != -1 && option->precision == 0)
		{
			option->zero_nb = option->padding;
			option->padding = -1;
		}
	}
	if (option->minuszero != '-' && option->padding != -1 && c != '0')
		result += display_padding_other_char(option);
	if (option->zero_nb != 0)
		result += display_flag_zero(option);
	result += ft_putchar_int(c);
	if (option->minuszero == '-' && option->padding != -1)
		result += display_padding_other_char(option);
	va_end(get);
	return (result);
}

int				ft_convert_char(va_list lst, t_option *option)
{
	int		result;
	char	c;

	result = 0;
	if (option->modifier == 'l')
		return (ft_convert_long_char(lst, option));
	if (!(c = (char)va_arg(lst, unsigned int)))
	{
		if (option->padding != -1 && option->precision == 0)
		{
			option->zero_nb = option->padding;
			option->padding = -1;
		}
	}
	if (option->minuszero != '-' && option->padding != -1 && c != '0')
		result += display_padding(option);
	if (option->zero_nb != 0)
		result += display_flag_zero(option);
	result += ft_putchar_int(c);
	if (option->minuszero == '-' && option->padding != -1)
		result += display_padding(option);
	return (result);
}
