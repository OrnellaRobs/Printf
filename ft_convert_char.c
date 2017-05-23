/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:34:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/23 17:34:32 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		display_flag_zero(t_option *option)
{
	int result;
	int i;

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

int				ft_conv_char(va_list lst, t_option *option)
{
	int		result;
	char	c;

	result = 0;
	c = (char)va_arg(lst, unsigned int);
	if (option->minuszero != '-' && option->padding != -1)
		result += display_padding(option);
	if (option->zero_nb != 0)
		result += display_flag_zero(option);
	result += ft_putchar_int(c);
	if (option->minuszero == '-' && option->padding != -1)
		result += display_padding(option);
	return (result);
}
