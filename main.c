#include "shell.h"

/**
 * main - main function
 * @argc: arguments count
 * @argv: arguments array
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	data in;
	(void)argc;

	it_inits(&in, argv[0]);
	exec_cmds(&in);

	return (0);
}
