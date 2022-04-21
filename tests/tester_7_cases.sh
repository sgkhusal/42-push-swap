# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester_7_cases.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/04/21 04:46:55 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"

cd .. # change path to push_swap

rm log7

printf "\n"
printf "$YELLOW"
echo "****************** PUSH SWAP TESTER ******************"
echo "******************* stack size = 7 *******************"

i=1
SUM=0
RET=0

cat tests/7_cases | while read case7
do
	printf "$PURPLE\nTest $i:$GREY $case7"
	printf "\nTest $i: $case7" >> log7
	./push_swap $case7 > result
	#cat result
	RET=`cat result | wc -l | bc`
	printf "$BLUE\nTotal moves = $RET\n" 
	printf "\nTotal moves = $RET\n" >> log7
	i=$(($i + 1))
	SUM=$(($SUM + $RET))
done

printf "\nMedia = %.1f" "$(($SUM / $i))"
printf "\nMedia = %.1f" "$(($SUM / $i))" >> log7
printf "\n$END"

rm result
