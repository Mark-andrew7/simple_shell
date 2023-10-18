#include "shell.h"
/**
 * handle_exit_command - Handle the "exit" built-in command.
 * @arguments: An array of strings containing the command an args
 */
void handle_exit_command(char **arguments)
{
if (strcmp(arguments[0], "exit") == 0)
{
free_tokens(arguments);
exit(0);
}
}
