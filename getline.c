#include "shell.h"

static char buffer[BUFF_SIZE];
static size_t buffer_index;

/**
 * custom_getline - Read a line from stdin
 *
 * @lineptr: A pointer to the buffer where the line will be stored.
 * @n: A pointer to the size of the buffer.
 *
 * Return:
 *  - On success, returns the number of characters read
 *  - On error or end of input, returns -1.
 */
ssize_t custom_getline(char **lineptr, size_t *n)
{
size_t i = 0;
char c;

if (lineptr == NULL || n == NULL)
{
return (-1);
}

if (buffer_index == 0)
{
ssize_t read_result = read(STDIN_FILENO, buffer, BUFF_SIZE);

if (read_result <= 0)
{
return (-1);
}

buffer_index = (size_t)read_result;
}

*lineptr = (char *)malloc(*n);
if (*lineptr == NULL)
{
return (-1);
}

while (i < *n - 1)
{
c = buffer[buffer_index];
buffer_index++;

if (c == '\n')
{
(*lineptr)[i] = '\0';
return (i);
}
else if (buffer_index == BUFF_SIZE)
{
ssize_t read_result = read(STDIN_FILENO, buffer, BUFF_SIZE);

if (read_result <= 0)
{
return (-1);
}

buffer_index = 0;
}

(*lineptr)[i] = c;
i++;
}

return (-1);
}
