/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:46:22 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/13 00:20:45 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*reminder : # define STR_CONVERSION "sSpdDi%oOuUxXcC" */
/* FLAG 0 à gérer pour la conversion de CHAR (undefined behavior)*/
/* FLAG space à gérer pour la conversion des HEXA (undefined behavior) */
/* CE QU'IL RESTE A GÉRER : S , p, D, O, U, C*/
int		display_padding(t_option *option)
{
	int i;
	int result;

	i = 1;
	result = 0;
	while (i < option->padding)
	{
		result += ft_putchar_int(' ');
		i++;
	}
	return (result);
}

int		ft_conv_char(t_option *option, long long nb)
{
	int		result;
	char	c;

	result = 0;
	c = (char)nb;
	if (option->minuszero != '-' && option->padding != -1)
		result += display_padding(option);
	result += ft_putchar_int(c);
	if (option->padding != -1)
		result += display_padding(option);
	return (result);
}

int		ft_convert_int(t_option *option, char *format, long long nb)
{
	int result;
	char *tab;

	result = 0;
	if (*format == 'c')
		result += ft_conv_char(option, nb);
	else if (*format == 'u')
		result += ft_conv_unsigned_int(option, (unsigned int)nb);
	else if (*format == 'x' || *format == 'X')
		result += ft_convert_hexa(option, (unsigned int)nb, format);
	else if (*format == 'o')
		result += ft_convert_octal(option, (unsigned int)nb);
	else if (*format == 'p')
		result += ft_convert_pointer(option, (unsigned int)nb);
	return (result);
}

int		conversion(char *format, t_option *option, va_list lst)
{
	int	i;
	int	(*convert[6])(va_list, t_option *);

	i = 0;
	convert[0] = &ft_conv_string;
	// convert[1] = &ft_convert_S;
	// convert[2] = &ft_convert_p;
	convert[3] = &ft_conv_int;
	// convert[4] = &ft_convert_D;
	convert[5] = &ft_conv_int;
	while (STR_CONVERSION[i])
	{
		if (i < 6 && STR_CONVERSION[i] == *format)
			return (convert[i](lst, option));
		else if (*format == '%')
			return (ft_percent(option));
		else if (i >= 6 && STR_CONVERSION[i] == *format)
			return (ft_convert_int(option, format, va_arg(lst, long long)));
		i++;
	}
	return (0);
}
