#ifndef SHELL_H
#define SHELL_H
/* Libraries used */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
/* Global variable */
extern char **environ;
/*i/o functions prototypes */
int _putchar(char c);
void _puts(char *s);
ssize_t input_str(void);
char **get_tokens(char *, char *);
void execute_command(char **);
int _strlen(char *);
char *_strcpy(char *, char *);
int _strcmp(char *, char *);
char *get_cmd_location(char *);
char *_strcat(char *, char *);
char *_strdup(char *);
#endif

