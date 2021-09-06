/*
** EPITECH PROJECT, 2021
** minishell.h
** File description:
** minishell 1 header
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

#include <sys/types.h>

typedef struct input
{
    char *buf;
    size_t len;
    ssize_t nbr_char;
} input_t;

typedef struct setenv_arguments_length
{
    int l_var;
    int l_val;
} l_setenv;

int error(int ac, char **av);
char **copy_tab(char **tab);
void launch_minishell(char **env_c);
void choose_prompt(char **env_c);
input_t init_input(void);
char *my_getenv(char *env_var, char **env_c);
void my_cd(char **cmd_line, char ***env_c);
void my_setenv(char **cmd_line, char ***env_c);
void my_unsetenv(char **cmd_line, char ***env_c);
void my_env(char **cmd_line, char ***env_c);
void my_exit(char **cmd_line, char ***env_c);
void fetch_function(char **cmd_line, char ***env_c, char **paths);
int is_builtin(char **cmd_line, char ***env_c);
void is_binary(char **cmd_line, char **paths);

#endif