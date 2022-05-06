# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker_tester.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/11 21:44:15 by sguilher          #+#    #+#              #
#    Updated: 2022/05/06 01:15:05 by sguilher         ###   ########.fr        #
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
echo "Test 1: no input"
printf "$GREY"

printf "\n$BLUE"
echo "./push_swap"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap | ./checker_linux
printf "My checker result: \n"
./push_swap | ./checker

printf "\n"
printf "$PURPLE"
echo "Test 2: numbers in order - no error"
printf "$GREY"

ARG="0 1 2 3 4 5 6 7 8 9"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="-9 -8 -7 -6 -5 -4 -3 -2 -1 0"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 3: only one number"
printf "$GREY"

ARG="42"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG


printf "\n"
printf "$PURPLE"
echo "Test 4: 2 numbers"
printf "$GREY"

ARG="42 -42"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 5: 3 numbers"
printf "$GREY"

ARG="2 1 3"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 6: 4 numbers"
printf "\n"
printf "$GREY"

ARG="3 26 6 1"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 7: 5 numbers"
printf "\n"
printf "$GREY"

ARG="8 20 12 32 42"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 8: 6 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

ARG="8 20 12 32 42 10"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 9: 7 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

ARG="8 20 12 32 42 10 25"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 10: 8 numbers"
printf "\n"
printf "$BLUE"
echo "Movements result:"
printf "$GREY"

ARG="7 2 1 5 3 8 4 6"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 11: 000000"
printf "$GREY"

ARG="10 1 2 3 5 000000 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$END"
