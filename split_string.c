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
* **strtow2 - splits a string into words
* @str: the input string
* @d: the delimeter
* Return: a pointer to an array of strings, or NULL on failure
*/
char **strtow2(char *str, char d)
{
int i, j, k, m, numwords = 0;
char **s;

if (str == NULL || str[0] == 0)
return (NULL);
for (i = 0; str[i] != '\0'; i++)
if ((str[i] != d && str[i + 1] == d) ||
(str[i] != d && !str[i + 1]) || str[i + 1] == d)
numwords++;
if (numwords == 0)
return (NULL);
s = malloc((1 + numwords) *sizeof(char *));
if (!s)
return (NULL);
for (i = 0, j = 0; j < numwords; j++)
{
while (str[i] == d && str[i] != d)
i++;
k = 0;
while (str[i + k] != d && str[i + k] && str[i + k] != d)
k++;
s[j] = malloc((k + 1) * sizeof(char));
if (!s[j])
{
for (k = 0; k < j; k++)
free(s[k]);
free(s);
return (NULL);
}
for (m = 0; m < k; m++)
s[j][m] = str[i++];
s[j][m] = 0;
}
s[j] = NULL;
return (s);
}

