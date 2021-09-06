/*
** EPITECH PROJECT, 2021
** my_exit.c
** File description:
** exit builtin function
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>

void my_exit(char **cmd_line, char ***env_c)
{
    free_double_tab((*env_c));
    if (!cmd_line)
        exit(84);
    free_double_tab(cmd_line);
    exit(0);
}