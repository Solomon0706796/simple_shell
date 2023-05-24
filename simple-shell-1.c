#include "shell.h"
#include <sys/wait.h>

#define MAX_COMMAND 20

void prints(char **av, char **env)
{
	char *buffs = NULL;
	int h, l, stats;
	size_t n = 0;
	ssize_t str_char;
	char *argv[MAX_COMMAND];
	pid_t chld_pid;

	while (2)
	{
		if (isatty(STDIN_FILENO))
