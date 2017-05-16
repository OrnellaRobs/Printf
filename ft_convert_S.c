/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_S.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/16 15:26:02 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/16 15:28:07 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_convert_S(va_list lst, t_option *option)
{
	int result;
	wchar_t *tab;

	result = 0;
	if (!(tab = va_arg(lst, wchar_t *)))
		tab = L"(null)";
	return (result); 
}
