#include "shell.h"

/**
 * _strlen - Compute the length of a null-terminated string.
 *
 * @s: The string to compute the length of.
 *
 * Return: The length of the string, excluding the null terminator.
 */
size_t _strlen(const char *s)
{
size_t length = 0;

if (s == NULL)
return (0);

while (*s != '\0')
{
length++;
s++;
}

return (length);
}

/**
 * _strcmp - compares two strings.
 * @str1: first string to compare.
 * @str2: second string to compare.
 *
 * Return: 0 if strings are equal, -1 if str1 is less than str2, 1 otherwise.
 */
int _strcmp(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}

/**
 * starts_with - checks if a string starts with a specific prefix
 *
 * @haystack: the string to search
 * @needle: the prefix to search for
 *
 * Return: a pointer to the first occurrence of the prefix in the string,
 *         or NULL if the prefix is not found
 */
char *starts_with(const char *haystack, const char *needle)
{
size_t haystack_len, needle_len;
size_t i;

if (haystack == NULL || needle == NULL)
return (NULL);

haystack_len = strlen(haystack);
needle_len = strlen(needle);

if (needle_len > haystack_len)
return (NULL);

for (i = 0; i < needle_len; i++)
{
if (haystack[i] != needle[i])
return (NULL);
}

return ((char *) haystack);
}

/**
 * _strcat - concatenates two strings
 *
 * @dest: the destination string
 * @src: the source string
 *
 * Return: a pointer to the resulting string
 */
char *_strcat(char *dest, char *src)
{
char *result = dest;

while (*dest != '\0')
dest++;

while (*src != '\0')
{
*dest = *src;
dest++;
src++;
}

*dest = '\0';

return (result);
}

