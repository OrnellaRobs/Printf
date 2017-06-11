/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:38:49 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 13:40:15 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		ft_get_flag_zero(char *format, t_option *option)
{
	option->minuszero = '0';
	if (ft_isdigit(*(format + 1)) && option->zero_nb == -1 &&
	option->padding == -1)
	{
		format++;
		option->zero_nb = get_number(format);
	}
}

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
			ft_get_flag_zero(format, option);
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
			option->modifier = 'h';
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

static int		ft_parsing(char *format, va_list lst, t_option *option,
int result)
{
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
	int			value;
	int			result;
	va_list		lst;
	t_option	*option;

	result = 0;
	if (!(option = ft_memalloc(sizeof(t_option))))
		return (-1);
	va_start(lst, format);
	value = ft_parsing((char *)format, lst, option, result);
	free(option);
	va_end(lst);
	return (value);
}
