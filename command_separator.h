#include "shell.h"
/**
 * split_commands - Split input into multiple commands using a separator.
 * @input: The input string containing multiple commands separated by a separator.
 *
 * This function tokenizes the input string based on the specified separator
 * and returns an array of strings, each containing a separate command.
 *
 * Returns: An array of strings, with each element being a command. The array
 * ends with a NULL pointer to indicate the end of commands.
 */

char **split_commands(char *input)
{
char **commands = NULL;
char *token = strtok(input, ";");
int i = 0;

while (token != NULL)
{
commands = (char **)realloc(commands, (i + 1) * sizeof(char *));
if (commands == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
commands[i] = strdup(token);
if (commands[i] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
i++;
token = strtok(NULL, ";");
}
commands = (char **)realloc(commands, (i + 1) * sizeof(char *));
if (commands == NULL)
{
perror("realloc");
exit(EXIT_FAILURE);
}
commands[i] = NULL;

return (commands);
}
