# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 17:05:09 by orazafin          #+#    #+#              #
#    Updated: 2017/05/25 10:44:30 by orazafin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

NAME_LIB = Libft/libft.a

SRCS_FT_PRINTF = ft_convert_int.c\
				ft_convert_hexa.c\
				ft_convert_int.c\
				ft_conversion.c\
				ft_convert_int_padd_prec.c\
				ft_convert_long_char.c\
				ft_convert_long_string.c\
				ft_convert_octal.c\
				ft_convert_pointer.c\
				ft_convert_string.c\
				ft_fill_mask.c\
				ft_get_number.c\
				ft_initialize_option.c\
				ft_is_in.c\
				ft_itoa_base_printf.c\
				ft_lltoa_base_sign.c\
				ft_lltoa_base_unsigned.c\
				ft_percent.c\
				ft_printf.c\

FLAGS += -Wall -Wextra -Werror

OBJS_FT_PRINTF = (SRCS_FT_PRINTF:.c=.o)

all : $(NAME)

$(NAME):
	@echo "compiling ft_printf..."
	@make -C Libft
	@gcc $(FLAGS) $(SRCS_FT_PRINTF) -o $(NAME) Libft/libft.a  -I ft_printf.h
	@echo "ft_printf done"

clean :
	@echo "deleting objects..."
	@make -C libft clean
	@echo "deleting done"

fclean : clean
	@echo "deleting library and ft_printf..."
	@make -C Libft fclean
	@rm -f $(NAME)
	@echo "deleting done"

re : fclean all
