/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:23:55 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 16:32:04 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* il manque la gestion de MODIFIER */

static int		display_flag_zero(int nb, t_option *option)
{
	int result;
	int i;
	int negatif;

	i = 0;
	result = 0;
	negatif = (nb < 0) ? 1 : 0;
	if (option->minuszero == '0')
	{
		while (i < option->zero_nb - (ft_intlen(nb) + negatif))
		{
			result += ft_putchar_int('0');
			i++;
		}
	}
	return (result);
}


int				display_precision(t_option *option, int nb)
{
	int i;
	int result;

	result = 0;
	i = -1;
	if (nb < 0)
		result += ft_putchar_int('-');
	while (++i < option->precision - ft_intlen(nb))
		result += ft_putchar_int('0');
	return (result);
}

int		precision_greater_than_zero(t_option *option, int nb, int state)
{
	int result;
	int i;
	int negatif;

	negatif = (nb < 0) ? 1 : 0;
	i = -1;
	result = 0;
	if (option->precision < ft_intlen(nb))
		while (++i < option->padding - (ft_intlen(nb) + negatif))
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - option->precision - negatif)
			result += ft_putchar_int(' ');
	if (state == 0)
		result += display_precision(option, nb);
	return (result);
}

static int		display_padding_and_precision(int nb, t_option *option, int state)
{
	int result;
	int i;
	int negatif;

	result = 0;
	i = -1;
	negatif = (nb < 0) ? 1 : 0;
	if (option->padding > option->precision && option->precision < 1)
	{
		while (++i < option->padding - (ft_intlen(nb) + negatif))
			result += ft_putchar_int(' ');
		if (negatif == 1)
			result += ft_putchar_int('-');
	}
	else if (option->padding > option->precision && option->precision > 0)
		result += precision_greater_than_zero(option, nb, state);
	else if (option->padding <= option->precision)
		while (++i < option->precision - ft_intlen(nb))
			result += ft_putchar_int('0');
	return (result);
}

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

	state = 0;
	result = 0;
	nb = va_arg(lst, int);
	result += display_flag_plusspace(option);
	if ((nb < 0) &&
	(option->padding == -1 || option->padding <= option->precision))
		result += ft_putchar_int('-');
	result += display_flag_zero(nb, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		state = 1;
		result += display_precision(option, nb);
		ft_putnbr(nb * -1);
	}
	result += display_padding_and_precision(nb, option, state);
	result += ft_intlen(nb);
	if (nb < 0 && state == 0 )
		ft_putnbr(nb * -1);
	else
		ft_putnbr(nb);
	return (result);
}
