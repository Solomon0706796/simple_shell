#include "shell.h"

 /**
  * main - main function that runs a simple shell
  * @void: no parameters
  *
  * Return: 0
  */

int main(void)
{
	char *prompt = "¤ ";
	char *cmd, **args;
	size_t len;
	int x;

	env_var("ES_VAR=Hello ALX");

	while (1)
	{
		write(STDOUT_FILENO, prompt, _strlen(prompt));
		cmd = read_cmd();
		len = _strlen(cmd);
		write(STDOUT_FILENO, cmd, len);
		write(STDOUT_FILENO, "\n", 1);
		args = split_cmd(cmd);
		exec_cmd(args[0]);
		free(cmd);

		for (x = 0; args[x] != NULL; x++)
			free(args[x]);
		free(args);
	}
	return (0);
}
