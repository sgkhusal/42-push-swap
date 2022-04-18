# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 21:44:15 by sguilher          #+#    #+#              #
#    Updated: 2022/04/17 18:40:59 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"

./errors.sh

cd ..

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
echo "./push_swap 1 2 3"
./push_swap 1 2 3

printf "\n"
echo "./push_swap 1 3 2"
./push_swap 1 3 2

printf "\n"
echo "./push_swap 2 1 3"
./push_swap 2 1 3

printf "\n"
echo "./push_swap 2 3 1"
./push_swap 2 3 1

printf "\n"
echo "./push_swap 3 1 2"
./push_swap 3 1 2

printf "\n"
echo "./push_swap 3 2 1"
./push_swap 3 2 1

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
echo "Test 10.3: 4 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 2 1 4 3"
./push_swap 2 1 4 3
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 2 1 4 3 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 10.4: 4 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 3 2 4 1"
./push_swap 3 2 4 1
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 3 2 4 1 | wc -l

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
echo "Test 12: 6 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 8 20 12 32 42 10"
./push_swap 8 20 12 32 42 10
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 8 20 12 32 42 10 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 13.1: 7 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 8 20 12 32 42 10 25"
./push_swap 8 20 12 32 42 10 25
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 8 20 12 32 42 10 25 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 13.2: 7 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

printf "\n"
echo "./push_swap 8 20 12 25 42 10 32"
./push_swap 8 20 12 25 42 10 32
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 8 20 12 25 42 10 32 | wc -l

printf "\n"
printf "$PURPLE"
echo "Test 14: 8 numbers"
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
echo "Test 15: 000000"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 000000 9 8"
./push_swap 10 1 2 3 5 000000 9 8
printf "$BLUE"
printf "\n"
echo "Total movements:"
printf "$GREY"
./push_swap 10 1 2 3 5 000000 9 8 | wc -l

printf "\n"
printf "$END"
