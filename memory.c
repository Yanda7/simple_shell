#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @djz: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **djz)
{
	if (djz && *djz)
	{
		free(*djz);
		*djz = NULL;
		return (1);
	}
	return (0);
}
