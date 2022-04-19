# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester_n_cases.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/04/18 22:35:14 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"
QTY_TESTS=100 # change the total of tests
n=5 # change the stack size

cd .. # change path to push_swap

rm log$n

printf "\n"
printf "$YELLOW"
echo "****************** PUSH SWAP TESTER ******************"
echo "******************* stack size = $n *******************"

i=1
SUM=0
RET=0
MED=0
while [ $i -le $QTY_TESTS ]
do
	seq 1 $n | shuf | tr '\n' ' ' > numbers
	printf "$PURPLE\nTest $i: "
	printf "\nTest $i: " >> log$n
	printf "$GREY"
	cat numbers
	cat numbers >> log$n
	cat numbers | xargs ./push_swap > result
	#cat result
	printf "$BLUE\nTotal moves = " 
	printf "\nTotal moves = " >> log$n
	cat result | wc -l
	RET=`cat result | wc -l | bc`
	cat result | wc -l >> log$n
	i=$(($i + 1))
	SUM=$(($SUM + $RET))
done

printf "\n"
MED=$(($SUM / $QTY_TESTS))
printf "Media = $MED\n"
printf "\n$END"

rm numbers result
