90% of storage used … If you run out, you won't have enough storage to create, edit and upload files. Get 100 GB of storage for R 34,99 R 8,99/month for 3 months.
#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @p: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *p)
{
	int n = 0;

	if (!n)
		return (0);

	while (*p++)
		n++;
	return (n);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @p1: the first strang
 * @p2: the second strang
 *
 * Return: negative if p1 < p2, positive if p1 > p2, zero if p1 == p2
 */
int _strcmp(char *p1, char *p2)
{
	while (*p1 && *p2)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
	}
	if (*p1 == *p2)
		return (0);
	else
		return (*p1 < *p2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
