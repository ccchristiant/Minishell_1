/*
** EPITECH PROJECT, 2021
** is_builtin.c
** File description:
** is_builtin function
*/

#include "my.h"
#include "struct.h"
#include "minishell.h"

static const command_matcher array[5] = {
    {"cd", &my_cd},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"env", &my_env},
    {"exit", &my_exit},
};

int is_builtin(char **cmd_line, char ***env_c)
{
    for (int i = 0; i < 5; i++)
        if (my_strcmp(cmd_line[0], array[i].command) == 0) {
            array[i].function(cmd_line, env_c);
            return (0);
        }
    return (84);
}