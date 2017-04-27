/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:46:22 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/27 19:55:28 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	display_space(t_option *option, char *res)
{
	int space;

	space = 0;
	while (space < option->padding - ft_strlen(res))
	{
		ft_putchar(' ');
		space++;
	}
}

int		ft_s(va_list lst, t_option *option)
{
	char *res;
	int result;
	int i;
	int flag;

	i = -1;
	if (!(res = va_arg(lst, char *)))
		res = "(null)";
	printf("RES = %s\n", res);
	if (option->precision == 0)
		return (0);
	else if (option->precision > 0 && option->padding > option->precision)
		result = option->padding;
	else if (option->precision > 0 && option->padding <= option->precision)
		result = ft_strlen(res);
	if (option->padding > option->precision)
		while (++i < option->padding - option->precision)
			ft_putchar(' ');
	i = -1;
	if (option->precision > 0 && option->precision < ft_strlen(res))
		while (++i < option->precision)
			ft_putchar(res[i]);
	else
		ft_putstr(res);
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
	// convert[3] = &ft_d;
	// convert[4] = &ft_D;
	// convert[5] = &ft_i;
	while (STR_CONVERSION[i])
	{
		if (i < 6 && STR_CONVERSION[i] == *format)
			return (convert[i](lst, option));
		else if (i >= 6 && STR_CONVERSION[i] == *format)
			return (1);
		i++;
	}
	return (0);
}
