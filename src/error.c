/*
** EPITECH PROJECT, 2021
** error.c
** File description:
** error minishell 1
*/

int error(int ac, __attribute__((unused)) char **av)
{
    if (ac != 1)
        return (84);
    return (0);
}