#include "shell.h"
/**
 * itstarts - starts a new process
 * @in: data input
 *
 * Return: void
 */
void itstarts(data *in)
{
	int stats = 0;
	pid_t cpid;

	cpid = fork();
	if (cpid == -1)
	{
		perror("Error forking process");
		free_args(in->ar);
		free(in->cmd);
		_exit(EXIT_FAILURE);
	}
	if (cpid == 0 && execve(in->ar[0], in->ar, NULL) == -1)
	{
		perror("Error executing command");
		free_args(in->ar);
		free(in->cmd);
		_exit(EXIT_FAILURE);
	}
	else if (wait(&stats) == -1)
	{
		perror("Error waiting for child process");
		free_args(in->ar);
		free(in->cmd);
		_exit(EXIT_FAILURE);
	}
}
/**
 * exec_cmds - executes a given commands
 * @in: data input
 *
 * Return: void
 */
void exec_cmds(data *in)
{
	const char prompt[] = "\n¤ ";

	signal(SIGINT, print_prompt);

	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			itprints(prompt);
		}
		read_cmds(in);
		if (_strlen(in->cmd) != 0)
		{
			split_cmd(in, " ");
			if (!builtin_cmds(in))
			{
				loc_exec(in);
				if (access(in->ar[0], F_OK) == -1)
				{
					perror(in->shell);
				}
				else
				{
					itstarts(in);
				}
			}
			free_args(in->ar);
		}
		free(in->cmd);
	}
}
