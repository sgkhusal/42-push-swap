# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester_6_cases.sh                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <sguilher@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/04/21 21:21:38 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"

cd .. # change path to push_swap

rm log6

printf "\n"
printf "$YELLOW"
echo "****************** PUSH SWAP TESTER ******************"
echo "******************* stack size = 6 *******************"

i=1
SUM=0
RET=0

cat tests/6_cases | while read case6
do
	printf "$PURPLE\nTest $i:$GREY $case6"
	printf "\nTest $i: $case6" >> log6
	./push_swap $case6 > result
	#cat result
	RET=`cat result | wc -l | bc`
	printf "$BLUE\nTotal moves = $RET\n" 
	printf "\nTotal moves = $RET\n" >> log6
	i=$(($i + 1))
	SUM=$(($SUM + $RET))
done

printf "\nMedia = %.1f" "$(($SUM / $i))"
printf "\nMedia = %.1f" "$(($SUM / $i))" >> log6
printf "\n$END"

rm result
