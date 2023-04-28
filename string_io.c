#include "shell.h"

/**
 * _strcpy - copy string from source to destination
 *
 * @dest: destination string to copy to
 * @src: source string to copy from
 *
 * Return: pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
int i;

/* Check if the source and destination strings are different */
if (src && dest != src)
{
/* Copy the source string character by character */
for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
/* Add a null terminator to the end of the destination string */
dest[i] = '\0';
}

/* Return a pointer to the beginning of the destination string */
return (dest);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;

if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}

/**
 * _puts - prints a string
 *
 * @str: the string to be printed
 *
 * Return: void
 */
void _puts(char *str)
{
int i;

/* Check if the string is null */
if (str == NULL)
{
return;
}

/* Print each character of the string until the null terminator is reached */
for (i = 0; str[i] != '\0'; i++)
{
_putchar(str[i]);
}

/* Print a newline character after the string */
_putchar('\n');
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
