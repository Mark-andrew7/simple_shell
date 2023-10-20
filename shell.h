#ifndef SHELL_H
#define SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <stdbool.h>

#define BUFF_SIZE 1024

extern char **environ;

struct Alias
{
char *name;
char *value;
struct Alias *next;
};
struct Alias *alias_list = NULL;

typedef struct info
{
int readfd;
char *path_env;
char *token;
char *full_path;
char *path_copy;
char **env;
char **arguments;
int lineStatus;
}info_t;

int _putchar(char c);
void prompt(void);
void free_tokens(char **args);
int main(int argc, char **argv);
char **tokenize(char *str);
char *find_executable(const char *cmd);
int executeCommand(char *programName, char **arguments);
void printEnvironment(void);
ssize_t custom_getline(char **lineptr, size_t *n);
void handle_cd_command(char **arguments);
char **split_commands(char *input);
void handle_exit_command(char **arguments);
void process_alias_command(char **arguments, struct Alias **alias_list);
int checkInteractive(info_t *shellInfo);
int isDelimiter(char character, char *delimiters);
int isAlphabetic(int character);
int stringToInteger(char *inputString);

#endif
