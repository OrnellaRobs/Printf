/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int_padd_prec.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:39:00 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/23 17:43:02 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		padding_greater_than_precision(t_option *option, char *tab,
	int state)
{
	int result;
	int i;
	int negatif;

	negatif = (*tab == '-') ? 1 : 0;
	i = -1;
	result = 0;
	if (option->precision < (int)ft_strlen(tab) || option->precision < 1)
		while (++i < option->padding - ((int)ft_strlen(tab)))
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - option->precision - negatif)
			result += ft_putchar_int(' ');
	if (state == 0)
		result += display_precision(option, tab);
	return (result);
}

int				display_padding_and_precision(char *tab, t_option *option,
	int state)
{
	int result;
	int	i;

	i = -1;
	result = 0;
	if (option->padding > option->precision)
		result += padding_greater_than_precision(option, tab, state);
	else if (option->padding <= option->precision && state == 0
		&& option->padding != -1)
		result += display_precision(option, tab);
	return (result);
}
