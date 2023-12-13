#include "shell.h"
/**
 * _itoa - int to string
 * @num: the number
 * @str: the string
 * @base: ...
 *
 * Return: ...
 */

char *_itoa(int num, char *str, int base)
{
	int i, isNegative, remainder, j, len;
	char temp;

	i = 0;
	isNegative = 0;
	if (base < 2 || base > 36)
	{
		return (NULL);
	}
	if (num == 0)
	{
		str[i++] = '0';
		str[i] = '\0';
		return (str);
	}
	if (num < 0 && base == 10)
	{
		isNegative = 1;
		num = -num;
	}
	while (num != 0)
	{
		remainder = num % base;
		str[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'a');
		num /= base;
	}
	if (isNegative)
	{
		str[i++] = '-';
	}
	str[i] = '\0';
	len = i;
	for (j = 0; j < len / 2; j++)
	{
		temp = str[j];
		str[j] = str[i - 1];
		str[i - 1] = temp;
		i--;
	}
	return (str);
}
/**
 * prr - function to print error
 * @argv: ....
 * @cmd: ....
 * @index: .....
 * Return: void
 */
void prr(char *argv, char *cmd, int index)
{
	char i[10], **errs;
	int a = 0;
	const int maxErrs = 7;

	errs = malloc((maxErrs + 1) * sizeof(char *));
	if (!errs)
	{
		return;
	}
	_itoa(index, i, 10);
	errs[0] = _strdup(argv);
	errs[1] = _strdup(": ");
	errs[2] = _strdup(i);
	errs[3] = _strdup(": ");
	errs[4] = _strdup(cmd);
	errs[5] = _strdup(": ");
	errs[6] = _strdup("not found\n");
	errs[7] = NULL;
	if (errs[0] && errs[1] && errs[2]
	&& errs[3] && errs[4] && errs[5] && errs[6])
	{
		while (errs[a] && a < maxErrs)
		{
			write(STDERR_FILENO, errs[a], _strlen(errs[a]));
			a++;
		}
		a = 0;
		while (errs[a] && a <= maxErrs)
		{
			free(errs[a]);
			errs[a] = NULL;
			a++;
		}
	}
	free(errs);
}

/**
 * _atoi - function to convert string to int
 * @s: the string
 * Return: int
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, res = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-')
			sign *= -1;
		else if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + s[i] - '0';
		else
			return (res * sign);
		i++;
	}
	return (res * sign);
}




/**
 * berr - function to handle error messages.
 * @argv: ....
 * @cmd: ....
 * @index: .....
 * @s: .....
 * Return: void
 */
void berr(char *argv, char *cmd, int index, char *s)
{
	char i[10], **errs;
	int a = 0;
	const int maxErrs = 10;
	(void)s;

	errs = malloc((maxErrs + 1) * sizeof(char *));
	if (!errs)
	{
		return;
	}
	_itoa(index, i, 10);
	errs[0] = _strdup(argv);
	errs[1] = _strdup(": ");
	errs[2] = _strdup(i);
	errs[3] = _strdup(": ");
	errs[4] = _strdup(cmd);
	errs[5] = _strdup(": ");
	errs[6] = _strdup("Illegal number");
	errs[7] = _strdup(": ");
	errs[8] = _strdup(s);
	errs[9] = _strdup("\n");
	errs[10] = NULL;
	if (errs[0] && errs[1] && errs[2]
	&& errs[3] && errs[4] && errs[5] && errs[6])
	{
		while (errs[a] && a < maxErrs)
		{
			write(STDERR_FILENO, errs[a], _strlen(errs[a]));
			a++;
		}
		a = 0;
		while (errs[a] && a <= maxErrs)
		{
			free(errs[a]);
			errs[a] = NULL;
			a++;
		}
	}
	free(errs);
}

