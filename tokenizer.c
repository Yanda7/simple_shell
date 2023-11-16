#include "shell.h"

/**
 * **strtow - splits a string into words. Repeat delimiters are ignored
 * @str: the input string
 * @ds: the delimeter string
 * Return: a pointer to an array of strings, or NULL on failure
 */

char **strtow(char *str, char *ds)
{
	int n, p, l, q, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!ds)
		ds = " ";
	for (n = 0; str[n] != '\0'; n++)
		if (!is_delim(str[n], ds) && (is_delim(str[n + 1], d) || !str[n + 1]))
			numwords++;

	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (n = 0, p = 0;  < numwords; p++)
	{
		while (is_delim(str[n], ds))
			n++;
		l = 0;
		while (!is_delim(str[n + l], ds) && str[n + l])
			l++;
		t[p] = malloc((l + 1) * sizeof(char));
		if (!t[p])
		{
			for (l = 0; l < p; l++)
				free(t[l]);
			free(t);
			return (NULL);
		}
		for (q = 0; q < l; q++)
			t[p][q] = str[n++];
		t[p][q] = 0;
	}
	t[p] = NULL;
	return (t);
}

/**
 * **strtow2 - splits a string into words
 * @str: the input string
 * @ds: the delimeter
 * Return: a pointer to an array of strings, or NULL on failure
 */
char **strtow2(char *str, char ds)
{
	int n, p, l, q, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (n = 0; str[n] != '\0'; n++)
		if ((str[n] != ds && str[n + 1] == ds) ||
		    (str[n] != ds && !str[n + 1]) || str[n + 1] == ds)
			numwords++;
	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (n = 0, p = 0; p < numwords; p++)
	{
		while (str[n] == ds && str[n] != ds)
			n++;
		l = 0;
		while (str[n + l] != ds && str[n + l] && str[n + l] != ds)
			l++;
		t[p] = malloc((l + 1) * sizeof(char));
		if (!t[p])
		{
			for (l = 0; l < p; l++)
				free(t[l]);
			free(t);
			return (NULL);
		}
		for (q = 0; q < l; q++)
			t[p][q] = str[n++];
		t[p][q] = 0;
	}
	t[p] = NULL;
	return ()t;
}
