/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_long_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:10:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 16:36:23 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_display_precision_long_string(t_option *option, char *str,
	int count)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < option->precision)
	{
		result += ft_putchar_int(str[i]);
		i++;
	}
	if (option->padding == -1)
		result += count - option->precision;
	return (result);
}

static int		ft_display_padding_and_precision_long_str(t_option *option,
	char *str, int len, int count)
{
	int result;

	result = 0;
	if (option->minuszero != '-' &&
	(option->padding != -1 || option->zero_nb != -1) &&
	(option->padding > len || option->zero_nb > len))
		result += ft_display_padding_long_string(option, len, count);
	if (option->precision == -1)
		result += ft_putstr_int(str);
	else if (option->precision > 0)
		result += ft_display_precision_long_string(option, str, count);
	if (option->minuszero == '-' && option->padding != -1 &&
	option->padding > len)
		result += ft_display_padding_long_string(option, len, count);
	free(str);
	return (result);
}

int				ft_convert_long_string(va_list lst, t_option *option)
{
	char	*str;
	char	*tab;
	int		len;
	int		count;

	count = 0;
	len = 0;
	option->nb = va_arg(lst, unsigned int *);
	tab = (option->nb == 0) ? "(null)" : ft_strnew(0);
	str = ft_get_octet_each_long_char(option, tab, &count, &len);
	return (ft_display_padding_and_precision_long_str(option, str, len, count));
}
