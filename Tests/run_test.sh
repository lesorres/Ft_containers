#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'

#test vector
echo "*************       Vector test     ************"

# ft containers test build
sed -ie 's/#define STD 1/#define STD 0/g' ./config.hpp
clang++ test_vector.cpp
./a.out > ft_output

# std containers test build
sed -ie 's/#define STD 0/#define STD 1/g' ./config.hpp
clang++ test_vector.cpp
./a.out > std_output

# checking the difference
diff ft_output std_output > output_diff

if [ -s output_diff ]
then 
	echo -e "${RED}FAILED"
else
	echo -e "${GREEN}OK"
fi