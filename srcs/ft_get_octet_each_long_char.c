/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_octet_each_long_char.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 14:47:30 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 15:29:18 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_octet_less_than_precision(char *tab, char *octet, int *len_octet, int *state)
{
	char *tmp;

	tmp = tab;
	tab = ft_strjoin(tmp, octet);
	free(tmp);
	*len_octet = 0;
	*state = 1;
	return (tab);
}

char 	*ft_get_len(t_option *option, char *tab, char *str, int *len)
{
	if (option->padding != -1 && option->precision != -1 &&
		(int)ft_strlen(tab) < option->precision)
		*len = option->precision;
	else
	{
		*len = ft_strlen(tab);
		str = ft_strdup(tab);
	}
	return (str);
}
char	*ft_get_octet_each_long_char(t_option *option, unsigned int *nb, int *count, int *len)
{
	char	*tab;
	char	*octet;
	int		state;
	int		len_octet;
	int		i;
	char	*str;

	i = 0;
	len_octet = 0;
	tab = ft_strnew(0);
	state = 0;
	if (nb == 0)
		tab = "(null)";
	while (nb != 0 && nb[i])
	{
		octet = ft_convert_binairy_to_decimal(nb[i], count, &len_octet);
		if (option->precision == -1 || (*count <= option->precision &&
			option->precision > 0))
			tab = ft_octet_less_than_precision(tab, octet, &len_octet, &state);
		else
		{
			*count -= len_octet;
			free(octet);
			break ;
		}
		if (option->precision != -1 && (int)ft_strlen(tab) < option->precision)
			str = ft_strdup(tab);
		i++;
		free(octet);
	}
	str = ft_get_len(option, tab, str, len);
	if (state == 1)
		free(tab);
	return (str);
}
