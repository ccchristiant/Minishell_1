/*
** EPITECH PROJECT, 2021
** fetch_function.c
** File description:
** fetch_function
*/

#include "minishell.h"

void fetch_function(char **cmd_line, char ***env_c, char **paths)
{
    if (is_builtin(cmd_line, env_c) == 84)
        is_binary(cmd_line, paths);
}