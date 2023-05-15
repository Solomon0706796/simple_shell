#include "shell.h"

/**
 * split_cmd - split commands into arguments
 * @cmd: command
 *
 * Return: arguments
 */

char **split_cmd(char *cmd)
{
	int x, ntoks = 0;
	char *tok, *cpy_cmd, **args = NULL;

	cpy_cmd = malloc((_strlen(cmd)) + 1 * sizeof(char));

	if (cpy_cmd == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	_cpystr(cpy_cmd, cmd);

	tok = strtok(cpy_cmd, " \t\n");

	while (tok != NULL)
	{
		ntoks++;
		tok = strtok(NULL, " \t\n");
	}

	args = malloc(sizeof(char *) * (ntoks + 1));

	if (args == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}
	tok = strtok(cmd, " \t\n");

	for (x = 0; x < ntoks; x++)
	{
		args[x] = tok;
		tok = strtok(NULL, " \t\n");
	}
	args[ntoks] = NULL;

	free(cpy_cmd);
	return (args);
}
