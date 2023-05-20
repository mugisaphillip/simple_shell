#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

void _putchar(char c);
void _puts(char *str);
void execute(char *progName, char **args, char **envp);

#endif
