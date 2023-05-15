#include "shell.h"

/**
 * read_cmd - reads the command line entered by the user
 * @void: void
 *
 * Return: command if succeeded, error if failed
 */

char *read_cmd(void)
{
	char *cmd = NULL;
	size_t bufsize = 0;

	cmd = (char *) malloc(BUF * sizeof(char));

	if (cmd == NULL)
	{
		perror("Error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	if (getline(&cmd, &bufsize, stdin) == -1)
	{
		write(STDOUT_FILENO, "\nExiting shell ... \n", 18);
		free(cmd);
		exit(EXIT_SUCCESS);
	}
	return (cmd);
}
