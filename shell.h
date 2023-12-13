#ifndef SHELL_H
#define SHELL_H
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
/* buffers size */
#define buf_size 1024
extern char **environ;

void displayP(void);
char *_strdup(const char *str);
int _strlen(char *str);
void exeP(char *c);
char *Reader(void);
int mergeF(char **argv, int index, int s);
char **tokn(char *line);
int run_func(char **c, char **argv, int index);
int _strcmp(const char *str1, const char *str2);
char *_getenv(char *key);
char *_strcat(char *dest, const char *src);
char *verP(char *command);
char *_strcpy(char *dest, const char *src);
char *_itoa(int num, char *str, int base);
void prr(char *argv, char *cmd, int index);
void hand(char **argv, char **cmd, int s, char *line, int index);
int checking(char *cmd);
int _atoi(char *s);
void berr(char *argv, char *cmd, int index, char *s);
void freearr2(char **cmd);
#endif
