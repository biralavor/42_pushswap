#!/bin/bash

GREEN='\033[0;32m'
NO_COLOR='\033[0m' # no color

cd program_to_test && \
make re
cd ../_ci_tdd && \
make
echo "" && \
echo -e "${GREEN}### SUCESS \o/ ###${NO_COLOR}"