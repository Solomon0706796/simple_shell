#include "shell.h"

/**
 * _strlen - calculates the length of a string
 * @s: pointer to string
 *
 * Return: number of characters in string
 */

size_t _strlen(const char *s)
{
	size_t len = 0;

	while (s[len] != '\0')
	{
		len++;
	}
	return (len);
}

/**
 * _cpystr - copies the string from the source to the destination
 * @src: source
 * @dest: destination
 *
 * Return: pointer to destination
 */

char *_cpystr(char *dest, const char *src)
{
	char *cp = dest;

	while (*src)
	{
		*dest++ = *src++;
	}
	*dest = '\0';

	return (cp);
}
