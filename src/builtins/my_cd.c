/*
** EPITECH PROJECT, 2021
** my_cd.c
** File description:
** cd builtin function
*/

#include "my.h"
#include "minishell.h"
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

void my_cd_home(char ***env_c, char *upd_oldpwd[])
{
    char *home = my_getenv("HOME", (*env_c));
    char *no_arg_pwd[4] = {"setenv", "PWD", home, NULL};

    chdir(home);
    my_setenv(upd_oldpwd, env_c);
    my_setenv(no_arg_pwd, env_c);
}

void my_cd_2_arg(char **cmd_line, char ***env_c, char *upd_oldpwd[])
{
    char *arg_pwd[4] = {"setenv", "PWD", NULL, NULL};
    char *oldpwd = my_getenv("OLDPWD", (*env_c));

    if ((my_strcmp(cmd_line[1], "-") == 0 && chdir(oldpwd) == 0) ||
        (chdir(cmd_line[1]) == 0)) {
        arg_pwd[2] = getcwd(NULL, 0);
        my_setenv(upd_oldpwd, env_c);
        my_setenv(arg_pwd, env_c);
    }
    else {
        my_put_error(cmd_line[1]);
        my_put_error(": ");
        my_put_error(strerror(errno));
        my_put_error(".\n");
    }
}

void my_cd(char **cmd_line, char ***env_c)
{
    int nb_arg = my_tab_length(cmd_line);
    char *pwd = my_getenv("PWD", (*env_c));
    char *upd_oldpwd[4] = {"setenv", "OLDPWD", pwd, NULL};

    if (nb_arg == 1)
        my_cd_home(env_c, upd_oldpwd);
    else if (nb_arg == 2 && my_strcmp(cmd_line[1], ".") != 0)
        my_cd_2_arg(cmd_line, env_c, upd_oldpwd);
    else
        my_put_error("cd: Too many arguments.\n");
}