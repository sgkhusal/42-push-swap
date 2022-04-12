# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 21:44:15 by sguilher          #+#    #+#              #
#    Updated: 2022/04/11 22:18:51 by sguilher         ###   ########.fr        #
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

###############################################################################
printf "\n"
printf "$YELLOW"
echo "****************** Valid arguments ******************"

printf "\n"
printf "$PURPLE"
echo "Test 5: no input"
printf "$GREY"

printf "\n"
echo "./push_swap"
./push_swap

printf "\n"
printf "$PURPLE"
echo "Test 6: numbers in order - no error"
printf "$GREY"

printf "\n"
echo "./push_swap 0 1 2 3 4 5 6 7 8 9"
./push_swap 0 1 2 3 4 5 6 7 8 9

printf "\n"
echo "./push_swap -9 -8 -7 -6 -5 -4 -3 -2 -1 0"
./push_swap -9 -8 -7 -6 -5 -4 -3 -2 -1 0

printf "\n"
echo "seq 1 100 | tr '\\n' ' ' | xargs ./push_swap"
seq 1 100 | tr '\n' ' ' | xargs ./push_swap

printf "\n"
printf "$PURPLE"
echo "Test 7: only one number"
printf "$GREY"

printf "\n"
echo "./push_swap 42"
./push_swap 42

printf "\n"
printf "$PURPLE"
echo "Test 8: 2 numbers"
printf "$GREY"

printf "\n"
echo "./push_swap 42 -42"
./push_swap 42 -42

printf "\n"
printf "$PURPLE"
echo "Test 9: 3 numbers"
printf "$GREY"

printf "\n"
echo "./push_swap 2 1 3"
./push_swap 2 1 3

printf "\n"
printf "$PURPLE"
echo "Test 10.1: 4 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 3 26 6 1"
./push_swap 3 26 6 1
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 3 26 6 1 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 10.2: 4 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 50 21 25 9"
./push_swap 50 21 25 9
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 50 21 25 9 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 11: 5 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 8 20 12 32 42"
./push_swap 8 20 12 32 42
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 8 20 12 32 42 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 11: 8 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 7 2 1 5 3 8 4 6"
./push_swap 7 2 1 5 3 8 4 6
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 7 2 1 5 3 8 4 6 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 12: 000000"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 000000 9 8"
./push_swap 10 1 2 3 5 000000 9 8

printf "\n"
printf "$END"
