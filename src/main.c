/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main minishell 1
*/

#include "my.h"
#include "minishell.h"

int main(int ac, char **av, char **env)
{
    if (error(ac, av) == 84)
        return (84);
    launch_minishell(copy_tab(env));
}