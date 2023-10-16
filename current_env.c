#include "shell.h"

/**
 * printEnvironment - Prints the current environment variables.
 * Return: nothing
 */
void printEnvironment(void)
{
char **env = environ;
while (*env)
{
printf("%s\n", *env);
env++;
}
}

/**
 * executeCommand - Executes a command.
 * @programName: Name of the program
 * @arguments: User input arguments
 *
 * Return: 0 on success
 */
int executeCommand(char *programName, char **arguments)
{
char *commandPath, *command;
pid_t childPid;
int childStatus;

if (!arguments[0])
return (0);

command = arguments[0];

if (strcmp(command, "exit") == 0)
{
free_tokens(arguments);
exit(0);
}
else if (strcmp(command, "env") == 0)
{
printEnvironment();
}
else
{
commandPath = find_executable(command);
if (!commandPath)
{
fprintf(stderr, "%s: 1: %s: not found\n", programName, command);
return (0);
}

childPid = fork();
if (childPid == -1)
{
perror("Error");
}
else if (childPid == 0)
{
if (execve(commandPath, arguments, NULL) == -1)
{
perror("Error: ");
exit(0);
}
}
else if (waitpid(childPid, &childStatus, 0) == -1)
{
perror("Error: ");
}
free(commandPath);
}
return (0);
}
