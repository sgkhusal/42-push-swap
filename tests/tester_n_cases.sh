# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester_n_cases.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/05/06 01:42:32 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"
QTY_TESTS=100 # change the total of tests
n=100 # change the stack size

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
	seq 1 $n | shuf | tr '\n' ' ' > numbers
	printf "$PURPLE	Test $i: $GREY"
	cat numbers
	printf "\nTest $i: " >> log$n
	cat numbers >> log$n
	cat numbers | xargs ./push_swap > result
	cat result | grep OK
	RET=`cat result | wc -l | bc`
	printf "$BLUE"
	printf "\nTotal moves = $RET\n"
	printf "\nTotal moves = $RET\n" >> log$n
	i=$(($i + 1))
	SUM=$(($SUM + $RET))
done

printf "\nMedia = %.1f" "$(($SUM / $QTY_TESTS))"
printf "\nMedia = %.1f" "$(($SUM / $QTY_TESTS))" >> log$n
printf "\n$END"

rm numbers result
