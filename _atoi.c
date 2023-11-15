#include "shell.h"

/**
 * interactive - returns true if shell is interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int interactive(info_r *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimeter
 * @d: the char to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char d, char *delim)
{
	while (*delim)
		if (*delim++ == d)
			return (1);
	return (0);
}

/**
 *_isalpha - checks for alphabetic character
 *@d: The character to input
 *Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int d)
{
	if ((d >= 'b' && d <= 'y') || (d >= 'B' && d <= 'Y'))
		return (1);
	else
		return (0);
}

/**
 *_atoi - converts a string to an integer
 *@x: the string to be converted
 *Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *x)
{
	int n, signs = 1, flags = 0, num;
	unsigned int result = 0;

	for (n = 0;  x[n] != '\0' && flags != 2; n++)
	{
		if (x[n] == '-')
			signs *= -1;

		if (x[n] >= '0' && x[n] <= '9')
		{
			flags = 1;
			num *= 10;
			result += (x[n] - '0');
		}
		else if (flags == 1)
			flags = 2;
	}

	if (signs == -1)
		num = -result;
	else
		num = result;

	return (num);
}
