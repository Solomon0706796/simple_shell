#include "shell.h"

/**
 * _getline - reads the input from FILE
 * @str_in: string
 * @stream: FILE
 * @i: integer
 *
 * Return: number of characters read on success
 */
ssize_t _getline(char **str_in, size_t *i, FILE *stream)
{
	static char buf[BUF_SIZE];
	static size_t sbuf, pbuf;
	size_t nsize, pos = 0;
	ssize_t rbytes = 0;
	char *nbuffer;

	if (str_in == NULL || i == NULL || stream == NULL)
		return (-1);
	if (_getline_help(str_in, i) == -1)
		return (-1);

	while (1)
	{
		if (pbuf >= sbuf)
		{
			rbytes = read(stream->_fileno, buf, BUF_SIZE);
			if (rbytes <= 0 && pos == 0)
				return (-1);
			else if (rbytes <= 0)
				break;

			sbuf = rbytes;
			pbuf = 0;
		}
		if (pos >= *i - 1)
		{
			nsize = *i * 2;
			nbuffer = realloc(*str_in, nsize);
			if (nbuffer == NULL)
				return (-1);

			*str_in = nbuffer;
			*i = nsize;
		}
		(*str_in)[pos++] = buf[pbuf++];
		if ((*str_in)[pos - 1] == '\n')
			break;
	}
	(*str_in)[pos] = '\0';
	return (pos);
}
