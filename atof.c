#include "shell.h"

/**
* interactive - check_interactive_mode - checks whether the shell
* is running in interactive mode
* @info: a pointer to the struct containing information about the shell
*
* Return: 1 if the shell is running in interactive mode, 0 otherwise
*/

int interactive(info_t *info)
{
int is_interactive = 0;

if (isatty(STDIN_FILENO) && info->readfd <= 2)
{
is_interactive = 1;
}

return (is_interactive);
}

/**
* is_delim - checks if character is a delimiter
* @c: the char to check
* @delim: the delimiter string
* Return: 1 if true, 0 if false
*/
int is_delim(char c, char *delim)
{
int i = 0;
while (delim[i] != '\0')
{
if (c == delim[i])
{
return (1);
}
i++;
}
return (0);
}

/**
* is_character_alpha - checks if a character is an alphabetic character
* @c: the character to check
*
* Return: 1 if the character is an alphabetic character, 0 otherwise
*/
int is_character_alpha(int c)
{
/* Check if the character is within the range of 'a' to 'z' or 'A' to 'Z' */
if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
{
return (1); /* Return 1 if character is an alphabetic character */
}
else
{
return (0); /* Return 0 if character is not an alphabetic character */
}
}

/**
* _atoi - This function converts a string to an integer.
* @str: Here is the string to be converted.
*
* Return: The converted integer, or 0 if no numbers in string.
*/
int _atoi(char *str)
{
int i, sign = 1, num_found = 0, result;
unsigned int value = 0;

for (i = 0; str[i] != '\0' && num_found != 2; i++)
{
if (str[i] == '-')
sign *= -1;

if (str[i] >= '0' && str[i] <= '9')
{
num_found = 1;
value *= 10;
value += (str[i] - '0');
}
else if (num_found == 1)
{
num_found = 2;
}
}

if (sign == -1)
result = -value;
else
result = value;

return (result);
}
