#include "shell.h"

 /**
  * main - main function that runs a simple shell
  * @void: no parameters
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
