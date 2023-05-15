#include "shell.h"

/**
 * exec_cmd - executes commands
 * @cmd: command to be executed
 *
 * Return: 1 on success, 0 if failed
 */

int exec_cmd(char *cmd)
{
	char **args, *err_msg;
	pid_t cpid;
	int stats;

	args = split_cmd(cmd);
	cpid = fork();
	if (cpid == -1)
	{
		err_msg = "Error forking process\n";
		write(STDERR_FILENO, err_msg, _strlen(err_msg));
		free_args(args);
		exit(EXIT_FAILURE);
	}
	if (cpid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			err_msg = "Error executing command\n";
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			free_args(args);
			exit(EXIT_FAILURE);
		}
	} else
	{
		if (waitpid(cpid, &stats, 0) == -1)
		{
			err_msg = "Error waiting for child process\n";
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			free_args(args);
			exit(EXIT_FAILURE);
		} else if (stats != 0)
		{
			err_msg = "Child process exited with error\n";
			write(STDERR_FILENO, err_msg, _strlen(err_msg));
			free_args(args);
			exit(EXIT_FAILURE);
		}
	}
	free_args(args);
	return (1);
}
