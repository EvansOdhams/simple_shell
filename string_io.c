#include "shell.h"

/**
 * _strcpy - copies the string pointed to by src to
 * the buffer pointed to by dest
 * @dest: buffer to copy string to
 * @src: string to be copied
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;

if (dest == src || src == NULL)
return (dest);

/* copy string */
while (src[i] != '\0')
{
dest[i] = src[i];
i++;
}

/* null-terminate string */
dest[i] = '\0';

return (dest);
}

/**
 * _strdup - creates a duplicate of a string in a new memory location
 * @str: the string to duplicate
 *
 * Return: a pointer to the newly-allocated duplicate string,
 * or NULL if an error occurs
 */
char *_strdup(const char *str)
{
size_t length;
char *new_str;

if (str == NULL)
return (NULL);

length = strlen(str);
new_str = malloc(length + 1);

if (new_str == NULL)
return (NULL);

memcpy(new_str, str, length + 1);
return (new_str);
}

/**
 * _puts - Prints a string to the standard output.
 * @str: The string to print.
 *
 * Return: Nothing.
 */
void _puts(char *str)
{
int i = 0;

if (!str)
return;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}

/**
 * _putchar - Writes a character to standard output.
 * @c: The character to write.
 *
 * Return: 1 on success, -1 on failure.
 */
int _putchar(char c)
{
static int i;
static char buffer[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
if (write(STDOUT_FILENO, buffer, i) == -1)
return (-1);
i = 0;
}

if (c != BUF_FLUSH)
buffer[i++] = c;

return (1);
}

