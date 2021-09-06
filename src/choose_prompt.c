/*
** EPITECH PROJECT, 2021
** choose_prompt.c
** File description:
** choose prompt with current dir
*/

#include "my.h"
#include "minishell.h"
#include <stdlib.h>

char *current_dir(char *pwd)
{
    int i = my_strlen(pwd) - 1;

    for (; pwd[i] != '/'; i--);
    return (&pwd[i + 1]);
}

void choose_prompt(char **env_c)
{
    if (my_getenv("USER", env_c) == NULL)
        my_printf("$> ");
    else {
        my_printf("[%s ", my_getenv("USER", env_c));
        my_printf("%s]$> ", current_dir(my_getenv("PWD", env_c)));
    }
}