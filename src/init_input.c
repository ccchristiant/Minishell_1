/*
** EPITECH PROJECT, 2021
** init_input.c
** File description:
** init input
*/

#include "minishell.h"
#include <stdlib.h>

input_t init_input(void)
{
    input_t input;

    input.buf = NULL;
    input.len = 0;
    input.nbr_char = 0;
    return (input);
}
