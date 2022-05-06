# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker_error.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/05/06 01:03:47 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
GREEN="\033[0;32m"
END="\033[0m"

cd .. # change path to push_swap
make
make bonus

printf "\n"
printf "$YELLOW"
echo "****************** Checker error tests ******************"

printf "\n"
printf "$PURPLE"
echo "Test 1: invalid arguments"

ARG="Hello"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 1 2 3 5 + 0 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 1 2 3 5 - 0 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 b 2 3 5 1 0 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 2 3 Hello 1 0 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 4 \* 3 5 1 0 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 4 * 3 5 1 0 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 1 2 3 5 0 +++7 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 1 2 3 5 ---7 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 1 2 3 5 +-+7 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

ARG="10 1 2 3 5 -100+83 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 2: repeated number"
printf "$GREY"

ARG="10 1 2 3 5 0 1 9 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 3: number bigger than an integer"
printf "$GREY"

ARG="10 1 2 3 5 0 9 2147483648 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n"
printf "$PURPLE"
echo "Test 4: number smaller than an integer"
printf "$GREY"

ARG="10 1 2 3 5 0 9 -2147483649 8"
printf "\n$BLUE"
echo "./push_swap $ARG"
printf "$GREY"
printf "checker_linux result: \n"
./push_swap $ARG | ./checker_linux $ARG
printf "My checker result: \n"
./push_swap $ARG | ./checker $ARG

printf "\n$END"
