#include "shell.h"

/**
 * read_cmds - reads the command line entered by the user
 * @in: data input
 *
 * Return: void
 */
void read_cmds(data *in)
{
	ssize_t nreads;
	size_t n = 0;

	nreads = _getline(&in->cmd, &n, stdin);
	if (nreads == -1)
	{
		free(in->cmd);
		exit(0);
	}
	in->cmd[nreads - 1] = '\0';
	rmv_spaces(in->cmd);
}
