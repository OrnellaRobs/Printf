/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 18:46:22 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/02 14:49:44 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_d(va_list lst, t_option *option)
{

}

int		conversion(char *format, t_option *option, va_list lst)
{
	int	i;
	int	(*convert[6])(va_list, t_option *);

	i = 0;
	convert[0] = &ft_s;
	// convert[1] = &ft_S;
	// convert[2] = &ft_p;
	// convert[3] = &ft_d;
	// convert[4] = &ft_D;
	// convert[5] = &ft_i;
	while (STR_CONVERSION[i])
	{
		if (i < 6 && STR_CONVERSION[i] == *format)
			return (convert[i](lst, option));
		else if (i >= 6 && STR_CONVERSION[i] == *format)
			return (1);
		i++;
	}
	return (0);
}
