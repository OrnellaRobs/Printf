/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_binairy_to_decimal_long_str.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 13:44:47 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 13:45:07 by orazafin         ###   ########.fr       */
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

char			*ft_convert_binairy_to_decimal(unsigned int value, int *count,
	int *i)
{
	int		len;
	char	*str;
	char	**tab;
	char	*ptr;

	str = ft_itoa_base_printf(value, 2, 0, 0);
	len = ft_strlen(str);
	if (len > 0 || len < 22)
		ptr = ft_binairy_mask(str, len);
	tab = ft_strsplit(ptr, ' ');
	free(str);
	if (!(str = malloc(sizeof(char) * ft_strlen(ptr) / 8)))
		return (NULL);
	free(ptr);
	while (tab[(*i)])
	{
		str[(*i)] = ft_atoi_base(tab[*i], 2);
		(*i)++;
	}
	str[(*i)] = '\0';
	*count += *i;
	free_array(tab);
	return (str);
}
