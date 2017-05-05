/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned_decimal.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:51:07 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 16:53:13 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_unsigned_intlen(unsigned int n)
{
	int i;

	i = 1;
	while ((n = n / 10))
		i++;
	return (i);
}

void	ft_putnbr_unsigned_int(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else if (n <= 9)
		ft_putchar(n + '0');
}

static int		display_flag_zero(unsigned int nb, t_option *option)
{
	int result;
	int i;

	i = 0;
	result = 0;
	if (option->minuszero == '0')
	{
		while (i < option->zero_nb - ft_intlen(nb))
		{
			result += ft_putchar_int('0');
			i++;
		}
	}
	return (result);
}


static int				display_precision(t_option *option, unsigned int nb)
{
	int i;
	int result;

	result = 0;
	i = -1;
	while (++i < option->precision - ft_intlen(nb))
		result += ft_putchar_int('0');
	return (result);
}

static int				precision_greater_than_zero(t_option *option, unsigned int nb, int state)
{
	int result;
	int i;

	i = -1;
	result = 0;
	if (option->precision < ft_intlen(nb))
		while (++i < option->padding - ft_intlen(nb))
			result += ft_putchar_int(' ');
	else
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	if (state == 0)
		result += display_precision(option, nb);
	return (result);
}

static int		precision_lower_than_one(t_option *option, unsigned int nb)
{
	int result;
	int i;

	result = 0;
	i = -1;
	while (++i < option->padding - ft_intlen(nb))
		result += ft_putchar_int(' ');
	return (result);
}

static int		display_padding_and_precision(unsigned int nb, t_option *option, int state)
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

int				ft_convert_unsigned_decimal(t_option *option, long long nb)
{
	unsigned int decimal;
	int result;
	int state;

	state = 0;
	result = 0;
	decimal = (unsigned int)nb;
	result += display_flag_zero(decimal, option);
	if (option->minuszero == '-' && option->padding != -1)
	{
		state = 1;
		result += display_precision(option, decimal);
		ft_putnbr_unsigned_int(decimal);
	}
	result += display_padding_and_precision(decimal, option, state);
	result += ft_unsigned_intlen(nb);
	if (state == 0)
		ft_putnbr_unsigned_int(decimal);
	return (result);
}
