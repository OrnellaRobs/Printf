/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:23:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 11:57:25 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* il manque la gestion de MODIFIER */
static int		display_flag_plusspace(t_option *option)
{
	int result;

	result = 0;
	if (option->pluspace == '+')
		result += ft_putchar_int('+');
	else if (option->pluspace == 's')
		result += ft_putchar_int(' ');
	return (result);
}

int				ft_convert_d(va_list lst, t_option *option)
{
	int nb;
	int result;
	int state;
	int diff;

	state = 0;
	result = 0;
	diff = 0;
	nb = va_arg(lst, int);
	result += display_flag_plusspace(option);
	result += display_flag_zero(nb, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		ft_putnbr(nb);
		state = 1;
	}
	result += display_padding_and_precision(nb, option, diff);
	result += ft_intlen(nb);
	if (state == 0)
		ft_putnbr(nb);
	return (result);
}
