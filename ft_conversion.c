/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:46:22 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/02 18:45:31 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_percent(t_option *option)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->padding != -1)
	{
		if (option->minuszero == '-')
			result += ft_putchar_int('%');
		while (++i < option->padding - 1)
			result += ft_putchar_int(' ');
		if (option->minuszero != '-')
			result += ft_putchar_int('%');
	}
	else
		result += ft_putchar_int('%');
	return (result);
}

int		conversion(char *format, t_option *option, va_list lst)
{
	int	i;
	int	(*convert[6])(va_list, t_option *);

	i = 0;
	convert[0] = &ft_s;
	// convert[1] = &ft_S;
	// convert[2] = &ft_p;
	convert[3] = &ft_d;
	// convert[4] = &ft_D;
	// convert[5] = &ft_i;
	while (STR_CONVERSION[i])
	{
		if (i < 6 && STR_CONVERSION[i] == *format)
			return (convert[i](lst, option));
		else if (*format == '%')
			return (ft_percent(option));
		else if (i >= 6 && STR_CONVERSION[i] == *format)
			return (1);
		i++;
	}
	return (0);
}
