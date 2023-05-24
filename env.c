#include "shell.h"

/**
 * env_var - retrieves the value of an environment variable
 * @str: string input
 *
 * Return: value of an environment variable
 */

char env_var(char *str)
{
	size_t len;
	int x = -1;

	if (str == NULL || *str == '\0')
	{
		return (NULL);
	}
	if (environ == NULL)
	{
		return (NULL);
	}
	len = _strlen(str);
	while (environ[++x])
	{
		if (!_cmpstrn(environ[x], str, len) && environ[x][len] == "=")
		{
			return (environ[x] + len + 1);
		}
	}
	return (NULL);
}
/**
 * loc_exec - locates an executable file associated with a given command.
 * @ds: data input
 *
 * Return: void
 */
int loc_exec(data *in)
{
	char *tok, *path, *p;
	int found = -1;
	size_t toklen;

	p = malloc(_strlen(env_var("PATH") ? env_var("PATH") : "") + 1);
	if (p == NULL)
	{
		free(p);
		return (found);
	}
	_cpystr(p, env_var("PATH"));
	if (p == NULL)
	{
		free(p);
		return (found);
	}
	tok = strtok(p, ":");
	while (tok)
	{
		toklen = _strlen(tok) + _strlen(in->ar[0]) + 2;
		path = malloc(toklen);
		if (path == NULL)
		{
			free(p);
			return (found);
		}
		_cpystr(path, tok);
		_catstr(path, "/");
		_catstr(path,in->ar[0]);

		if (access(path, F_OK) == 0)
		{
			free(in->ar[0]);
			in->ar[0] = _ptrstr(path);
			free(path);
			found = 0;
			break;
		}
		free(path);
		tok = strtok(NULL, ":");
	}
	free(p);
	return (found);
}
