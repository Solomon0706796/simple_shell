#include "shell.h"
/**
 * loc_exec - locates an executable file associated with a given command.
 * @in: data input
 * Return: void
 */
int loc_exec(data *in)
{
	char *path, *tok;
	char *p = malloc(_strlen(env_var("PATH") ? env_var("PATH") : "") + 1);
	int found = -1;
	size_t toklen;

	if (env_var("PATH"))
	{
		_cpystr(p, env_var("PATH"));
		if (p != NULL)
		{
			tok = strtok(p, ":");
			while (tok)
			{
				toklen = _strlen(tok) + _strlen(in->ar[0]) + 2;
				path = malloc(toklen);
				if (path != NULL)
				{
					_cpystr(path, tok);
					_catstr(path, "/");
					_catstr(path, in->ar[0]);
					if (access(path, F_OK) == 0)
					{
						free(in->ar[0]);
						in->ar[0] = _ptrstr(path);
						free(path);
						found = 0;
						break;
					}
					free(path);
				}
				tok = strtok(NULL, ":");
			}
		}
	}
	free(p);
	return (found);
}
