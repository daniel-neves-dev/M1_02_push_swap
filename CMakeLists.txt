cmake_minimum_required(VERSION 4.2)
project(push_swap C)

set(CMAKE_C_STANDARD 11)

add_library(push_swap STATIC
        push_swap.c
        push_swap.c
        push_swap.h
        op_swap.c
        op_swap.c
        op_swap.c
        op_rotation.c
        libft/ft_lstlast.c
        libft/ft_lstadd_back.c
        libft/ft_lstadd_front.c
        op_helpers.c
        op_reverse_rotation.c
        op_sorting.c
        op_sorting_big.c
        op_utils.c
        libft/ft_atoi.c)
