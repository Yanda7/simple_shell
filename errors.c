#include "shell.h"

/**
 *_Cputs - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _Cputs(char *str)
{
	int n = 0;

	if (!str)
		return;
	while (str[n] != '\0')
	{
		_Cputchar(str[n]);
		n++;
	}
}

/**
 * _Cputchar - writes the character d to stderr
 * @d: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _Cputchar(char d)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || n >= WRITE_BUF_SIZE)
	{
		write(2, buf, n);
		n = 0;
	}
	if (d != BUF_FLUSH)
		buf[n++] = c;
	return (1);
}

/**
 * _putfd - writes the character d to given fd
 * @d: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char d, int fd)
{
	static int n;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, n);
		n = 0;
	}
	if (d != BUF_FLUSH)
		buf[n++] = d;
	return (1);
}

/**
 *_putsfd - prints an input string
 * @str: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int n = 0;

	if (!str)
		return (0);
	while (*str)
	{
		n += _putfd(*str++, fd);
	}
	return (n);
}
