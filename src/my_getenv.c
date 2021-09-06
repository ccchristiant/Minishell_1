/*
** EPITECH PROJECT, 2021
** my_getenv.c
** File description:
** getenv function
*/

#include "my.h"
#include <stddef.h>

char *my_getenv(char *env_var, char **env_c)
{
    int len_env_var = my_strlen(env_var);

    for (int i = 0; env_c[i]; i++) {
        if (my_strncmp(env_var, env_c[i], len_env_var) == 0)
            return (&env_c[i][len_env_var + 1]);
    }
    return NULL;
}