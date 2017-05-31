/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_long_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:27:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/31 14:03:52 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_display_octet(char *ptr)
{
	char	**tab;
	int		i;
	int		nb;

	i = 0;
	tab = ft_strsplit(ptr, ' ');
	while (tab[i])
	{
		nb = ft_atoi_base(tab[i], 2);
		write(1, &nb, 1);
		i++;
	}
	free(tab);
	return (i);
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

static int		ft_binairy_mask(char *str, int len, t_option *option)
{
	char	*ptr;
	int		len_ptr;
	int		result;

	result = 0;
	ptr = NULL;
	if (len <= 7)
		ptr = ft_strdup("0xxxxxxx");
	else if (len > 7 && len <= 11)
		ptr = ft_strdup("110xxxxx 10xxxxxx");
	else if (len > 11 && len <= 16)
		ptr = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	else if (len > 16)
		ptr = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	len_ptr = ft_strlen(ptr);
	ptr = ft_fill_mask(ptr, str, len);
	if (option->minuszero != '-' && option->padding != -1)
		result += ft_display_padding(option, len_ptr / 8);
	result += ft_display_octet(ptr);
	if (option->minuszero == '-' && option->padding != -1)
		result += ft_display_padding(option, len_ptr / 8);
	free(ptr);
	return (result);
}

int				ft_convert_long_char(va_list lst, t_option *option)
{
	int		len;
	int		result;
	char	*str;

	result = 0;
	str = ft_itoa_base_printf(va_arg(lst, unsigned int), 2, 0, 0);
	len = ft_strlen(str);
	if (len > 0 || len < 22)
		result += ft_binairy_mask(str, len, option);
	return (result);
}
