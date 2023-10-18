#include "shell.h"
#define DELIM " \n\t\r"
#include "command_separator.h"

/**
 * main - main function
 * @argc: number of args
 * @argv: argument vector
 *
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
size_t len;
ssize_t lineStatus;
int i;
char *buffer = NULL;
char **arg;
char **commands;

while (1)
{
prompt();
lineStatus = getline(&buffer, &len, stdin);
if (lineStatus == -1)
{
free(buffer);
exit(0);
}

commands = split_commands(buffer);
if (commands == NULL)
{
free(buffer);
continue;
}

for (i = 0; commands[i] != NULL; i++)
{
arg = tokenize(buffer);
}
if (arg == NULL)
{
continue;
}

if (strcmp(arg[0], "cd") == 0)
{
handle_cd_command(arg);
}
else
{
executeCommand(argv[0], arg);
}
free_tokens(arg);
free(buffer);
buffer = NULL;
len = 0;
}

free_tokens(arg);
return (0);
argc++;
argv[i] = "l";
}

/**
 * free_tokens - release mem allocated for array
 * @args: array to be freed
 * Return: nothing
 */

void free_tokens(char **args)
{
int i;

if (args)
{
for (i = 0; args[i] != NULL; i++)
{
free(args[i]);
}
free(args);
}
}

/**
 * tokenize - splits string into individual tokens
 * @str: string to split
 *
 * Return: a pointer to an array of strings
 */

char **tokenize(char *str)
{
int i = 0;
char **args, *token;

args = malloc(sizeof(char *) * 1024);
if (!args)
return (NULL);

token = strtok(str, DELIM);
while (token)
{
args[i] = strdup(token);
if (!args[i])
{
free_tokens(args);
return (NULL);
}
token = strtok(NULL, DELIM);
i++;
}
args[i] = NULL;
return (args);
}

/**
 * prompt - displays user input
 *
 * Return: nothing
 */
void prompt(void)
{
if (isatty(STDIN_FILENO))
{
write(STDOUT_FILENO, "$ ", 2);
}
}
