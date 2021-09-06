/*
** EPITECH PROJECT, 2021
** my_setenv.c
** File description:
** setenv builtin function
*/

#include "my.h"
#include "minishell.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void env_var_and_value(char **cmd_line, char **env_c, l_setenv args, int i)
{
    int total_len = args.l_var + args.l_val + 2;

    env_c[i] = malloc(sizeof(char) * total_len);
    env_c[i][0] = '\0';
    my_strcat(env_c[i], cmd_line[1]);
    my_strcat(env_c[i], "=");
    if (args.l_val != 0)
        my_strcat(env_c[i], cmd_line[2]);
}

void new_env_var(char **cmd_line, char ***env_c, l_setenv args, int len_env_c)
{
    char **new_env_c = NULL;

    new_env_c = malloc(sizeof(char*) * (len_env_c + 2));
    for (int i = 0; i < len_env_c; i++)
        new_env_c[i] = my_strdup((*env_c)[i]);
    env_var_and_value(cmd_line, new_env_c, args, len_env_c);
    new_env_c[len_env_c + 1] = NULL;
    free_double_tab((*env_c));
    *env_c = new_env_c;
}

void init_args(l_setenv *args, char **cmd_line, int nb_arg)
{
    (*args).l_var = my_strlen(cmd_line[1]);
    (*args).l_val = (nb_arg == 3) ? my_strlen(cmd_line[2]) : 0;
}

void my_setenv(char **cmd_line, char ***env_c)
{
    int len_env_c = my_tab_length((*env_c));
    int nb_arg = my_tab_length(cmd_line);
    l_setenv args;

    if (nb_arg == 2 || nb_arg == 3) {
        init_args(&args, cmd_line, nb_arg);
        for (int i = 0; (*env_c)[i]; i++) {
            if (my_strncmp(cmd_line[1], (*env_c)[i], args.l_var) == 0) {
                free((*env_c)[i]);
                env_var_and_value(cmd_line, (*env_c), args, i);
                return;
            }
        }
        new_env_var(cmd_line, env_c, args, len_env_c);
    }
    else
        my_put_error("setenv: Too many arguments.\n");
}
