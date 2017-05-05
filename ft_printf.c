/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 18:38:49 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/05 11:54:04 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	initialize_option(t_option *option)
{
	option->pluspace = '\0';
	option->minuszero = '\0';
	option->zero_nb = 0;
	option->hash = '\0';
	option->modifier = '\0';
	option->padding = -1;
	option->precision = -1;
}

int		get_number(char *str)
{
	int result;

	result = 0;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result);
}

int		ft_is_in(char elem, char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		if (src[i] == elem)
			return (1);
		i++;
	}
	return (0);
}

void	flag(char *format, t_option *flag)
{
	while (ft_is_in(*format, STR_CONVERSION) == 0)
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

void  	length_modifier(char *format, t_option *flag)
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

int		how_many_percent(char *format)
{
	int count;

	count = 0;
	while (*format == '%')
	{
		format++;
		count++;
	}
	 return (count);
}

void 	padding_and_precision(char *format, t_option *flag)
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

int 	ft_display_percent(int percent)
{
	int result;

	result = 0;
	if (percent % 2 == 0)
	{
		while (percent - 2 >= 0)
		{
			result += ft_putchar_int('%');
			percent = percent - 2;
		}
	}
	else
	{
		percent = percent - 1;
		while (percent - 2 >= 0)
		{
			result += ft_putchar_int('%');
			percent = percent - 2;
		}
	}
	return (result);
}

int		ft_parsing(char* format, va_list lst)
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
			percent = how_many_percent(format);
			if (percent != 1)
				result += ft_display_percent(percent);
			while (*format == '%')
				format++;
			if (percent % 2 == 0)
				format++;
			else
			{
				padding_and_precision(format, option);
				flag(format, option);
				length_modifier(format, option);
				while (ft_is_in(*format, STR_CONVERSION) == 0)
					format++;
			// printf("\n\n ---------- \n\n");
			// printf("plusspace = %c\n", option->pluspace);
			// printf("minuszero = %c\n", option->minuszero);
			// printf("zero_nb = %d\n", option->zero_nb);
			// printf("hash = %c\n", option->hash);
			// printf("modifier = %c\n", option->modifier);
			// printf("padding = %d\n", option->padding);
			// printf("precision = %d\n", option->precision);
			// printf("\n\n ---------- \n\n");
				result = conversion(format, option, lst);
			}
		}
		else
			result += ft_putchar_int(*format);
		format++;
	}
	return (result);
}

int		ft_printf(const char *format, ...)
{
	int value;

	va_list lst;
	va_start(lst, format);
	value = ft_parsing((char *)format, lst);
	va_end(lst);
	return (value);
}

int		main(void)
{
	char	*str = "bonjour";
	// char i = 'a';
	ft_printf("%+u\n", -6);
	printf("%+u", -6);
	return 0;
}
