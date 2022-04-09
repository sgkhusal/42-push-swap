#!/bin/bash

YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[1;35m"
END="\033[0m"

cd ..
make

printf "\n"
printf "$YELLOW"
echo "****************** Error tests ******************"

printf "\n"
printf "$PURPLE"
echo "Test 1: invalid arguments"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 + 0 9 8"
./push_swap 10 1 2 3 5 + 0 9 8

printf "\n"
echo "./push_swap 10 1 2 3 5 - 0 9 8"
./push_swap 10 1 2 3 5 - 0 9 8

printf "\n"
echo "./push_swap 10 b 2 3 5 1 0 9 8"
./push_swap 10 b 2 3 5 1 0 9 8

printf "\n"
echo "./push_swap 10 4 \* 3 5 1 0 9 8"
./push_swap 10 4 \* 3 5 1 0 9 8

printf "\n"
echo "./push_swap 10 4 * 3 5 1 0 9 8"
./push_swap 10 4 * 3 5 1 0 9 8

printf "\n"
printf "$PURPLE"
echo "Test 2: repeated number"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 0 1 9 8"
./push_swap 10 1 2 3 5 0 1 9 8

printf "\n"
printf "$PURPLE"
echo "Test 3: number bigger than an integer"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 0 2147483648 9 8"
./push_swap 10 1 2 3 5 0 2147483648 9 8

printf "\n"
printf "$PURPLE"
echo "Test 4: number lesser than an integer"
printf "$GREY"

printf "\n"
echo "./push_swap 10 1 2 3 5 0 -2147483649 9 8"
./push_swap 10 1 2 3 5 0 -2147483649 9 8

printf "\n"
printf "$END"
