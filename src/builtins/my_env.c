/*
** EPITECH PROJECT, 2021
** my_env.c
** File description:
** env builtin function
*/

#include "my.h"

void my_env(__attribute__((unused)) char **cmd_line, char ***env_c)
{
    my_show_word_array((*env_c));
}