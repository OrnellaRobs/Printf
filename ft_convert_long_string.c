/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_long_string.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 13:10:32 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/23 16:02:19 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_binairy_mask(char *str, int len)
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

char	*ft_convert(unsigned int value)
{
	char *str;
	int len;
	char **tab;
	char *ptr;
	int i;

	str = ft_itoa_base_printf(value, 2, 0, 0);
	len = ft_strlen(str);
	if (len > 0 || len < 22)
		ptr = ft_binairy_mask(str, len);
	tab = ft_strsplit(ptr, ' ');
	str = malloc(sizeof(char) * ft_strlen(ptr) / 8);
	i = 0;
	while (tab[i])
	{
		str[i] = ft_atoi_base(tab[i], 2);
		i++;
	}
	free(ptr);
	return (str);
}


static int		ft_display_padding(t_option *option, int len)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < option->padding - len)
	{
		result += ft_putchar_int(' ');
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

	i = 0;
	result = 0;
	tab = "";
	nb = va_arg(lst, unsigned int *);
	while (nb[i])
	{
		tab = ft_strjoin(tab, ft_convert(nb[i]));
		if (option->precision != -1 && ft_strlen(tab) <= option->precision)
			str = ft_strdup(tab);
		i++;
	}
	if (option->precision != -1 && ft_strlen(tab) < option->precision )
		len = option->precision;
	else
	{
		len = ft_strlen(tab);
		str = ft_strdup(tab);
	}
	if (option->minuszero != '-' && option->padding != -1 &&
	option->padding > len)
		result += ft_display_padding(option, len);
	result += ft_putstr_int(str);
	if (option->minuszero == '-' && option->padding != -1 &&
	option->padding > len)
		result += ft_display_padding(option, len);
	return (result);
}
