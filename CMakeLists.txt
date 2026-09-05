cmake_minimum_required(VERSION 4.3)
project(_c C)

set(CMAKE_C_STANDARD 11)

add_executable(_c main.c
        sort/sort.h
        sort/sort.c
)

add_executable(seq_list
        SeqList/seqList.c
)
