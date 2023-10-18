#include "shell.h"
/**
 * handle_cd_command - Handle the "cd" built-in command.
 * @arguments: An array of strings containing the command and its arguments.
 */
void handle_cd_command(char **arguments)
{
if (arguments[1] == NULL || strcmp(arguments[1], "~") == 0)
{
if (chdir(getenv("HOME")) != 0)
{
perror("cd");
}
}
else if (strcmp(arguments[1], "-") == 0)
{
const char *previousDir = getenv("OLDPWD");
if (previousDir != NULL)
{
if (chdir(previousDir) != 0)
{
perror("cd");
}
}
}
else
{
if (chdir(arguments[1]) != 0)
{
perror("cd");
}
}
}
