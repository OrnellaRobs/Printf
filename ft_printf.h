/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:42:08 by orazafin          #+#    #+#             */
/*   Updated: 2017/05/16 15:56:43 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STR_CONVERSION "sSpcC%dDioOuUxX"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <locale.h>

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
int		ft_conv_int(t_option *option, char *tab);
int		conversion(char *format, t_option *option, va_list lst);
int		ft_conv_string(va_list lst, t_option *option);
int		ft_percent(t_option *option);
char	*ft_itoa_base_printf(unsigned int value, int base, int upper_case,
	int sign);
int		ft_convert_hexa(t_option *option, char *tab, char *format);
int		ft_convert_octal(t_option *option, char *tab);
int		ft_conv_pointer(va_list lst, t_option *option);
int		ft_conv_char(va_list lst, t_option *option);
char	*ft_lltoa_base_sign(long long value, int base, int upper_case, int sign);
char	*ft_lltoa_base_unsigned(unsigned long long value, int base, int upper_case, int sign);
int		ft_conv_unsigned_int(t_option *option, char *tab);
int		ft_convert_C(va_list lst, t_option *option);
#endif
