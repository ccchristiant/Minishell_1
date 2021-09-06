/*
** EPITECH PROJECT, 2021
** my_unsetenv.c
** File description:
** unsetenv builtin function
*/

#include "my.h"
#include "stdlib.h"

void clean_env_c(char ***env_c, int i, int l_env_c)
{
    (*env_c)[i] = NULL;
    for (; i < l_env_c - 1; i++)
        str_swap(&(*env_c)[i], &(*env_c)[i + 1]);
}

void my_unsetenv(char **cmd_line, char ***env_c)
{
    int nb_arg = my_tab_length(cmd_line);
    int l_var = 0;
    int l_env_c = my_tab_length((*env_c));

    if (nb_arg == 2) {
        l_var = my_strlen(cmd_line[1]);
        for (int i = 0; (*env_c)[i]; i++)
            if (my_strncmp(cmd_line[1], (*env_c)[i], l_var) == 0) {
                clean_env_c(env_c, i, l_env_c);
                return;
            }
    }
    else
        my_put_error("unsetenv: Too many arguments.\n");
}
