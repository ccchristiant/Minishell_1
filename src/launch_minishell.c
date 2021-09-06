/*
** EPITECH PROJECT, 2021
** launch_minishell.c
** File description:
** launch minishell
*/

#include "my.h"
#include "minishell.h"
#include <stdio.h>

void launch_minishell(char **env_c)
{
    input_t input = init_input();
    char **cmd_line = NULL;
    char *env_path = my_getenv("PATH", env_c);
    char **paths = my_str_to_word_array_delim(env_path, ':');

    while (1) {
        choose_prompt(env_c);
        input.nbr_char = getline(&input.buf, &input.len, stdin);
        if (input.nbr_char == -1)
            my_exit(cmd_line, &env_c);
        if (input.nbr_char > 1) {
            input.buf[input.nbr_char - 1] = '\0';
            cmd_line = my_str_to_word_array(input.buf);
            fetch_function(cmd_line, &env_c, paths);
        }
    }
}