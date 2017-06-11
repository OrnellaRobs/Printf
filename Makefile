# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 21:49:20 by orazafin          #+#    #+#              #
#    Updated: 2017/06/11 21:04:11 by orazafin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_conversion.c\
		ft_convert_int.c\
		ft_convert_hexa.c\
		ft_convert_char.c\
		ft_convert_long_char.c\
		ft_convert_long_string.c\
		ft_convert_octal.c\
		ft_convert_pointer.c\
		ft_convert_string.c\
		ft_fill_binairy_mask.c\
		ft_get_number.c\
		ft_initialize_struct.c\
		ft_is_in.c\
		ft_itoa_base_printf.c\
		ft_lltoa_base_sign.c\
		ft_lltoa_base_unsigned.c\
		ft_percent.c\
		ft_parsing.c\
		ft_display_padding_long_string.c\
		ft_display_flag_zero_str.c\
		ft_display_minus_padding_precision_int.c\
		ft_get_padding_precision_into_struct.c\
		ft_convert_binairy_to_decimal_long_str.c\
		ft_free_double_array.c\
		ft_get_octet_each_long_char.c\

SRCDIR = ./srcs/

OBJ = $(SRC:.c=.o)

LIBSRC = 	ft_atoi_base.c\
			ft_strnew.c\
			ft_memalloc.c\
			ft_memset.c\
			ft_isdigit.c\
			ft_is_space.c\
 			ft_putstr_int.c\
 			ft_putchar_int.c\
			ft_strcpy.c\
			ft_strsub.c\
 			ft_strlen.c\
 			ft_strjoin.c\
			ft_strdup.c\
			ft_strsplit.c\
			ft_count_word.c\
			ft_itoa.c\
			ft_intlen.c\
			ft_strcmp.c\

LIBOBJ = $(LIBSRC:.c=.o)

CFLAGS = -g -Wall -Werror -Wextra

LIBDIR = ./Libft/
OBJDIR	= ./objs/
SRCDIR	= ./srcs/

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

LIBS = Libft/libft.a

all : $(NAME)

$(NAME) :
	@echo "\x1b[1m\x1b[36mCompiling library libft...\x1b[0m"
	@make -C Libft/ re
	@gcc $(CFLAGS) -I ./Libft/libft.h -I ft_printf.h -c $(SRCS)
	@ar rc $(NAME) $(OBJ) $(addprefix $(LIBDIR), $(LIBOBJ))
	@ranlib $(NAME)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)
	@ranlib $(NAME)
	@echo "\x1b[1m\x1b[34mLibrary libft compilation completed \x1b[1m\x1b[32m✔\x1b[0m"

clean :
	@echo "\x1b[1m\x1b[33mDeleting objects...\x1b[0m"
	@rm -rf objs
	@echo "\x1b[1m\x1b[32mDeleting done\x1b[0m"
	@make -C Libft/ clean

fclean : clean
	@rm -rf $(NAME)
	@echo "\x1b[1m\x1b[31mDeleting library...\x1b[0m"
	@make -C Libft/ fclean
	@echo "\x1b[1m\x1b[32mDeleting library done\x1b[0m"

re : fclean all
