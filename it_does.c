#include "shell.h"

/**
 * itprints - prints string to stdout
 * @str: input
 *
 * Return: void
 */
void itprints(const char *str)
{
	if (str == NULL)
		return;
	while (*str)
	{
		write(STDOUT_FILENO, str, 1);
		str++;
	}
}
/**
 * it_inits - initializes data
 * @in: data input
 * @shell: string
 *
 * Return: void
 */
void it_inits(data *in, const char *shell)
{
	in->ar = NULL;
	in->cmd = NULL;
	in->shell = shell;
}
