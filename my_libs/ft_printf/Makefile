# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/04 17:01:10 by sguilher          #+#    #+#              #
#    Updated: 2022/04/20 22:48:04 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# creates libftprintf.a library

NAME =			libftprintf.a

HEADER =		ft_printf.h

SRC_PATH =		./src
OBJ_PATH =		./obj
SRC_FILES =		1_ft_printf.c \
				2_ft_printf_flags.c \
				3_ft_printf_specifiers.c \
				4_ft_printf_char.c \
				5_ft_printf_integer.c \
				5_ft_printf_itoa.c \
				6_ft_printf_hex.c  \
				6_ft_printf_itohex.c \
				7_ft_printf_pointer.c \
				ft_printf_utils.c

SRC =		$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ =		$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)

INCLUDES =	-I./ -I../libft

# compilation
CC =		gcc
CFLAGS = 	-Wall -Werror -Wextra

# clean
RM =		-rm -f
RM_DIR =	rm -rf

# rules
all:	$(NAME)

bonus:	$(NAME)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

$(NAME):	$(OBJ)
	@ar rc $@ $(OBJ)
	@ranlib $@

clean:
	@$(RM) $(OBJ)
	@$(RM_DIR) $(OBJ_PATH)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
