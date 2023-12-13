#include "shell.h"
/**
 * mergeF - function to call all the oter functions
 * @argv: args val
 * @index: ...
 * @s: ...
 * Return: int
*/
int mergeF(char **argv, int index, int s)
{
	char *line = NULL, **cmd = NULL;

	displayP();
	line = Reader();
	if (!line)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(line), line = NULL;
		exit(WEXITSTATUS(s));
	}
	cmd = tokn(line);
	if (!cmd)
	{
		return (-1);
	}

	hand(argv, cmd, s, line, index);
	s = run_func(cmd, argv, index);

	free(line), line = NULL;
	return (s);
}
