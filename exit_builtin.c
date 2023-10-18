#include "shell.h"
/**
 * handle_exit_command - Handle the "exit" built-in command.
 * @arguments: An array of strings containing the command and its arguments.
 *
 * This function checks if the user entered the "exit" command and, if so, exits
 * the shell. It frees any memory allocated for the argument array and terminates
 * the shell process.
 */
void handle_exit_command(char **arguments)
{
if (strcmp(arguments[0], "exit") == 0)
{
free_tokens(arguments);
exit(0);
}
}
