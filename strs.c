#include "shell.h"
/**
 * _strlen - return the length of string
 * @str: the string
 *
 * Return: length
 */
int _strlen(char *str)
{
	int length;

	for (length = 0; str[length] != 0; length++)
		;
	return (length);
}
/**
 * _strdup - a function to allocate and cope
 * @str: the str to handle
 *
 * Return: duplicate
 */
char *_strdup(const char *str)
{
	size_t length = strlen(str);
	char *duplicate = (char *)malloc(length + 1);

	if (str == NULL)
	{
		return (NULL);
	}
	if (duplicate != NULL)
	{
		strcpy(duplicate, str);
	}

	return (duplicate);
}
/**
 * _strcmp - function to compare to s
 * @str1: string 1
 * @str2: string 2
 *
 * Return: the result
 */
int _strcmp(const char *str1, const char *str2)
{
	while (*str1 == *str2)
	{
		if (*str1 == '\0')
			return (0);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

/**
 * _strcat - function to add string to another
 * @dest: destination
 * @src: source
 *
 * Return: full string
 */

char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (original_dest);
}

/**
 * _strcpy - function simular to strcpy
 * @dest: destination
 * @src: source
 *
 * Return: the result
 */
char *_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0';

	return (original_dest);
}
