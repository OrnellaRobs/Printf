/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:46:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/26 18:30:55 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** FLAG 0 à gérer (undefined behavior)
*/

static int	display_space(t_option *option, char *res)
{
	int i;
	int result;

	result = 0;
	i = -1;
	if (option->precision != -1 && option->precision < (int)ft_strlen(res))
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - (int)ft_strlen(res))
			result += ft_putchar_int(' ');
	return (result);
}

int			ft_conv_string(va_list lst, t_option *option)
{
	char	*res;
	int		result;
	int		i;
	int 	flag;

	flag = 0;
	result = 0;
	i = -1;
	if (!(res = va_arg(lst, char *)))
		res = "(null)";
	if (option->minuszero == '0')
		result += ft_display_flag_zero_str(option, res);
	else if (option->minuszero != '-')
		if (option->padding > option->precision)
			result += display_space(option, res);
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
