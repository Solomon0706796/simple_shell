#include "shell.h"

/**
 * env_var - retrieves the value of an environment variable
 * @str: string input
 *
 * Return: value of an environment variable
 */

char *env_var(char *str)
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
		if (!_cmpstrn(environ[x], str, len) && environ[x][len] == '=')
		{
			return (environ[x] + len + 1);
		}
	}
	return (NULL);
}
