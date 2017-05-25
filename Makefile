# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/23 17:05:09 by orazafin          #+#    #+#              #
#    Updated: 2017/05/25 16:56:50 by orazafin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_PATH = ./Libft/
LIBFT_NAME = libft.a

SRC	 = ft_convert_int.c\
				ft_convert_hexa.c\
				ft_convert_int.c\
				ft_conversion.c\
				ft_convert_char.c\
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

OBJ = $(SRC:.c=.o)

CC = gcc

FLAGS += -Wall -Wextra -Werror

all: $(NAME)

$(NAME):$(OBJ)
		@echo "Compile $(NAME) with $(FLAGS)$";
		@echo "ar rc $(NAME)"
		@ar rc $(NAME) $(OBJ)
		@echo "ranlib $(NAME)"
		@ranlib $(NAME)

clean:
		@echo "delete OBJ files"
		@rm -rf $(OBJ)

fclean: clean
		@echo "Delete $(NAME) file"
		@rm -rf $(NAME)

re: fclean all clean
