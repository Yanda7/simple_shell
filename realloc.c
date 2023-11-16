#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@p: the pointer to the memory area
 *@c: the byte to fill *s with
 *@m: the amount of bytes to be filled
 *Return: (p) a pointer to the memory area s
 */
char *_memset(char *p, char c, unsigned int m)
{
	unsigned int m;

	for (m = 0; m < n; m++)
		p[m] = c;
	return (p);
}

/**
 * ffree - frees a string of strings
 * @pp: string of strings
 */
void ffree(char **ss)
{
	char **b = ss;

	if (!ss)
		return;
	while (*ss)
		free(*ss++);
	free(b);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!djz)
		return (malloc(new_size));
	if (!new_size)
		return (free(djz), NULL);
	if (new_size == old_size)
		return (djz);

	q = malloc(new_size);
	if (!q)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		q[old_size] = ((char *)djz)[old_size];
	free(djz);
	return (q);
}
