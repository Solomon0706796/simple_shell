#include "shell.h"

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments array
 * @env: environment
 *
 * Return: 0
 */
int main(int argc, char **argv, char **env)
{
	data in;
	(void)argc;

	it_inits(&in, argv[0], env);
	exec_cmds(&in);

	return (0);
}
