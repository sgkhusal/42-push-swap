# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester_4_cases.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/04/19 23:01:21 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"

cd .. # change path to push_swap

rm log4

printf "\n"
printf "$YELLOW"
echo "****************** PUSH SWAP TESTER ******************"
echo "******************* stack size = 4 *******************"

i=1
SUM=0
RET=0

cat tests/4_cases | while read case4
do
	printf "$PURPLE\nTest $i:$GREY $case4"
	printf "\nTest $i: $case4" >> log4
	./push_swap $case4 > result
	cat result
	RET=`cat result | wc -l | bc`
	printf "$BLUE\nTotal moves = $RET\n" 
	printf "\nTotal moves = $RET\n" >> log4
	i=$(($i + 1))
	SUM=$(($SUM + $RET))
done

printf "\nMedia = %.1f" "$(($SUM / $i))"
printf "\nMedia = %.1f" "$(($SUM / $i))" >> log4
printf "\n$END"

rm result
