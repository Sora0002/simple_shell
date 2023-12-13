#include "shell.h"
/**
 * displayP - a function to give the ability
 * to the user to write inside the cms
 *
 * Return: int;
 */
void displayP(void)
{
	char *s = "$ ";

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, s, 2);
}

/**
 * Reader - read a command line
 *
 * Return: char
 */
char *Reader(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread != -1)
	{
		return (line);
	}
	free(line), line = NULL;
	return (NULL);
}

/**
 * tokn - a tokenizer
 * @line: the command wich the user enter
 *
 * Return: array of commands
 */
char **tokn(char *line)
{
	char *t = NULL, *l, **cmds = NULL, d[] = "\t\n ";
	int counter = 0;

	if (!line)
		return (NULL);
	l = _strdup(line);
	t = strtok(l, d);
	if (!t)
	{
		free(line), line = NULL;
		free(l), l = NULL;
		return (NULL);
	}
	while (t)
	{
		counter++;
		t = strtok(NULL, d);
	}
	free(l), l = NULL;
	cmds = malloc(sizeof(char *) * (counter + 1));

	if (!cmds)
	{
		free(line), line = NULL;
		return (NULL);
	}

	t = strtok(line, d);
	counter = 0;
	while (t)
	{
		cmds[counter] = _strdup(t);
		t = strtok(NULL, d);
		counter++;
	}
	cmds[counter] = NULL;
	return (cmds);
}
/**
 * run_func - a function to execute a program
 * @c: the command
 * @argv: the arg value
 * @index: 0000
 *
 * Return: status
 */
int run_func(char **c, char **argv, int index)
{
	int s = 0, fv = 0, i;
	char *c2;

	c2 = verP(c[0]);
	if (!c2)
	{
		prr(argv[0], c[0], index);
		for (i = 0; c[i]; i++)
		{
			free(c[i]), c[i] = NULL;
		}
		free(c), c = NULL;
		return (127);
	}
	fv = fork();
	if (fv == 0)
	{
		if (execve(c2, c, environ))
		{
			perror(argv[0]);
			for (i = 0; c[i]; i++)
			{
				free(c[i]), c[i] = NULL;
			}
			free(c), c = NULL;
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(fv, &s, 0);
		for (i = 0; c[i]; i++)
		{
			free(c[i]), c[i] = NULL;
		}
		free(c2), c2 = NULL;
		free(c), c = NULL;
	}
	return (s);
}
