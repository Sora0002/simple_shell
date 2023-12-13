#include "shell.h"
/**
 * main - entry point
 * @argv: args values
 * @argc: args count
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int r = 0;
	int index = 1;
	(void)argc;

	while (1)
	{
		r = mergeF(argv, index, r);
		if (r == -1)
		{
			r = 0;
			continue;
		}
		index++;
	}
	return (WEXITSTATUS(r));
}
