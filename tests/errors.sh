# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    errors.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/15 02:07:42 by sguilher          #+#    #+#              #
#    Updated: 2022/05/06 01:42:00 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"

cd ..
make

printf "\n"
printf "$YELLOW"
echo "****************** Error tests ******************"

printf "\n"
printf "$PURPLE"
echo "Test 1: invalid arguments"
printf "$GREY"

printf "\n"
echo "./push_swap Hello"
./push_swap Hello

printf "\n"
echo "./push_swap 10 1 2 3 5 + 0 9 8"
./push_swap 10 1 2 3 5 + 0 9 8

printf "\n"
echo "./push_swap 10 1 2 3 5 - 0 9 8"
./push_swap 10 1 2 3 5 - 0 9 8

printf "\n"
echo "./push_swap 10 b 2 3 5 1 0 9 8"
./push_swap 10 b 2 3 5 1 0 9 8

printf "\n"
echo "./push_swap 10 2 3 Hello 1 0 9 8"
./push_swap 10 2 3 Hello 1 0 9 8

printf "\n"
echo "./push_swap 10 4 \* 3 5 1 0 9 8"
./push_swap 10 4 \* 3 5 1 0 9 8

printf "\n"
echo "./push_swap 10 4 * 3 5 1 0 9 8"
./push_swap 10 4 * 3 5 1 0 9 8

printf "\n"
echo "./push_swap 10 1 2 3 5 0 +++7 9 8"
./push_swap 10 1 2 3 5 0 +++7 9 8

printf "\n"
echo "./push_swap 10 1 2 3 5 ---7 9 8"
./push_swap 10 1 2 3 5 ---7 9 8

printf "\n"
echo "./push_swap 10 1 2 3 5 +-+7 9 8"
./push_swap 10 1 2 3 5 +-+7 9 8

printf "\n"
echo "./push_swap 10 1 2 3 5 -100+83 9 8"
./push_swap 10 1 2 3 5 -100+83 9 8

printf "\n"
printf "$PURPLE"
echo "Test 2: repeated number"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 0 1 9 8"
./push_swap 10 1 2 3 5 0 1 9 8

printf "\n"
printf "$PURPLE"
echo "Test 3: number bigger than an integer"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 0 9 2147483648 8"
./push_swap 10 1 2 3 5 0 9 2147483648 8

printf "\n"
printf "$PURPLE"
echo "Test 4: number smaller than an integer"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 0 9 -2147483649 8"
./push_swap 10 1 2 3 5 0 9 -2147483649 8

printf "\n$END"
