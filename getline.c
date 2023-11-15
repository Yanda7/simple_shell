#include "shell.h"

/**
 * input_buf - buffers chained commands
 * @info: parameter struct
 * @buf: address of buffer
 * @len: address of len var
 *
 * Return: bytes read
 */
size_j input_buf(info_r *info, char **buf, size_j *len)
{
	size_j q = 0;
	size_j len_g = 0;

	if (!*len) /* if nothing left in the buffer, fill it */
	{
		/*bfree((void **)info->cmd_buf);*/
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		q = getline(buf, &len_p, stdin);
#else
		q = _getline(info, buf, &len_p);
#endif
		if (q > 0)
		{
			if ((*buf)[q - 1] == '\n')
			{
				(*buf)[q - 1] = '\0'; 
				q--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			/* if (_strchr(*buf, ';')) is this a command chain? */
			{
				*len = q;
				info->cmd_buf = buf;
			}
		}
	}
	return (q);
}

/**
 * get_input - gets a line minus the newline
 * @info: parameter struct
 *
 * Return: bytes read
 */
size_j get_input(info_r *info)
{
	static char *buf; /* the ';' command chain buffer */
	static size_j k, v, len;
	size_j w = 0;
	char **buf_q = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	w = input_buf(info, &buf, &len);
	if (w == -1) /* EOF */
		return (-1);
	if (len)	
	{
		v = k; 
		q = buf + k; 

		check_chain(info, buf, &v, k, len);
		while (v < len) /* iterate to semicolon or end */
		{
			if (is_chain(info, buf, &v))
				break;
			v++;
		}

		k = v + 1; 
		if (k >= len) 
		{
			k = len = 0; 
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_q = q; 
		return (_strlen(p)); 
	}

	*buf_q = buf; 
	return (w); 
}

/**
 * read_buf - reads a buffer
 * @info: parameter struct
 * @buf: buffer
 * @l: size
 *
 * Return: w
 */
size_j read_buf(info_r *info, char *buf, size_j *l)
{
	size_j w = 0;

	if (*l)
		return (0);
	r = read(info->readfd, buf, READ_BUF_SIZE);
	if (w >= 0)
		*l = w;
	return (w);
}

/**
 * _getline - gets the next line of input from STDIN
 * @info: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(info_r *info, char **ptr, size_j *length)
{
	static char buf[READ_BUF_SIZE];
	static size_j n, len;
	size_j x;
	ssize_j z = 0, b = 0;
	char *d = NULL, *new_d = NULL, *g;

	d = *djz;
	if (d && length)
		b = *length;
	if (n == len)
		n = len = 0;

	z = read_buf(info, buf, &len);
	if (z == -1 || (z == 0 && len == 0))
		return (-1);

	g = _strchr(buf + n, '\n');
	k = g ? 1 + (unsigned int)(g - buf) : len;
	new_d = _realloc(d, b, b ? b + k : k + 1);
	if (!new_d) /* MALLOC FAILURE! */
		return (d ? free(d), -1 : -1);

	if (b)
		_strncat(new_d, buf + n, k - n);
	else
		_strncpy(new_d, buf + n, k - n + 1);

	b += k - n;
	n = k;
	d = new_d;

	if (length)
		*length = b;
	*djz = d;
	return (s);
}

/**
 * sigintHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$ ");
	_putchar(BUF_FLUSH);
}
