/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_padd_prec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:39:00 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/26 15:55:18 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		padding_greater_than_precision(t_option *option, char *tab,
	int sign)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->precision < (int)ft_strlen(tab) || option->precision < 1)
		while (++i < option->padding - ((int)ft_strlen(tab)))
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - option->precision - sign)
			result += ft_putchar_int(' ');
	if (option->minuszero != '-')
		result += display_precision(option, tab);
	return (result);
}

int				display_padding_and_precision(char *tab, t_option *option,
	int sign)
{
	int result;
	int	i;

	i = -1;
	result = 0;
	if (option->padding > option->precision)
		result += padding_greater_than_precision(option, tab, sign);
	else if (option->padding <= option->precision && option->minuszero != '-'
		&& option->padding != -1)
		result += display_precision(option, tab);
	return (result);
}
