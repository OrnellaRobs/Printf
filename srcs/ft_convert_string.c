/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:46:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 22:07:09 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		display_space(t_option *option, char *res)
{
	int	i;
	int	result;

	result = 0;
	i = -1;
	if (option->precision != -1 && option->precision < (int)ft_strlen(res))
	{
		while (++i < option->padding - option->precision)
			if (option->minuszero == '0' && option->zero_nb == -1)
				result += ft_putchar_int('0');
			else
				result += ft_putchar_int(' ');
	}
	else
	{
		while (++i < option->padding - (int)ft_strlen(res))
			if (option->minuszero == '0' && option->zero_nb == -1)
				result += ft_putchar_int('0');
			else
				result += ft_putchar_int(' ');
	}
	return (result);
}

static int		ft_precision_different_from_zero(t_option *option, char *res)
{
	int	i;
	int	result;
	int	flag;

	flag = 0;
	i = -1;
	result = 0;
	if (option->precision > 0 && option->precision < (int)ft_strlen(res))
	{
		while (++i < option->precision)
			result += ft_putchar_int(res[i]);
		flag = 1;
	}
	if (option->precision != 0 || option->minuszero == '-')
	{
		if (flag == 0)
			result += ft_putstr_int(res);
		if (option->minuszero == '-')
			result += display_space(option, res);
	}
	return (result);
}

int				ft_convert_string(va_list lst, t_option *option)
{
	char	*res;
	int		result;

	if (option->modifier == 'l')
		return (ft_convert_long_string(lst, option));
	result = 0;
	if (!(res = va_arg(lst, char *)))
		res = "(null)";
	if (option->zero_nb != -1)
		result += ft_display_flag_zero_str(option, res);
	else if (option->minuszero != '-')
		result += display_space(option, res);
	result += ft_precision_different_from_zero(option, res);
	return (result);
}
