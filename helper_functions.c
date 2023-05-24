#include "shell.h"

/**
 * _strlen - calculates the length of a string
 * @str: pointer to string
 *
 * Return: number of characters in string
 */

unsigned int _strlen(char *str)
{
	unsigned int x;

	for (x = 0; str[x] != '\0'; x++)
		;
	return (x);
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
	char *p = dest;

	while (*src)
	{
		*p++ = *src++;
	}
	*p = '\0';

	return (dest);
}
/**
 * _catstr - appends the source string to the destination
 * @src: source
 * @dest: destination
 *
 * Return: void
 */
char *_catstr(char *dest, const char *src)
{
	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (dest);
}
/**
 * _cmprstr - compares two strings
 * @str1: first string
 * @str2: second string
 *
 * Return: 0 is str1 and str2 are equal
 *		negative value if str1 is less than str2
 *		positive value if str1 is greater than str2
 */
int _cmprstr(const char *str1, const char *str2)
{
	int x, r = 0;

	for (x = 0; str1[x] != '\0' && str2[x] != '\0'; x++)
	{
		if (str1[x] != str2[x])
		{
			r = str1[x] - str2[x];
			break;
		}
	}
	return (r);
}
/**
 * _cmpstrn - compares two strings of specific length
 * @str1: first string
 * @str2: second string
 * @i: input
 *
 * Return: 0 is str1 and str2 are equal
 *		negative value if str1 is less than str2
 *		positive value if str1 is greater than str2
 */
int _cmpstrn(const char *str1, const char *str2, int i)
{
	int x, r = 0;

	for (x = 0; str1[x] != '\0' && str2[x] != '\0'; x++)
	{
		if (x >= i)
			break;
		if (str1[x] != str2[x])
		{
			r = str1[x] - str2[x];
			break;
		}
	}
	return (r);
}
