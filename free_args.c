#include "shell.h"

/**
 * free_args - frees memory allocated for arguments
 * @args: arguments
 *
 * Return: void
 */

void free_args(char **args)
{
	free(args);
}
