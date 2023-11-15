#include "shell.h"

/**
 * _Penv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _Penv(info_r *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_r *info, const char *name)
{
	list_q *node = info->env;
	char *f;

	while (node)
	{
		f = starts_with(node->str, name);
		if (f && *f)
			return (f);
		node = node->next;
	}
	return (NULL);
}

/**
 * _Psetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _Psetenv(info_r *info)
{
	if (info->argc != 3)
	{
		_Cputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_Psetenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _Punsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _Punsetenv(info_r *info)
{
	int n;

	if (info->argc == 1)
	{
		_Cputs("Too few arguements.\n");
		return (1);
	}
	for (n = 1; n <= info->argc; n++)
		_Punsetenv(info, info->argv[n]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_r *info)
{
	list_q *node = NULL;
	size_j n;

	for (n = 0; environ[n]; n++)
		add_node_end(&node, environ[n], 0);
	info->env = node;
	return (0);
}
