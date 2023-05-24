#include "shell.h"

/**
 * builtin_cmds - executes built-in commands after checking if they exit
 * @in: data input
 *
 * Return: 1 if true, 0 if not
 */
int builtin_cmds(data *in)
{
	int x = 0;

	bltin bltin[] = {
		{"exit", bltin_exit},
		{"env", bltin_env},
		{NULL, NULL}
	};

	for (x = 0; bltin[x].cmd; x++)
	{
		if (_cmprstr(in->ar[0], bltin[x].cmd) == 0)
		{
			bltin[x].func(in);
			return (1);
		}
	}
	return (0);
}
/**
 * bltin_exit - exits the shell
 * @in: data input
 *
 * Return: void
 */
void bltin_exit(data *in)
{
	int stats = 0;

	if (in->ar[1])
	{
		stats = atoi(in->ar[1]);
	}
	free_args(in->ar);
	free(in->cmd);
	exit(stats);
}
/**
 * bltin_env - prints the current environment
 * @in: data input
 *
 * Return: void
 */
void bltin_env(data *in)
{
	int x = 0;

	(void)in;

	while (environ[x])
	{
		itprints(environ[x]);
		itprints("\n");
		x++;
	}
}
