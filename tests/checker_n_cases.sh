# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    checker.sh                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/05/06 00:49:58 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
GREEN="\033[0;32m"
END="\033[0m"
QTY_TESTS=100 # change the total of tests
n=500 # change the stack size

cd .. # change path to push_swap

rm log$n

printf "\n"
printf "$YELLOW"
echo "****************** PUSH SWAP TESTER ******************"
echo "******************* stack size = $n *******************"
printf "\n"
i=1
SUM=0
RET=0
while [ $i -le $QTY_TESTS ]
do
	ARG=`seq 1 $n | shuf | tr '\n' ' '`
	printf "$PURPLE	Test $i:$GREY $ARG"
	printf "\nTest $i: $ARG" >> log$n
	./push_swap $ARG > result
	RET=`./push_swap $ARG | wc -l | bc`
	printf "$BLUE"
	printf "\nTotal moves = $RET\n"
	printf "\nTotal moves = $RET\n" >> log$n
	printf "checker_linux result: $GREEN"
	printf "checker_linux result: " >> log$n
	./push_swap $ARG | ./checker_linux $ARG
	./push_swap $ARG | ./checker_linux $ARG >> log$n
	printf "$BLUE"
	printf "My checker result: $GREEN"
	./push_swap $ARG | ./checker $ARG
	i=$(($i + 1))
	SUM=$(($SUM + $RET))
done

printf "\nMedia = %.1f" "$(($SUM / $QTY_TESTS))"
printf "\nMedia = %.1f" "$(($SUM / $QTY_TESTS))" >> log$n
printf "\n$END"
