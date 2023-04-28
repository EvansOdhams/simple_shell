#include "shell.h"
/**
* **strtow - splits a string into substrings based on a delimiter
* @str: the string to split
* @delim: the delimiter to use
*
* Return: a NULL-terminated array of pointers to the substrings
*/
char **strtow(char *str, char *delim)
{
int i, j, k, m, num_words = 0;
char **substrings;
if (str == NULL || str[0] == '\0')
return (NULL);
if (!delim)
delim = " ";
for (i = 0; str[i] != '\0'; i++)
if (!is_delim(str[i], delim) &&
(is_delim(str[i + 1], delim) || !str[i + 1]))
num_words++;
if (num_words == 0)
return (NULL);
substrings = malloc((1 + num_words) *sizeof(char *));
if (!substrings)
return (NULL);
for (i = 0, j = 0; j < num_words; j++)
{
while (is_delim(str[i], delim))
i++;
for (k = 0; !is_delim(str[i + k], delim) && str[i + k]; k++)
;
substrings[j] = malloc((k + 1) * sizeof(char));
if (!substrings[j])
{
for (k = 0; k < j; k++)
free(substrings[k]);
free(substrings);
return (NULL);
}
for (m = 0; m < k; m++)
substrings[j][m] = str[i++];
substrings[j][m] = '\0';
}
substrings[j] = NULL;
return (substrings);
}

/**
* strtow2 - Splits a string into words using a delimiter.
* @str: The string to split.
* @delimiter: The character that delimits the words in the string.
*
* Return: A pointer to an array of strings, where each element
*         points to a word. Returns NULL if str is NULL, if str is
*         empty, or if memory allocation fails.
*/
char **strtow2(char *str, char delimiter)
{
int i, j, k, m, num_words = 0;
char **substrings;
if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
{
if ((str[i] != delimiter && str[i + 1] == delimiter) ||
(str[i] != delimiter && !str[i + 1]) || str[i + 1] == delimiter) {
num_words++;
}
}
if (num_words == 0)
return (NULL);
substrings = malloc((1 + num_words) *sizeof(char *));
if (!substrings)
return (NULL);
for (i = 0, j = 0; j < num_words; j++)
{
while (str[i] == delimiter && str[i] != delimiter)
i++;
k = 0;
while (str[i + k] != delimiter && str[i + k] && str[i + k] != delimiter)
k++;
substrings[j] = malloc((k + 1) * sizeof(char));
if (!substrings[j])
{
for (k = 0; k < j; k++)
free(substrings[k]);
free(substrings);
return (NULL);
}
for (m = 0; m < k; m++)
substrings[j][m] = str[i++];
substrings[j][m] = 0;
}
substrings[j] = NULL;
return (substrings);
}
