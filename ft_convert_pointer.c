/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 16:50:19 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/11 16:52:51 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if (option->minuszero == '-' && option->padding != -1)
// {
// 	state = 1;
// 	result += display_precision(option, decimal);
// 	ft_putnbr_unsigned_int(decimal);
// }
// result += display_padding_and_precision(decimal, option, state);
// result += ft_unsigned_intlen(nb);
// if (state == 0)
// 	ft_putnbr_unsigned_int(decimal);

int		ft_convert_pointer(t_option *option, unsigned int nb)
{
	int result;
	char *tab;

	result = 0;
	tab = ft_itoa_base_printf(nb, 16, 0);
	tab = ft_strjoin("0x10", tab);
	printf("\ntab = %s\n", tab);
	return (result);
}
