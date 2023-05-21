<<<<<<< HEAD
#ifndef SHELL_H
#define SHELL_H

#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int calculate_area_rect(int length, int breath)
#endif	
=======
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

#define BUF 1024

extern char **environ;

/* prints prompt */
void print_prompt(void);
/* reads command line */
char *read_cmd(void);
/* executes command */
int exec_cmd(char *cmd);
/* splits command line into arguments */
char **split_cmd(char *cmd);
/* frees memory allocated for arguments */
void free_args(char **args);
/* adds new environmental variable */
int env_var(char *var);

/* helper functions */

/* calculates length of the string */
size_t _strlen(const char *s);
/* copies a string */
char *_cpystr(char *dest, const char *src);
#endif
>>>>>>> d320eb016492e5b83d1bc82ad32a2393f85cddff
