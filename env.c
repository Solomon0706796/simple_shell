#include "shell.h"

/**
 * env_var - adds a new environmental variable
 * @var: env variable to add
 *
 * Return: 0 if failed, 1 on success
 */

int env_var(char *var)
{
	char **env, **nenv, *nvar;
	int x, len, cp;

	env = environ;
	len = _strlen(var);
	nvar = malloc(sizeof(char) * (len + 1));

	if (nvar == NULL)
	{
		perror("Memory allocation error");
		return (0);
	}
	_cpystr(nvar, var);

	for (x = 0; env[x] != NULL; x++)
		;
	nenv = malloc(sizeof(char *) * (x + 2));
	if (nenv == NULL)
	{
		perror("Memory allocation error");
		free(nvar);
		return (0);
	}
	for (x = 0; env[x] != NULL; x++)
		nenv[x] = env[x];

	nenv[x] = nvar;
	nenv[x + 1] = NULL;
	cp = setenv(nvar, "", 1);
	if (cp == -1)
	{
		perror("Error setting environmental variable");
		free(nvar);
		free(nenv);
		return (0);
	}
	free(env);
	environ = nenv;
	return (1);
}
