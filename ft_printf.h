/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:42:08 by orazafin          #+#    #+#             */
/*   Updated: 2017/06/11 19:53:16 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define STR_CONVERSION "sSpcC%dDioOuUxX"
# define FLAG_CONVERSION "0123456789-+# .jzhl"
# include <stdarg.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct		s_option
{
	char			pluspace;
	char			minuszero;
	int				zero_nb;
	char			hash;
	char			modifier;
	int				padding;
	int				precision;
	int				state;
	unsigned int	*nb;
}					t_option;

/*
** PARSING
*/
int					ft_printf(const char *format, ...);
void				padding_and_precision(char *format, t_option *option);
void				initialize_option(t_option *option);
int					ft_is_in(char elem, char *src);
int					get_number(char *str);

/*
** CONVERT STRING
*/
int					ft_convert_string(va_list lst, t_option *option);
int					ft_display_flag_zero_str(t_option *option, char *str);

/*
** CONVERT CHAR (except UNICODE)
*/
int					ft_convert_char(va_list lst, t_option *option);
int					ft_other_char(va_list lst, t_option *option);

/*
** CONVERT INT (dDioOuUxX)
*/
int					ft_convert_hexa(t_option *option, char *tab, char *format);
int					ft_convert_octal(t_option *option, char *tab);
int					ft_convert_int(t_option *option, char *tab);
int					ft_convert_unsigned_int(t_option *option, char *tab);
char				*ft_lltoa_base_sign(long long value, int base, int sign);
char				*ft_lltoa_base_unsigned(unsigned long long value, int base,
	int upper_case, int sign);
char				*ft_itoa_base_printf(unsigned int value, int base,
	int upper_case, int sign);
int					ft_is_flag_minus_int(t_option *option, char *tab,
	int unsign);
int					display_precision_int(t_option *option, char *tab,
	int un_sign);
int					display_padding_and_precision_int(char *tab,
	t_option *option, int sign, int un_sign);

/*
** UNICODE
*/
int					ft_convert_long_char(va_list lst, t_option *option);
int					ft_convert_long_string(va_list lst, t_option *option);
void				ft_free_double_array(char **tab);
char				*ft_fill_binairy_mask(char *ptr, char *str, int len_str);
int					ft_display_padding_long_string(t_option *option, int len,
	int count);
char				*ft_convert_binairy_to_decimal(unsigned int value,
	int *count, int *i);
char				*ft_get_octet_each_long_char(t_option *option, char *tab,
	int *count, int *len);


int					conversion(char *format, t_option *option, va_list lst,
	...);

int					ft_percent(t_option *option);
int					ft_convert_pointer(va_list lst, t_option *option);

#endif
