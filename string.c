#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @s: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *s)
{
int i = 0;

if (!s)
return (0);

while (*s++)
i++;
return (i);
}

/**
* _strcmp - performs Lexical comparison of two strings.
* @s1: the first string as it input parameter
* @s2: the second string as its input parameters
*
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
*/
int my_strcmp(char *s1, char *s2)
{
int i = 0;

while (s1[i] != '\0' && s2[i] != '\0')
{
if (s1[i] != s2[i])
{
return (s1[i] - s2[i]);
}
i++;
}

if (s1[i] == '\0' && s2[i] == '\0')
{
return (0);
}
else
{
return (s1[i] < s2[i] ? -1 : 1);
}
}

int main(void)
{
char s1[] = "hello";
char s2[] = "world";
int result = my_strcmp(s1, s2);
printf("%d\n", result);
return (0);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;

while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
