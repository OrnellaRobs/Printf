# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/10 21:49:20 by orazafin          #+#    #+#              #
#    Updated: 2017/06/10 22:28:26 by orazafin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_convert_int.c\
		ft_convert_hexa.c\
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
		ft_display_padding_long_string.c\
		ft_display_flag_zero_str.c\
		get_padding_and_precision_into_struct.c\

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
	@echo "Compiling library libft..."
	@make -C Libft/ re
	@gcc $(CFLAGS) -I ./Libft/libft.h -I ft_printf.h -c $(SRCS)
	@ar rc $(NAME) $(OBJ) $(addprefix $(LIBDIR), $(LIBOBJ))
	@ranlib $(NAME)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)
	@ranlib $(NAME)
	@echo "Library libft compilation completed"

clean :
	@echo "Deleting objects..."
	@rm -rf objs
	@echo "Deleting done!"
	@make -C Libft/ clean

fclean : clean
	@rm -rf $(NAME)
	@echo "Deleting library"
	@make -C Libft/ fclean
	@echo "Deleting library done"

re : fclean all
