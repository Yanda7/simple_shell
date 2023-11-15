#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int m)
{
	int k, p;
	char *q = dest;

	k = 0;
	while (src[k] != '\0' && k < m - 1)
	{
		dest[k] = src[k];
		k++;
	}
	if (k < m)
	{
		p = k;
		while (p < m)
		{
			dest[p] = '\0';
			p++;
		}
	}
	return (q);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int m)
{
	int x, e;
	char *g = dest;

	x = 0;
	e = 0;
	while (dest[x] != '\0')
		x++;
	while (src[e] != '\0' && e < m)
	{
		dest[x] = src[e];
		x++;
		e++;
	}
	if (x < m)
		dest[x] = '\0';
	return (g);
}

/**
 **_strchr - locates a character in a string
 *@g: the string to be parsed
 *@c: the character to look for
 *Return: (g) a pointer to the memory area s
 */
char *_strchr(char *g, char k)
{
	do {
		if (*g == k)
			return (k);
	} while (*g++ != '\0');

	return (NULL);
}
