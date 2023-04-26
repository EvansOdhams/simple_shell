#include "shell.h"

/**
* _strncpy - copies a string up to n characters
* @dest: the destination string to be copied to
* @src: the source string to be copied
* @n: the maximum number of characters to be copied
* Return: the copied string
*/
char *_strncpy(char *destination, char *source, int n)
{
int i, j;
char *result = destination;

i = 0;
while (source[i] != '\0' && i < n - 1)
{
destination[i] = source[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
destination[j] = '\0';
j++;
}
}
return (result);
}

/**
* _strncat - concatenates two strings
* @dest: the first string
* @src: the second string
* @n: the amount of bytes to be maximally used
*
* Return: the concatenated string
*/
char *_strncat(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
while (dest[i] != '\0') /* Find the end of dest */
i++;

j = 0;
while (src[j] != '\0' && j < n) /* Copy src to dest */
{
dest[i] = src[j];
i++;
j++;
}

if (j < n) /* Terminate the concatenated string */
dest[i] = '\0';

return (s);
}

/*
* _strchr - function locates a character in a string
* @str: pointer to the string to be parsed
* @c: the character to look for
*
* Return: pointer to the memory area 'str', or
* NULL if the character is not found
*/
char *_strchr(char *str, char c)
{
/* Loop through each character in 'str' */
do {
/* Check if current character is 'c' */
if (*str == c)
return (str);
} while (*str++ != '\0'); /* Keep looping until end of 'str' is reached */

/* If 'c' is not found, return NULL */
return (NULL);
}

