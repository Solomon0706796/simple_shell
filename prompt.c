#include "shell.h"

/**
 * print_prompt - prints the prompt
 * @signal: prompt
 *
 * Return: void
 */

void print_prompt(int signal)
{
	const char prompt[] = "\n¤ ";
	(void)signal;
	itprints(prompt);
}
