/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 13:46:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/25 18:47:01 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*str_after_precision(char *str, t_list *option)
{
	int i;

	i = 0;
	while (i < option->precision)
		i++;
	str[i] = *str;
	ft_strclr(str);
	return (str);
}

static void 	display_space(t_list *option)
{
	int space;

	space = 0;
	while (space < option->padding - ft_strlen(res))
	{
		ft_putchar(' ');
		space++;
	}
}

int				ft_s(va_list lst, t_list *option)
{
	char	*res;
	int		result;
	int		flag;

	flag = 0;

	res = va_arg(lst, char *);
	if (option->precision == 0)
		return (0);
	if (option->precision > 0 && option->precision < ft_strlen(res))
		res = str_after_precision(res, option);
	if (option->precision > 0 && option->padding > option->precision)
	{
		result = option->padding;
		flag = 1;
	}
	else
		result = ft_strlen(res);
	if (flag == 1)
		display_space(option);
	ft_putstr(res);
	return (result);
}
