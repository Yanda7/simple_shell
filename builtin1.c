#include "shell.h"

/**
 * _Phistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: potential arguments contained in a sturcture. it maintains
 *        constant function prototype.
 *  Return: Always 0
 */
int _Phistory(info_r *info)
{
	print_list(info->history);
	return (0);
}

/**
 * unset_Palias - sets Palias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int unset_Palias(info_r *info, char *str)
{
	char *f, g;
	int res;

	f = _strchr(str, '=');
	if (!f)
		return (1);
	g = *f;
	*f = 0;
	res = delete_node_at_index(&(info->Palias),
		get_node_index(info->alias, node_starts_with(info->Palias, str, -1)));
	*f = g;
	return (res);
}

/**
 * set_Palias - sets Palias to string
 * @info: parameter struct
 * @str: the string Palias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_Palias(info_r *info, char *str)
{
	char *f;

	f = _strchr(str, '=');
	if (!f)
		return (1);
	if (!*++f)
		return (unset_Palias(info, str));

	unset_Palias(info, str);
	return (add_node_end(&(info->Palias), str, 0) == NULL);
}

/**
 * print_Palias - prints an Palias string
 * @node: the Palias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_Palias(list_q *node)
{
	char *f = NULL, *m = NULL;

	if (node)
	{
		f = _strchr(node->str, '=');
		for (i = node->str; i <= f; m++)
			_putchar(*i);
		_putchar('\'');
		_puts(f + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _Palias - mimics the Palias builtin (man Palias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _Palias(info_r *info)
{
	int m = 0;
	char *f = NULL;
	list_q *node = NULL;

	if (info->argc == 1)
	{
		node = info->Palias;
		while (node)
		{
			print_Palias(node);
			node = node->next;
		}
		return (0);
	}
	for (m = 1; info->argv[m]; m++)
	{
		f = _strchr(info->argv[m], '=');
		if (f)
			set_palias(info, info->argv[m]);
		else
			print_Palias(node_starts_with(info->Palias, info->argv[m], '='));
	}

	return (0);
}
