#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

testPassedContainer()
{
	# ft container test build
	sed -ie 's/#define STD 1/#define STD 0/g' ./config.hpp
	clang++ $1 -Wall -Werror -Wextra
	./a.out > ft_output
	# std container test build
	sed -ie 's/#define STD 0/#define STD 1/g' ./config.hpp
	clang++ $1 -Wall -Werror -Wextra
	./a.out > std_output 
	# checking the difference
	diff ft_output std_output > output_diff
	if [ -s output_diff ]
	then 
		echo -e "${RED}FAILED"
	else
		echo -e "${GREEN}OK"
	fi
	# setting files to the default condition
	sed -ie 's/#define STD 1/#define STD 0/g' ./config.hpp
	rm output_diff
	rm ft_output
	rm std_output
}

echo "*************     VECTOR TEST    ************"
testPassedContainer test_vector.cpp

echo -e "${NC}*************     STACK TEST     ************"
testPassedContainer test_stack.cpp

echo -e "${NC}*************      MAP TEST      ************"
testPassedContainer test_map.cpp

echo -e "${NC}*************      SET TEST      ************"
testPassedContainer test_set.cpp