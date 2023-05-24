#include "shell.h"

/**
 * print_prompt - prints the prompt
 * @prmt: prompt
 *
 * Return: void
 */

void print_prompt(int prmt)
{
	const char prompt[] = "\n¤ ";
	(void)prmt;
	itprints(prompt);
}
