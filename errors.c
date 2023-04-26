#include "shell.h"

/**
* _eputs - Prints a string to the standard error.
* @str: The string to be printed.
*
* Return: Nothing.
*/
void _eputs(char *str)
{
int index = 0;

if (!str)
return;

while (str[index] != '\0')
{
_putfd(str[index], STDERR_FILENO);
index++;
}
}

/**
* _eputchar - writes the character c to stderr
* @character: The character to print
*
* Return: On success 1.
*         On error, -1 is returned, and errno is set appropriately.
*/
int _eputchar(char character)
{
static int buffer_index;
static char buffer[WRITE_BUF_SIZE];

if (character == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
{
write(STDERR_FILENO, buffer, buffer_index);
buffer_index = 0;
}
if (character != BUF_FLUSH)
buffer[buffer_index++] = character;

return (1);
}

/**
* _putfd - writes a character to the given file descriptor
* @c: the character to print
* @fd: the file descriptor to write to
* Return: On success, 1
* On failure, -1 is returned and errno is set appropriately.
*/
int _putfd(char c, int fd)
{
static int buffer_index;
static char buffer[WRITE_BUF_SIZE];

/* Flush the buffer if the character is the flush signal */
if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
{
write(fd, buffer, buffer_index);
buffer_index = 0;
}

/* Add character to buffer if it's not the flush signal */
if (c != BUF_FLUSH)
buffer[buffer_index++] = c;

return (1);
}


/**
* _putsfd - writes an input string to a given file descriptor
* @str: The string to write
* @fd: The file descriptor to write to
*
* Return: The number of characters written.
*/
int _putsfd(char *str, int fd)
{
int num_chars = 0;

if (!str)
return (0);

while (*str)
{
num_chars += _putfd(*str++, fd);
}

return (num_chars);
}

