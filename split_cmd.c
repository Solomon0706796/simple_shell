#include "shell.h"

/**
 * split_cmd - splits commands using a delimiter
 * @in: data input
 * @delim: delimiter
 *
 * Return: void
 */
void split_cmd(data *in, const char *delim)
{
	int ntoks = 0;
	char *tok;

	in->ar = malloc(2 * sizeof(char *));
	if (in->ar == NULL)
	{
		free(in->cmd);
		perror(in->shell);
		exit(EXIT_FAILURE);
	}
	in->ar[0] = NULL;
	in->ar[1] = NULL;

	tok = strtok(in->cmd, delim);
	while (tok)
	{
		in->ar = _realloc(in->ar, (ntoks + 2) * sizeof(char *));
		if (in->ar == NULL)
		{
			perror(in->shell);
			free(in->cmd);
			exit(EXIT_FAILURE);
		}
		in->ar[ntoks] = _ptrstr(tok);
		if (in->ar[ntoks] == NULL)
		{
			perror(in->shell);
			free_args(in->ar);
			free(in->cmd);
			exit(EXIT_FAILURE);
		}
		ntoks++;
		tok = strtok(NULL, delim);
	}
	in->ar[ntoks] = NULL;
}
