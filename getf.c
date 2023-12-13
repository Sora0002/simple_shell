#include "shell.h"

/**
 * _getenv - function to get environment
 * @key: the key to get the env
 *
 * Return: env
 */
char *_getenv(char *key)
{
	char *cle, *v, *a, *t;
	int i = 0;

	while (environ[i])
	{
		t = strdup(environ[i]);
		cle = strtok(t, "=");
		if (cle != NULL && strcmp(cle, key) == 0)
		{
			v = strtok(NULL, "=");
			if (v != NULL)
			{
				a = strdup(v);
				free(t);
				return (a);
			}
		}
		free(t);
		i++;
	}
	return (NULL);
}

/**
 * verP - verify if a command exists in the PATH
 * @command: the command to verify
 *
 * Return: char
 */
char *verP(char *command)
{
	char *fp, *vp, *fc;
	struct stat buf;
	int i = 0;

	while (command[i])
	{
		if (command[i] == '/')
		{
			if (stat(command, &buf) == 0)
				return (_strdup(command));
			return (NULL);
		}
		i++;
	}

	fp = _getenv("PATH");
	if (!fp)
		return (NULL);
	vp = strtok(fp, ":");
	while (vp)
	{
		fc = malloc(strlen(command) + strlen(vp) + 2);
		if (!fc)
		{
			free(fp), fp = NULL;
			return (NULL);
		}
		strcpy(fc, vp);
		strcat(fc, "/");
		strcat(fc, command);
		if (stat(fc, &buf) == 0)
		{
			free(fp), fp = NULL;
			return (fc);
		}
		vp = strtok(NULL, ":");
		free(fc), fc = NULL;
	}
	free(fp), fp = NULL;
	return (NULL);
}
