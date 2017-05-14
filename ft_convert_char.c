/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 18:34:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/13 19:58:21 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		display_padding(t_option *option)
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

int		ft_conv_char(va_list lst, t_option *option)
{
	int		result;
	char	c;

	result = 0;
	c = (char)va_arg(lst, unsigned int);
	if (option->minuszero != '-' && option->padding != -1)
		result += display_padding(option);
	result += ft_putchar_int(c);
	if (option->padding != -1)
		result += display_padding(option);
	return (result);
}
