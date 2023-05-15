#include "shell.h"

/**
 * print_prompt - prints the prompt
 * @void: void
 *
 * Return: 0
 */

void print_prompt(void)
{
	char prompt[] = "¤ ";

	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}
