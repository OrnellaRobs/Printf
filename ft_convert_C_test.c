/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_C.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 12:33:07 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/16 18:28:43 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_octet(wchar_t res, char *octet, int *i, int len)
{
	if (len > 7)
	{
		if (len > 11)
		{
			if (len > 16)
			{
				octet[(*i)++] = ((res >> 18) & 0b00000111) | 0b11110000;
				octet[(*i)++] = ((res >> 12) & 0b00111111) | 0b10000000;
			}
			else
				octet[(*i)++] = ((res >> 12) & 0b00001111) | 0b11100000;
			octet[(*i)++] = ((res >> 6) & 0b00111111) | 0b10000000;
		}
		else
			octet[(*i)++] = ((res >> 6) & 0b00011111) | 0b11000000;
		octet[(*i)++] = (res & 0b00111111) | 0b10000000;
	}
	else
		octet[(*i)++] = (char)res;
	octet[(*i)++] = '\0';
}

int		ft_convert_C(va_list lst, t_option *option)
{
	int		result;
	int 	len;
	char	octet[5];
	wchar_t res;
	int 	i;

	i = 0;
	result = 0;
	res = va_arg(lst, wchar_t);
	len = ft_count_bit(res);
	ft_octet(res, octet, &i, len);
	result += ft_putstr_int(octet);
	return (result);
}
