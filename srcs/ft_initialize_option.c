/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_option.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/23 17:56:40 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 13:38:40 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	initialize_option(t_option *option)
{
	option->pluspace = '\0';
	option->minuszero = '\0';
	option->zero_nb = -1;
	option->hash = '\0';
	option->modifier = '\0';
	option->padding = -1;
	option->precision = -1;
}
