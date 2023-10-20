#include "shell.h"

/**
 * checkInteractive - checks if the shell is in interactive mode
 * @shellInfo: Pointer to the info_t structure
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int checkInteractive(info_t *shellInfo)
{
return (isatty(STDIN_FILENO) && shellInfo->readfd <= 2);
}

/**
 * isDelimiter - checks if a character is a delimiter
 * @character: The character to check
 * @delimiters: The delimiter string
 *
 * Return: 1 if it's a delimiter, 0 if not
 */
int isDelimiter(char character, char *delimiters)
{
while (*delimiters)
if (*delimiters++ == character)
return (1);
return (0);
}

/**
 * isAlphabetic - checks for an alphabetic character
 * @character: The character to check
 *
 * Return: 1 if character is alphabetic, 0 otherwise
 */
int isAlphabetic(int character)
{
if ((character >= 'a' && character <= 'z') || (character >= 'A' && character <= 'Z'))
return (1);
else
return (0);
}

/**
 * stringToInteger - converts a string to an integer
 * @inputString: The string to be converted
 *
 * Return: The integer value of the string, or 0 if no numbers in the string
 */
int stringToInteger(char *inputString)
{
int i, sign = 1, flag = 0, result;
unsigned int output = 0;

for (i = 0; inputString[i] != '\0' && flag != 2; i++)
{
if (inputString[i] == '-')
sign *= -1;

if (inputString[i] >= '0' && inputString[i] <= '9')
{
flag = 1;
output *= 10;
output += (inputString[i] - '0');
}
else if (flag == 1)
flag = 2;
}

if (sign == -1)
result = -output;
else
result = output;

return (result);
}
