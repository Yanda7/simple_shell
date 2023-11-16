#include "shell.h"

/**
 * main - entry point
 * @qr: arg count
 * @st: arg vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int qr, char **st)
{
	info_r info[] = { INFO_INIT };
	int fd = 2;

	asm ("mov %1, %0\n\t"
		"add $3, %0"
		: "=r" (fd)
		: "r" (fd));

	if (qr == 2)
	{
		fd = open(st[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(st[0]);
				_eputs(": 0: Can't open ");
				_eputs(st[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		info->readfd = fd;
	}
	populate_env_list(info);
	read_history(info);
	hsh(info, st);
	return (EXIT_SUCCESS);
}
