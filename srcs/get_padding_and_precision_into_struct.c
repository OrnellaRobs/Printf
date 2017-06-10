/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_padding_and_precision_into_struct.c            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/10 13:15:39 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/10 13:15:54 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void		get_precision(char **format, t_option *option, int *zero,
	int tmp)
{
	if (option->precision != -1)
	{
		*zero = 3;
		option->precision = -1;
	}
	else if (*zero != 3)
	{
		if (tmp != -1 && option->padding == -1)
			option->padding = tmp;
		(*format)++;
		while ((**format) && !(ft_is_in(**format, STR_CONVERSION)) &&
		!(ft_is_in(**format, "123456789")))
			(*format)++;
		if (option->precision == -1)
			option->precision = get_number(*format);
	}
}

void			padding_and_precision(char *format, t_option *option)
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
			get_precision(&format, option, &zero, tmp);
		format++;
	}
}
