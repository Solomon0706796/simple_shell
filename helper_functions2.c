#include "shell.h"

/**
 * _ptrstr - returns pointer to newly allocated space in memory,
 *		which contains a copy of the string given in input
 * @str: input
 *
 * Return: pointer
 */
char *_ptrstr(const char *str)
{
	int x, len = 0;
	char *r;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[len] != '\0')
	{
		len++;
	}
	r = (char *)malloc((len + 1) * sizeof(char));
	if (r == NULL)
	{
		return (NULL);
	}
	for (x = 0; x <= len; x++)
	{
		r[x] = str[x];
	}
	free(r);
	return (r);
}
/**
 * rmv_spaces - removes any type of spaces from a string
 * @str: string
 *
 * Return: void
 */
void rmv_spaces(char *str)
{
	int len = _strlen(str);
	int x, y;

	for (x = 0; x < len && (str[x] == ' ' || str[x] == '\t'); x++)
		;
	for (y = 0; x < len; x++, y++)
	{
		str[y] = str[x];
	}
	str[y] = '\0';

	for (x = _strlen(str) - 1; x > 0 && (str[x] == ' ' || str[x] == '\t'); x--)
		str[x] = '\0';
}
/**
 * free_args - frees a memory allocated for arguments
 * @ar: arguments
 *
 * Return: void
 */
void free_args(char **ar)
{
	int x;

	if (!ar)
	{
		return;
	}
	for (x = 0; ar[x]; x++)
	{
		free(ar[x]);
	}
	free(ar);
}
/**
 * _realloc - reallocates a memory block
 * @ptr: pointer
 * @new_loc: new pointer location
 *
 * Return: newly allocated memory
 */
void *_realloc(void *ptr, unsigned int new_loc)
{
	unsigned int old_loc = sizeof(ptr);
	unsigned int x, nptr = new_loc;
	char *po = malloc(new_loc);

	if (old_loc == new_loc)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		return (malloc(new_loc));
	}
	if (new_loc > old_loc)
	{
		nptr = old_loc;
	}
	if (new_loc == 0)
	{
		free(ptr);
		return (NULL);
	}
	for (x = 0; x < nptr; x++)
	{
		po[x] = ((char *)ptr)[x];
	}
	free(ptr);
	return (po);
}
