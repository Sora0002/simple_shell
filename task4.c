#include "shell.h"

/**
 * freearr2 - free the array
 * @cmd: the command
 *
 * Return: void
 */
void freearr2(char **cmd)
{
	int i = 0;

	for (i = 0; cmd[i]; i++)
	{
		free(cmd[i]);
		cmd[i] = NULL;
	}
	free(cmd);
	cmd = NULL;
}

/**
 * checking - check if the function is build
 * @cmd: the command
 *
 * Return: int;
 */
int checking(char *cmd)
{
	char *b[] = {
		"cd", "exit", NULL};
	int i = 0;

	while (b[i])
	{
		if (_strcmp(b[i], cmd) == 0)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * hand - handle the buildin functions
 * @cmd: the command
 * @s: the status
 * @line: the line
 * @index: the index
 * @argv: the argv
 *
 * Return: rien
 */
void hand(char **argv, char **cmd, int s, char *line, int index)
{
	int a;

	if (checking(cmd[0]) == 1)
	{
		free(line), line = NULL;
		if (_strcmp(cmd[0], "exit") == 0)
		{
			if (cmd[1] == NULL)
			{
				freearr2(cmd);
				exit(WEXITSTATUS(s));
			}
			else
			{
				a = _atoi(cmd[1]);
				if (a < 0)
				{
					berr(argv[0], cmd[0], index, cmd[1]);
					freearr2(cmd);
					exit(2);
				}
				else if (a == 0 && cmd[1][0] != '0')
				{
					berr(argv[0], cmd[0], index, cmd[1]);
					freearr2(cmd);
					exit(2);
				}
				else
				{
					freearr2(cmd);
					exit(a);
				}
			}
		}
	}
}
