/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:38:49 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/31 16:16:25 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		flag(char *format, t_option *option)
{
	int digit;

	digit = 0;
	while (*format && ft_is_in(*format, STR_CONVERSION) == 0)
	{
		if (*format == '+')
			option->pluspace = '+';
		else if (*format == ' ' && option->pluspace != '+')
			option->pluspace = 's';
		else if (*format == '-')
			option->minuszero = '-';
		else if (*format >= '1' && *format <= '9' && option->minuszero == '\0')
			digit = 1;
		else if (*format == '0' && option->minuszero != '-' && digit == 0)
		{
			option->minuszero = '0';
			if (ft_isdigit(*(format + 1)) && option->zero_nb == -1 &&
			option->padding == -1)
			{
				format++;
				option->zero_nb = get_number(format);
			}
		}
		else if (option->minuszero == '0' && option->zero_nb == -1 &&
		ft_isdigit(*format) && option->precision == -1 && option->padding == -1)
			option->zero_nb = get_number(format);
		else if (*format == '#')
			option->hash = '#';
		format++;
	}
}

static void		length_modifier(char *format, t_option *option)
{
	while (*format && ft_is_in(*format, STR_CONVERSION) == 0)
	{
		if (*format == 'h' && *(format + 1) != 'h' && option->modifier != 'z'
	&& option->modifier != 'j')
		{
				option->modifier = 'h';
		}
		else if (*format == 'h' && *(format + 1) == 'h')
		{
			option->modifier = 'i';
			format++;
		}
		else if (*format == 'j')
			option->modifier = 'j';
		else if (*format == 'z')
			option->modifier = 'z';
		else if (*format == 'l' && *(format + 1) != 'l')
			option->modifier = 'l';
		else if (*format == 'l' && *(format + 1) == 'l')
		{
			option->modifier = 'm';
			format++;
		}
		format++;
	}
}

static void		padding_and_precision(char *format, t_option *option)
{
	int		zero;
	int		tmp;

	zero = 0;
	tmp = -1;
	while (*format && ft_is_in(*format, STR_CONVERSION) == 0)
	{
		if (*format == '0' && zero == 0 && option->padding == -1)
			zero = 1;
		else if (*format == '-')
			zero = 2;
		else if (*format >= '1' && *format <= '9' && (zero == 0 || zero == 2)
		&& option->padding == -1)
			option->padding = get_number(format);
		else if ((*format >= '1' && *format <= '9' && zero == 1
		&& option->padding == -1) && tmp == -1)
			tmp = get_number(format);
		if (*format == '.')
		{
			if (option->precision != -1)
			{
				zero = 3;
				option->precision = -1;
			}
			else if (zero != 3)
			{
				if (tmp != -1 && option->padding == -1)
					option->padding = tmp;
				format++;
				while (*format && !ft_is_in(*format, STR_CONVERSION) && !ft_is_in(*format, "123456789"))
					format++;
			if (option->precision == -1)
				option->precision = get_number(format);
			}
		}
		format++;
	}
}

static int		ft_parsing(char *format, va_list lst, t_option *option)
{
	int			result;

	result = 0;
	while (*format)
	{
		initialize_option(option);
		if (*format == '%')
		{
			format++;
			padding_and_precision(format, option);
			flag(format, option);
			length_modifier(format, option);
			while (*format && ft_is_in(*format, STR_CONVERSION) == 0 &&
			ft_is_in(*format, FLAG_CONVERSION))
				format++;
			result += conversion(format, option, lst, *format);
		}
		else
			result += ft_putchar_int(*format);
		if (*format)
			format++;
	}
	return (result);
}

int				ft_printf(const char *format, ...)
{
	int		value;
	va_list	lst;
	t_option	*option;

	if (!(option = malloc(sizeof(t_option))))
		return (-1);
	va_start(lst, format);
	value = ft_parsing((char *)format, lst, option);
	va_end(lst);
	return (value);
}
