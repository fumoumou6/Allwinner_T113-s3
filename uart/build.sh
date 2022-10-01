#!/bin/bash

make clean

make 

make install
# ./mksunxiboot ledc.bin ledc

# sudo dd if=./ledc of=/dev/mmcblk0 bs=8k seek=1

# sync

# make clean