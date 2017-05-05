/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_d_padding_precision.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:40:48 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 16:43:45 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					display_precision(t_option *option, int nb)
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

int				precision_greater_than_zero(t_option *option, int nb, int state)
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

int				precision_lower_than_one(t_option *option, int nb)
{
	int result;
	int i;
	int negatif;

	result = 0;
	i = -1;
	negatif = (nb < 0) ? 1 : 0;
	while (++i < option->padding - (ft_intlen(nb) + negatif))
		result += ft_putchar_int(' ');
	if (negatif == 1)
		result += ft_putchar_int('-');
	return (result);
}

int		display_padding_and_precision(int nb, t_option *option, int state)
{
	int result;
	int	i;

	i = -1;
	result = 0;
	if (option->padding > option->precision && option->precision < 1)
		result += precision_lower_than_one(option, nb);
	else if (option->padding > option->precision && option->precision > 0)
		result += precision_greater_than_zero(option, nb, state);
	else if (option->padding <= option->precision)
		while (++i < option->precision - ft_intlen(nb))
			result += ft_putchar_int('0');
	return (result);
}
