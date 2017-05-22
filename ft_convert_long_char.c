/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_long_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:27:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/22 19:04:34 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char 	*ft_fill_mask(char *ptr, char *str, int len_str)
{
	int len_ptr;

	len_str--;
	len_ptr = ft_strlen(ptr) - 1;

	while (len_ptr >= 0)
	{
		if (ptr[len_ptr] == 'x')
		{
			if (len_str >= 0)
			{
				ptr[len_ptr] = str[len_str];
				len_str--;
			}
			else
				ptr[len_ptr] = '0';
		}
		len_ptr--;
	}
	return (ptr);
}

void 	ft_display_octet(char *ptr)
{
	char **tab;
	int i;
	int nb;

	i = 0;
	tab = ft_strsplit(ptr, ' ');
	while (tab[i])
	{
		nb = ft_atoi_base(tab[i], 2);
		write(1, &nb, 1);
		i++;
	}
}

void 	ft_binairy_mask(char *str, int len)
{
	char	*ptr;
	int		len_ptr;

	ptr = NULL;
	if (len <= 7)
		ptr 
	else if (len <= 11)
		ptr = ft_strdup("110xxxxx 10xxxxxx");
	else if (len > 11 && len <= 16)
		ptr = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
	else if (len > 16)
		ptr = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
	if (len <= 21)
	{
		len_ptr = ft_strlen(ptr);
		ptr = ft_fill_mask(ptr, str, len);
		ft_display_octet(ptr);
		free(ptr);
	}
}

int		ft_convert_long_char(va_list lst, t_option *option)
{
	int result;
	char *str;
	int len;

	result = 0;
	str = ft_itoa_base_printf(va_arg(lst, unsigned int), 2, 0, 0);
	len = ft_strlen(str);
	// if (len <= 7)
	if (len >= 7)
		ft_binairy_mask(str, len);
	return (result);
}
