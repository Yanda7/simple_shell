#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_j list_len(const list_q *g)
{
	size_j n = 0;

	while (g)
	{
		g = g->next;
		n++;
	}
	return (n);
}

/**
 * list_to_strings - returns an array of strings of the list->str
 * @head: pointer to first node
 *
 * Return: array of strings
 */
char **list_to_strings(list_q *head)
{
	list_q *node = head;
	size_j n = list_len(head), k;
	char **strs;
	char *str;

	if (!head || !n)
		return (NULL);
	strs = malloc(sizeof(char *) * (n + 1));
	if (!strs)
		return (NULL);
	for (n = 0; node; node = node->next, n++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (k = 0; k < n; k++)
				free(strs[k]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[n] = str;
	}
	strs[n] = NULL;
	return (strs);
}


/**
 * print_list - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_j print_list(const list_q *g)
{
	size_j n = 0;

	while (g)
	{
		_puts(convert_number(g->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(g->str ? g->str : "(nil)");
		_puts("\n");
		g = g->next;
		n++;
	}
	return (n);
}

/**
 * node_starts_with - returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_q *node_starts_with(list_t *node, char *prefix, char d)
{
	char *e = NULL;

	while (node)
	{
		e = starts_with(node->str, prefix);
		if (e && ((d == -1) || (*e == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
size_j get_node_index(list_q *head, list_q *node)
{
	size_j n = 0;

	while (head)
	{
		if (head == node)
			return (n);
		head = head->next;
		n++;
	}
	return (-1);
}
