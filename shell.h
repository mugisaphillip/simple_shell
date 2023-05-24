#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/wait.h>

void _putchar(char c);
void _puts(char *str);
void execute(char *progName, char **args, char **envp);
void location(char **args);
void handleExit(char *prompt, char **args);
ssize_t _getline(char **lineptr, size_t *n);
int _atoi(char *s);
int handleChangeDir(char **args);

#endif
