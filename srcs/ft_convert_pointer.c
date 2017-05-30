/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:50:19 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/30 16:36:59 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
** precision pour la conversion de p (undefined behavior)
** flag 0 (undefined behavior)
*/

static int		ft_get_size_for_malloc(unsigned long value, int base)
{
	int total_number;

	total_number = 0;
	while (value > 0)
	{
		total_number++;
		value = value / base;
	}
	return (total_number);
}

char			*ft_itoa_base_printf_pointer(unsigned long value, int base,
	int upper_case)
{
	char	*tab;
	int		total_number;
	char	*alpha;

	alpha = (upper_case < 1) ? "0123456789abcdef" : "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (NULL);
	else if (base == 10)
		return (ft_itoa((int)value));
	if (value == 0)
		return ("0");
	total_number = ft_get_size_for_malloc(value, base);
	if (!(tab = malloc(sizeof(char) * (total_number + 1))))
		return (NULL);
	tab[total_number] = '\0';
	total_number--;
	while (value > 0)
	{
		tab[total_number] = alpha[value % base];
		total_number--;
		value = value / base;
	}
	return (tab);
}

static int		ft_display_pointer(t_option *option, char *tab)
{
	int result;
	int i;
	int state;

	i = -1;
	result = 0;
	state = 0;
	if (option->padding == -1 && option->precision != -1)
	{
		state = 1;
		result += ft_putstr_int(tab);
		if (option->minuszero == '0')
			result += ft_display_flag_zero_str(option, tab);
		while (++i < option->precision - 1)
			result += ft_putchar_int('0');
	}
	else
		if (option->precision > (int)ft_strlen(tab) && *tab)
			while (++i < option->precision - (int)ft_strlen(tab))
				result += ft_putchar_int('0');
	if (state == 0)
	{
		result += ft_putstr_int(tab);
		if (option->minuszero == '0')
			result += ft_display_flag_zero_str(option, tab);
	}
	return (result);
}

/*
** void * car ca pointe directement sur la zone mémoire
*/

int				ft_conv_pointer(va_list lst, t_option *option)
{
	int				result;
	int				i;
	char			*tab;
	unsigned long	nb;

	i = -1;
	result = 0;
// 	printf("padd = %d | prec =  %d | nb_zero = %d\n", option->padding,
// option->precision, option->zero_nb);
	nb = (unsigned long)va_arg(lst, void *);
	tab = ft_itoa_base_printf_pointer(nb, 16, 0);
	if (option->precision < (int)ft_strlen(tab))
		tab = (*tab == '0' && option->precision == 0) ?
		ft_strjoin(tab, "x") : ft_strjoin("0x", tab);
	else
		result += ft_putstr_int("0x");
	if (option->minuszero == '-')
		result += ft_display_pointer(option, tab);
	// printf("\nstrlen = %d\n", (int)ft_strlen(tab));
	if (option->padding != -1 && option->precision > (int)ft_strlen(tab))
		while (++i < option->padding - option->precision)
			result += ft_putchar_int(' ');
	else if (option->padding != -1 && option->precision <= (int)ft_strlen(tab))
		while (++i < option->padding - (int)ft_strlen(tab))
			result += ft_putchar_int(' ');
	if (option->minuszero != '-')
		result += ft_display_pointer(option, tab);
	return (result);
}
