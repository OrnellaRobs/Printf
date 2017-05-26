/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_flag_zero_str.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/26 18:24:00 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/26 18:25:30 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_display_flag_zero_str(t_option *option, char *str)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (i < option->zero_nb - (int)ft_strlen(str))
	{
		result += ft_putchar_int('0');
		i++;
	}
	return (result);
}
