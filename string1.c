#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
 * @sr: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *dest, char *sr)
{
	int m = 0;

	if (dest == sr || sr == 0)
		return (dest);
	while (sr[m])
	{
		dest[m] = src[m];
		m++;
	}
	dest[m] = 0;
	return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
 *_puts - prints an input string
 *@str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int m = 0;

	if (!str)
		return;
	while (str[m] != '\0')
	{
		_putchar(str[m]);
		m++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char f)
{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (f == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, m);
		m = 0;
	}
	if (f != BUF_FLUSH)
		buf[m++] = f;
	return (1);
}
