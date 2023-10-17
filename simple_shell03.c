#include "shell.h"
#define DELIM ":"

/**
 * find_executable - searches for an executable command in the PATH.
 * @cmd: user input command to locate
 *
 * Return: If an error occurs or the command cannot be located - NULL.
 *         Otherwise - the full pathname of the command.
 */

char *find_executable(const char *cmd)
{
char *path_env = getenv("PATH");
char *token, *full_path, *path_copy;
int full_path_length;

if (!path_env)
return (NULL);

path_copy = strdup(path_env);
if (!path_copy)
return (NULL);

token = strtok(path_copy, DELIM);

while (token)
{
full_path_length = strlen(token) + strlen(cmd) + 2;
full_path = malloc(full_path_length);

if (!full_path)
{
free(path_copy);
return (NULL);
}

sprintf(full_path, "%s/%s", token, cmd);

if (access(full_path, F_OK | X_OK) == 0)
{
free(path_copy);
return (full_path);
}

free(full_path);
token = strtok(NULL, DELIM);
}

free(path_copy);
return (NULL);
}
