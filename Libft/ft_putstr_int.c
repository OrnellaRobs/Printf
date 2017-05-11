/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 15:38:48 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/11 15:39:01 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_int(char const *s)
{
	int i;
	int result;

	i = 0;
	result = 0;
	while (s[i])
	{
		result += ft_putchar_int(s[i]);
		i++;
	}
	return (result);
}
