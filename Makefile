# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/07 21:41:41 by sguilher          #+#    #+#              #
#    Updated: 2022/04/08 04:43:48 by sguilher         ###   ########.fr        #
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

SRC_FILES =			push_swap.c
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

$(NAME):	$(LIBFT) $(PRINTF) $(OBJ) $(HEADER)
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

TESTS =	test0 test1 test2 test3 test4 test5 test8 test10 test100 test500
run:	$(TESTS)

test0:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 0.0: 0 numbers"
	@echo "\033[38;5;244m"
	./$(NAME)
	@echo "\033[1;35m"
	@echo "Test 0.1: numbers in order"
	@echo "\033[38;5;244m"
	seq 1 10 | tr '\n' ' ' | xargs | ./$(NAME)
	@echo "\033[1;35m"
	@echo "Test 0.2: invalid arguments"
	@echo "\033[38;5;244m"
	./$(NAME) 10 1 2 3 5 + 0 9 8
	./$(NAME) 10 1 2 3 5 - 0 9 8
	./$(NAME) 10 b 2 3 5 1 0 9 8
	./$(NAME) 10 4 * 3 5 1 0 9 8
	@echo "\033[1;35m"
	@echo "Test 0.3: repeated number"
	@echo "\033[38;5;244m"
	./$(NAME) 10 1 2 3 5 0 1 9 8
	@echo "\033[0m"

test1:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 1: 1 number"
	@echo "\033[38;5;244m"
	./$(NAME) 10

test2:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 2: 2 numbers"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	./$(NAME) 6 10
	@echo "\033[0m"

test3:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 3: 3 numbers, 1 to 3"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 3 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0m"

test4:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 4: 4 numbers, 1 to 4"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 4 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0m"

test5:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 5: 5 numbers, 1 to 5"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 5 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0m"

test8:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 8: 8 numbers, 1 to 8"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 8 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 8 | tr '\n' ' ' | shuf | xargs | ./$(NAME) | wc -l
	@echo "\033[0m"

test10:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 10: 10 numbers, 1 to 10"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 10 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 10 | tr '\n' ' ' | shuf | xargs | ./$(NAME) | wc -l
	@echo "\033[0m"

test100:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 100: 100 numbers, 1 to 100"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 100 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 100 | tr '\n' ' ' | shuf | xargs | ./$(NAME) | wc -l
	@echo "\033[0m"

test500:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 500: 500 numbers, 1 to 500"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 500 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 500 | tr '\n' ' ' | shuf | xargs | ./$(NAME) | wc -l
	@echo "\033[0m"

test1000:	$(NAME)
	@echo "\033[1;35m"
	@echo "Test 1000: 1000 numbers, 1 to 1000"
	@echo "\033[0;36m"
	@echo "Movements result:"
	@echo "\033[38;5;244m"
	seq 1 1000 | tr '\n' ' ' | shuf | xargs | ./$(NAME)
	@echo "\033[0;36m"
	@echo "Total movements: (different input!!)"
	@echo "\033[38;5;244m"
	seq 1 1000 | tr '\n' ' ' | shuf | xargs | ./$(NAME) | wc -l
	@echo "\033[0m"

$(LIBFT):
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
