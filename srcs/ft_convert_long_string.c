/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_long_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:10:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 14:01:49 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_display_precision_long_string(t_option *option, char *str, int count)
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

int		ft_display_padding_and_precision_long_str(t_option *option, char *str,
	int len, int count)
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
	return (result);
}

int		ft_convert_long_string(va_list lst, t_option *option)
{
	unsigned int	*nb;
	int				i;
	char 			*tab;
	char			*str;
	char 			*tmp;
	int				result;
	int				len;
	int				count;
	int				len_octet;
	int 			state;
	char			*octet;

	state = 0;
	len_octet = 0;
	count = 0;
	i = 0;
	result = 0;
	tab = ft_strnew(0);
	nb = va_arg(lst, unsigned int *);
	if (nb == 0)
		tab = "(null)";
	while (nb != 0 && nb[i])
	{
		octet = ft_convert_binairy_to_decimal(nb[i], &count, &len_octet);
		if (option->precision == -1 || (count <= option->precision && option->precision > 0))
		{
			tmp = tab;
			tab = ft_strjoin(tmp, octet);
			free(tmp);
			len_octet = 0;
			state = 1;
		}
		else
		{
			count -= len_octet;
			free(octet);
			break ;
		}
		if (option->precision != -1 &&
		(int)ft_strlen(tab) <= option->precision)
			str = ft_strdup(tab);
		i++;
		free(octet);
	}
	if (option->padding != -1 && option->precision != -1 &&
	(int)ft_strlen(tab) < option->precision)
		len = option->precision;
	else
	{
		len = ft_strlen(tab);
		str = ft_strdup(tab);
	}
	result += ft_display_padding_and_precision_long_str(option, str, len, count);
	if (state == 1)
		free(tab);
	free(str);
	return (result);
}
