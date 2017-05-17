/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_long_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/17 16:27:23 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/17 20:21:55 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_fill_mask(char *ptr, char *str)
{
	int i;

	i = ft_strlen(ptr);
	while (i != 0)
	{
		if (*ptr == 'x')
		{
			*ptr = *str;
			str--;
			i--;
		}
}

void 	ft_binairy_mask(char *str, int len)
{
	char *ptr;

	ptr = NULL;
	if (len <= 11)
	{
		ptr = ft_strdup("110xxxxx 10xxxxxx");
		ft_fill_mask(ptr, str);
		//fonction qui affiche avec un ft_strsplit qui separe les octets
	}
	else if (len > 11 && len <= 16)
	{
		ptr = ft_strdup("1110xxxx 10xxxxxx 10xxxxxx");
		//ici une fonction qui remplace les x
		//fonction qui affiche avec un ft_strsplit qui separe les octets
	}
	else if (len > 16)
	{
		ptr = ft_strdup("11110xxx 10xxxxxx 10xxxxxx 10xxxxxx");
		//ici une fonction qui remplace les x
		//fonction qui affiche avec un ft_strsplit qui separe les octets
	}
	free(ptr);
}

int		ft_convert_long_char(va_list lst, t_option *option)
{
	int len;
	int result;
	char *str;
	int len;

	result = 0;
	str = ft_itoa_base_printf((va_arg(lst, unsigned int), 2, 0, 0));
	len = ft_strlen(str);
	// if (len <= 7)
	if (len > 7)
		ft_binairy_mask(str, len);
}
