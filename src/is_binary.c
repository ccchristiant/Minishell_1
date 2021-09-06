/*
** EPITECH PROJECT, 2021
** is_binary.c
** File description:
** is_binary
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

void exec_binary(char **cmd_line, char *tmp)
{
    int status = 0;
    int pid = fork();

    if (pid == 0) {
        status = execve(tmp, cmd_line, NULL);
        my_put_error(strerror(errno));
        my_put_error(".\n");
    }
    else {
        waitpid(-1, &status, 0);
        if (WIFSIGNALED(status)) {
            printf("%d\n", status);
            my_put_error(strsignal(WTERMSIG(status)));
            my_put_error(WCOREDUMP(status) ? " (core dumped)\n" : "\n");
        }
    }
}

int exist_executable_file(char *tmp)
{
    struct stat info;

    stat(tmp, &info);
    if (access(tmp, F_OK) == -1 || access(tmp, X_OK) == -1 ||
        !S_ISREG(info.st_mode))
        return (84);
    return (0);
}

void search_builtin_binary(char **cmd_line, char **paths)
{
    char *tmp = NULL;
    int tot_len = 0;

    for (int i = 0; paths[i]; i++) {
        tot_len = my_strlen(paths[i]) + my_strlen(cmd_line[0]) + 2;
        tmp = malloc(sizeof(char) * tot_len);
        tmp[0] = '\0';
        my_strcat(my_strcat(my_strcat(tmp, paths[i]), "/"), cmd_line[0]);
        if (exist_executable_file(tmp) == 0) {
            exec_binary(cmd_line, tmp);
            free(tmp);
            return;
        }
        free(tmp);
    }
    my_put_error(cmd_line[0]);
    my_put_error(": Command not found.\n");
}

void is_binary(char **cmd_line, char **paths)
{
    if (my_strncmp(cmd_line[0], "./", 2) == 0 ||
        my_strncmp(cmd_line[0], "/", 1) == 0) {
        if (exist_executable_file(cmd_line[0]) == 0)
            exec_binary(cmd_line, cmd_line[0]);
        else if (access(cmd_line[0], F_OK) == -1) {
            my_put_error(cmd_line[0]);
            my_put_error(": Command not found.\n");
        }
        else {
            my_put_error(cmd_line[0]);
            my_put_error(": ");
            my_put_error(strerror(errno));
            my_put_error(".\n");
        }
    }
    else
        search_builtin_binary(cmd_line, paths);
}