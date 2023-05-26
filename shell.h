#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <stddef.h>

#define BUF_SIZE 1024

extern char **environ;
/**
 * struct data - data
 * @shell: shell name
 * @cmd: command
 * @ar: array
 */
typedef struct data
{
	const char *shell;
	char **env;
	char *cmd;
	char **ar;
} data;
/**
 * struct bltin - builtin
 * @cmd: command
 * @func: function
 */
typedef struct bltin
{
	const char *cmd;
	void (*func)(data *in);
} bltin;

/* main function */
int main(int argc, char **argv, char **env);
/* prints prompt */
void print_prompt(int signal);
/* reads command line */
void read_cmds(data *in);
/* starts a new process */
void itstarts(data *in);
/* executes command */
void exec_cmds(data *in);
/* splits a command line using a delimiter */
void split_cmd(data *in, const char *delim);
/* adds new environmental variable */
char *env(char *str);
/* locates files*/
int loc_exec(data *in);
/* reads the input from FILE */
ssize_t _getline(char **str_in, size_t *i, FILE *stream);

/* builtin */

/* executes built-in commands */
int builtin_cmds(data *in);
/* exits the shell */
void bltin_exit(data *in);
/* prints the current environment */
void bltin_env(data *in);

/* helper functions */

/* calculates length of the string */
unsigned int _strlen(char *str);
/* copies a string */
char *_cpystr(char *dest, const char *src);
/* apends the source input to destination */
char *_catstr(char *dest, const char *src);
/* compares the length of two strings */
int _cmprstr(const char *str1, const char *str2);
/* compares the specified length of two strings */
int _cmpstrn(const char *str1, const char *str2, int i);

/* helper functions 2 */

/* reallocates a memory block */
void *_realloc(void *ptr, unsigned int new_loc);
/* returns pointer to newly allocated space in memory */
char *_ptrstr(const char *str);
/* frees memory allocated for arguments */
void free_args(char **ar);
/* removes trailing spaces */
void rmv_spaces(char *str);
/* getline helper */
int _getline_help(char **str_in, size_t *i);

/* it does */

/* printf implementation */
void itprints(const char *str);
/* initializes data */
void it_inits(data *in, const char *shell, char **env);


#endif
