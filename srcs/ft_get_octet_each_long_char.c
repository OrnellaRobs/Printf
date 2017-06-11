/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_octet_each_long_char.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:47:30 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 16:34:57 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*ft_octet_less_than_precision(t_option *option, char *tab,
	char *octet,
	int *len_octet)
{
	char *tmp;

	tmp = tab;
	tab = ft_strjoin(tmp, octet);
	free(tmp);
	*len_octet = 0;
	option->state = 1;
	return (tab);
}

static char		*ft_get_len(t_option *option, char *tab, char *str, int *len)
{
	if (option->padding != -1 && option->precision != -1 &&
		(int)ft_strlen(tab) < option->precision)
		*len = option->precision;
	else
	{
		*len = ft_strlen(tab);
		str = ft_strdup(tab);
	}
	if (option->state == 1)
		free(tab);
	return (str);
}

char			*ft_get_octet_each_long_char(t_option *option, char *tab,
	int *count, int *len)
{
	char	*octet;
	int		len_octet;
	int		i;
	char	*str;

	i = -1;
	len_octet = 0;
	while (option->nb != 0 && option->nb[++i])
	{
		octet = ft_convert_binairy_to_decimal(option->nb[i], count, &len_octet);
		if (option->precision == -1 || (*count <= option->precision &&
			option->precision > 0))
			tab = ft_octet_less_than_precision(option, tab, octet, &len_octet);
		else
		{
			*count -= len_octet;
			free(octet);
			break ;
		}
		if (option->precision != -1 && (int)ft_strlen(tab) < option->precision)
			str = ft_strdup(tab);
		free(octet);
	}
	str = ft_get_len(option, tab, str, len);
	return (str);
}
