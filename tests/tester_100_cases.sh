# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    tester_100_cases.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sguilher <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/18 20:17:58 by sguilher          #+#    #+#              #
#    Updated: 2022/05/02 15:11:24 by sguilher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
BLUE="\033[0;36m"
END="\033[0m"

cd .. # change path to push_swap

rm log100

printf "\n"
printf "$YELLOW"
echo "****************** PUSH SWAP TESTER ******************"
echo "******************* stack size = 100 *******************"

i=1
RET=0

cat tests/100_cases | while read case100
do
	printf "$PURPLE\nTest $i:$GREY $case100"
	printf "\nTest $i: $case100" >> log100
	./push_swap $case100 > result
	cat result | grep OK
	RET=`cat result | wc -l | bc`
	printf "$BLUE\nTotal moves = $RET\n"
	printf "\nTotal moves = $RET\n" >> log100
	i=$(($i + 1))
done

printf "\n$END"

rm result
