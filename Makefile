# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcollett <gcollett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/15 13:56:15 by gcollett          #+#    #+#              #
#    Updated: 2017/05/26 16:04:27 by orazafin         ###   ########.fr        #
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

SRCDIR = ./srcs/

OBJ = $(SRC:.c=.o)

LIBSRC = 	ft_atoi_base.c \
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

LIBOBJ = $(LIBSRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

LIBDIR = ./Libft/
OBJDIR	= ./objs/
SRCDIR	= ./srcs/

SRCS	= $(addprefix $(SRCDIR), $(SRC))
OBJS	= $(addprefix $(OBJDIR), $(OBJ))

LIBS = Libft/libft.a

RM = rm -f

all : $(NAME)

$(NAME) :
	@make -C Libft/ re
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation in progress..."
	@gcc $(GCC_FLAGS) -I ./Libft/libft.h -I ft_printf.h -c $(SRCS)
	@ar rc $(NAME) $(OBJ) $(addprefix $(LIBDIR), $(LIBOBJ))
	@ranlib $(NAME)
	@mkdir -p $(OBJDIR)
	@mv $(OBJ) $(OBJDIR)
	@ranlib $(NAME)
	@echo "\t\033[33;32m'MAKE' ->\t\033[1;34m$(NAME)\033[0m :\tLibrary compilation completed sucessfully !"

clean :
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the library \033[1;34m$(NAME)\033[0m"
	@rm -rf objs
	@echo "\t\033[1;31m'CLEAN' ->\tDestruction\033[0m:\tfiles .o for the library \033[1;34m$(NAME)\033[0m completed successfully !"
	@make -C libft/ clean

fclean : clean
	@$(RM) $(NAME)
	@echo "\t\033[1;31m'FCLEAN' ->\tDestruction\033[0m of library \033[1;34m$(NAME)\033[0m completed successfully !"
	@make -C libft/ fclean

re : fclean all

compile :
	@gcc $(CFLAGS) $(addprefix $(SRCDIR), $(SRC)) main.c Libft/libft.a -g

cc:
	@gcc -o test $(addprefix $(SRCDIR), $(SRC)) main.c Libft/libft.a -g

compexec : compile
	@./a.out

cexec : cc
	@./a.out
