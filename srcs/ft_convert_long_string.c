/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_long_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:10:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/30 15:55:13 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_binairy_mask(char *str, int len)
{
	char	*ptr;
	int		len_ptr;

	ptr = NULL;
	if (len <= 7)
		ptr = ft_strdup("0xxxxxxx");
	else if (len > 7 && len <= 11)
		ptr = ft_strdup("110xxxxx 10xxxxxx");
	else if (len > 11 && len <= 16)
		ptr = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	else if (len > 16)
		ptr = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	if (len <= 21)
	{
		len_ptr = ft_strlen(ptr);
		ptr = ft_fill_mask(ptr, str, len);
	}
	return (ptr);
}

static	char	*ft_convert_binairy_to_decimal(unsigned int value, int *count,
t_option *option, int *i)
{
	char *str;
	int len;
	char **tab;
	char *ptr;

	str = ft_itoa_base_printf(value, 2, 0, 0);
	len = ft_strlen(str);
	if (len > 0 || len < 22)
		ptr = ft_binairy_mask(str, len);
	tab = ft_strsplit(ptr, ' ');
	str = malloc(sizeof(char) * ft_strlen(ptr) / 8);
	while (tab[(*i)])
	{
		str[(*i)] = ft_atoi_base(tab[*i], 2);
		(*i)++;
	}
	*count += *i;
	free(ptr);
	return (str);
}


static int		ft_display_padding(t_option *option, int len, int count)
{
	int i;
	int result;

	i = -1;
	result = 0;
	if (option->precision == -1)
	{
		if (option->padding != -1)
			while (++i < option->padding - len)
				result += ft_putchar_int(' ');
		else if (option->zero_nb != -1)
			while (++i < option->zero_nb - len)
				result += ft_putchar_int('0');
	}
	else if (option->precision == 0)
	{
		while (++i < option->padding)
		{
			if (option->minuszero != '0')
				result += ft_putchar_int(' ');
			else if (option->minuszero == '0')
				result += ft_putchar_int('0');
		}
	}
	else if (option->precision > 1)
	{
		while (++i < option->padding - count)
		{
			if (option->minuszero != '0')
				result += ft_putchar_int(' ');
			else if (option->minuszero == '0')
				result += ft_putchar_int('0');
		}
		if (option->minuszero != '0')
			result += count - option->precision;
	}
	return (result);
}

int		ft_display_precision_long_string(t_option *option, char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < option->precision)
	{
		result += ft_putchar_int(str[i]);
		i++;
	}
	return (result);
}

int		ft_convert_long_string(va_list lst, t_option *option)
{
	unsigned int *nb;
	int		i;
	char 	*tab;
	char	*str;
	int		result;
	int		len;
	int count;
	int len_octet;

	len_octet = 0;
	count = 0;
	i = 0;
	result = 0;
	tab = "";
	nb = va_arg(lst, unsigned int *);
	if (nb == 0)
		tab = "(null)";
	else
	{
		while (nb[i])
		{
			char *octet = ft_convert_binairy_to_decimal(nb[i], &count, option,
			&len_octet);
			if (count <= option->precision)
			{
				tab = ft_strjoin(tab, octet);
				len_octet = 0;
			}
			else
			{
				count -= len_octet;
				break ;
			}
			if (option->precision != -1 && (int)ft_strlen(tab) <= option->precision)
				str = ft_strdup(tab);
			i++;
		}
	}
	if (option->precision != -1 && (int)ft_strlen(tab) < option->precision)
		len = option->precision;
	else
	{
		len = ft_strlen(tab);
		str = ft_strdup(tab);
	}
	if (option->minuszero != '-' &&
	(option->padding != -1 || option->zero_nb != -1) &&
	(option->padding > len || option->zero_nb > len))
		result += ft_display_padding(option, len, count);
	if (option->precision == -1)
		result += ft_putstr_int(str);
	else if (option->precision > 1)
		result += ft_display_precision_long_string(option, str);
	if (option->minuszero == '-' && option->padding != -1 &&
	option->padding > len)
		result += ft_display_padding(option, len, count);
	return (result);
}
