#include "shell.h"

 /**
  * main - initialize and executes
  * @argc: arguments count
  * @argv: arguments array
  *
  * Return: 0
  */

int main(int argc, char **argv)
{
	(void)argc;
	data in;

	it_inits(&in, argv[0]);
	exec_cmds(&in);

	return (0);
}
