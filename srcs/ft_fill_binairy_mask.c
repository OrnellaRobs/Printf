/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_mask.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 14:20:48 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 18:48:11 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_fill_binairy_mask(char *ptr, char *str, int len_str)
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
