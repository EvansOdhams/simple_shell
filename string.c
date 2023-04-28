#include "shell.h"

/**
* _strlen - Gets the length of a string.
* @str: The string to measure.
*
* Return: The length of the string.
*/
int _strlen(char *str)
{
int length = 0;

if (!str)
return (0);

while (*str++)
length++;

return (length);
}

/**
 * _strcmp - Compares two strings.
 * @s1: The first string to be compared.
 * @s2: The second string to be compared.
 *
 * Return: An integer less than, equal to, or greater than zero if s1 is found,
 * respectively, to be less than, to match, or be greater than s2.
 */
int _strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] && s2[i] && s1[i] == s2[i])
i++;

if (s1[i] == s2[i])
return (0);

return (s1[i] < s2[i] ? -1 : 1);
}

/**
* *starts_with - Checks if a string starts with a specified prefix.
* @str: The string to search.
* @prefix: The prefix to look for.
*
* Return: A pointer to the location in str where the prefix begins,
*         or NULL if the prefix is not found.
*/
char *starts_with(const char *str, const char *prefix)
{
while (*prefix)
if (*prefix++ != *str++)
return (NULL);

return ((char *)str);
}

/**
 * *_strcat - Concatenates two strings.
 * @dest: The destination string to append to.
 * @src: The source string to append.
 *
 * Return: A pointer to the concatenated string.
 */
char *_strcat(char *dest, char *src)
{
char *result = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = '\0';

return (result);
}

