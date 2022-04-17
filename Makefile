# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 21:41:41 by sguilher          #+#    #+#              #
#    Updated: 2022/04/17 02:38:41 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =					push_swap
#BONUS =					checker

# **************************************************************************** #
# MY LIBRARIES - libft.a and libftprintf.a

LIBFT_PATH =	./my_libs/libft/
PRINTF_PATH =	./my_libs/ft_printf/

LIBFT =			$(LIBFT_PATH)libft.a
PRINTF =		$(PRINTF_PATH)libftprintf.a

LIBS =			-L $(LIBFT_PATH) -lft -L $(PRINTF_PATH) -lftprintf

# **************************************************************************** #

# INPUTS
#VPATH =		src bonus headers

SRC_PATH =			src
OBJ_PATH =			obj
#SRC_BONUS_PATH =	bonus
#OBJ_BONUS_PATH =	obj/bonus
HEADER_PATH =		headers
INCLUDES =	-I $(LIBFT_PATH) -I $(PRINTF_PATH) -I $(HEADER_PATH)

SRC_FILES =			1_main.c 2_push_swap_init.c 3_push_swap_check_args.c \
					4_push_swap_1.c \
					push_swap_mov_1.c push_swap_mov_2.c \
					push_swap_utils_1.c push_swap_utils_2.c \
					clean.c \
					tests.c tests_mov.c
#SRC_BONUS_FILES =	
HEADER_FILES =		push_swap.h

SRC =				$(addprefix $(SRC_PATH)/, $(SRC_FILES))
OBJ =				$(SRC:$(SRC_PATH)/%.c=$(OBJ_PATH)/%.o)
HEADER =			$(addprefix $(HEADER_PATH)/, $(HEADER_FILES))

#SRC_BONUS =			$(addprefix $(SRC_BONUS_PATH)/, $(SRC_BONUS_FILES))
#OBJ_BONUS =			$(SRC_BONUS:$(SRC_BONUS_PATH)/%.c=$(OBJ_BONUS_PATH)/%.o)

# **************************************************************************** #

# compilation
CC =		gcc
CFLAGS =	-Wall -Werror -Wextra #-g3 -fsanitize=leak

# clean
RM =		-rm -f
RM_DIR =	-rm -rf

# **************************************************************************** #
# rules

all:	$(NAME)

bonus:	$(BONUS)

$(OBJ_PATH)/%.o:	$(SRC_PATH)/%.c $(HEADER)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

#$(OBJ_BONUS_PATH)/%.o:	$(SRC_BONUS_PATH)/%.c $(HEADER)
#	@mkdir -p $(OBJ_BONUS_PATH)
#	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(PRINTF) $(OBJ) $(OBJ_TEST) $(HEADER) ##########
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(PRINTF) $(LIBFT)
	@echo "\033[1;32m"
	@echo "************************************"
	@echo "           push_swap created"
	@echo "************************************"
	@echo "\033[0m"

#$(BONUS):	$(LIBFT) $(PRINTF) $(OBJ_BONUS) $(HEADER)
#	$(CC) $(CFLAGS) -o $@ $(OBJ_BONUS) $(PRINTF) $(LIBFT)
#	@echo "\033[1;32m"
#	@echo "************************************"
#	@echo "           checker created"
#	@echo "************************************"
#	@echo "\033[0m"

TESTS =	test0 test10 test100 test500
#run:	$(TESTS)
run:	test0 test10

test0:	$(NAME)
	cd tests && ./tester.sh

test10:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 10: 10 numbers, 1 to 10"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 10 | shuf | tr '\n' ' ' | xargs ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 10 | shuf | tr '\n' ' ' | xargs ./$(NAME) | wc -l
	@echo "\033[0m"

test100:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 100: 100 numbers, 1 to 100"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 100 | shuf | tr '\n' ' ' | xargs ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 100 | shuf | tr '\n' ' ' | xargs ./$(NAME) | wc -l
	@echo "\033[0m"

test500:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 500: 500 numbers, 1 to 500"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 500 | shuf | tr '\n' ' ' | xargs ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 500 | shuf | tr '\n' ' ' | xargs ./$(NAME) | wc -l
	@echo "\033[0m"

test1000:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 1000: 1000 numbers, 1 to 1000"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 1000 | shuf | tr '\n' ' ' | xargs ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 1000 | shuf | tr '\n' ' ' | xargs ./$(NAME) | wc -l
	@echo "\033[0m"

$(LIBFT): $(LIBFT_PATH)libft.h
	cd $(LIBFT_PATH) && $(MAKE)
	@echo "libft.a created"

$(PRINTF):
	cd $(PRINTF_PATH) && $(MAKE)
	@echo "libftprintf.a created"

clean:
		@$(RM_DIR) $(OBJ_PATH)

fclean:		clean
		@$(RM) $(NAME)
		@$(RM) $(BONUS)

re:			fclean all

reb:		fclean bonus

reall:		fcleanlib fclean all bonus

cleanlib:	
	@cd $(PRINTF_PATH) && $(MAKE) clean
	@cd $(LIBFT_PATH) && $(MAKE) clean

fcleanlib:
	@cd $(PRINTF_PATH) && $(MAKE) fclean
	@cd $(LIBFT_PATH) && $(MAKE) fclean

.PHONY: all clean fclean re reb reall cleanlib fcleanlib run $(TESTS)
