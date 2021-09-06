/*
** EPITECH PROJECT, 2021
** struct.h
** File description:
** struct header
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include <stdarg.h>

//WRAPPER
struct match_printf {
    char c;
    void (*function)(va_list list);
};

typedef struct match_printf c_f;

struct match_minishell_1 {
    char *command;
    void (*function)(char **command_line, char ***env);
};

typedef struct match_minishell_1 command_matcher;

//LINKED LISTS
typedef struct linked_list_int
{
    int data;
    struct linked_list_int *next;
}linked_list_int_t;

typedef struct linked_list_str
{
    char *data;
    struct linked_list_str *next;
}linked_list_str_t;

#endif