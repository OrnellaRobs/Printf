/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:42:08 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/11 15:27:47 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STR_CONVERSION "sSpdDi%oOuUxXcC"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct	s_option
{
	char		pluspace;
	char		minuszero;
	int			zero_nb;
	char		hash;
	char		modifier;
	int			padding;
	int			precision;
}				t_option;

int		main(void);
int		ft_printf(const char *format, ...);
int		conversion(char *format, t_option *option, va_list lst);
int		ft_conv_string(va_list lst, t_option *option);
int		ft_conv_int(va_list lst, t_option *option);
int		ft_percent(t_option *option);
int		ft_conv_unsigned_int(t_option *option, long long nb);
char	*ft_itoa_base_printf(unsigned int value, int base, int upper_case);

#endif
