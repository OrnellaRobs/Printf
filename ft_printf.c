/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:38:49 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/24 17:48:42 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		flag(char *format, t_option *flag)
{
	while (*format && ft_is_in(*format, STR_CONVERSION) == 0)
	{
		if (*format == '+')
			flag->pluspace = '+';
		else if (*format == ' ' && flag->pluspace != '+')
			flag->pluspace = 's';
		else if (*format == '-')
			flag->minuszero = '-';
		else if (*format == '0' && flag->minuszero != '-'
		&& flag->padding == -1)
		{
			flag->minuszero = '0';
			format++;
			flag->zero_nb = get_number(format);
		}
		else if (*format == '#')
			flag->hash = '#';
		format++;
	}
}

static void		length_modifier(char *format, t_option *flag)
{
	while (ft_is_in(*format, STR_CONVERSION) == 0)
	{
		if (*format == 'h' && *(format + 1) != 'h')
			flag->modifier = 'h';
		else if (*format == 'h' && *(format + 1) == 'h')
		{
			flag->modifier = 'i';
			format++;
		}
		else if (*format == 'j')
			flag->modifier = 'j';
		else if (*format == 'z')
			flag->modifier = 'z';
		else if (*format == 'l' && *(format + 1) != 'l')
			flag->modifier = 'l';
		else if (*format == 'l' && *(format + 1) == 'l')
		{
			flag->modifier = 'm';
			format++;
		}
		format++;
	}
}

static void		padding_and_precision(char *format, t_option *flag)
{
	int		zero;

	zero = 0;
	while (ft_is_in(*format, STR_CONVERSION) == 0)
	{
		if (*format == '0')
			zero = 1;
		else if (*format >= '1' && *format <= '9' && zero == 0
		&& flag->padding == -1)
			flag->padding = get_number(format);
		else if (*format == '.')
		{
			format++;
			flag->precision = get_number(format);
		}
		format++;
	}
}

static int		ft_parsing(char *format, va_list lst)
{
	t_option	*option;
	int			percent;
	int			result;

	result = 0;
	if (!(option = malloc(sizeof(t_option))))
		return (-1);
	while (*format)
	{
		initialize_option(option);
		if (*format == '%')
		{
			format++;
			padding_and_precision(format, option);
			flag(format, option);
			length_modifier(format, option);
			while (ft_is_in(*format, STR_CONVERSION) == 0)
				format++;
			result += conversion(format, option, lst);
		}
		else
			result += ft_putchar_int(*format);
		format++;
	}
	return (result);
}

int				ft_printf(const char *format, ...)
{
	int		value;
	va_list	lst;

	va_start(lst, format);
	value = ft_parsing((char *)format, lst);
	va_end(lst);
	return (value);
}
