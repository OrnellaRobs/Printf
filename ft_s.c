/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:46:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/02 14:01:01 by orazafin         ###   ########.fr       */
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

	i = -1;
	if (!(res = va_arg(lst, char *)))
		res = "(null)";
	if (option->precision == 0 || (option->precision > 0
	&& (option->padding > option->precision)))
		result = option->padding;
	else if ((option->precision > 0 && option->padding <= option->precision)
	|| (option->precision == -1 && option->padding == -1))
		result = ft_strlen(res);
	if (option->padding > option->precision && option->precision > -1)
		while (++i < option->padding - option->precision)
			ft_putchar(' ');
	i = -1;
	if (option->precision > 0 && option->precision < ft_strlen(res))
		while (++i < option->precision)
			ft_putchar(res[i]);
	else if (option->precision != 0)
		ft_putstr(res);
	printf("\nVRAI PRINTF = format = %5.1sok", "bonjour");
	printf("result = %d\n", result);
	return (result);
}
