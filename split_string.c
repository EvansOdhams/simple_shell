#include "shell.h"

/**
* count_words - counts the number of words in a string
* @str: the input string
* @delimiter: the delimiter character
* Return: the number of words in the string
*/
static int count_words(char *str, char delimiter)
{
int num_words = 0, i;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] != delimiter && (str[i + 1] == delimiter || str[i + 1] == '\0'))
{
num_words++;
}
}

return (num_words);
}

/**
* allocate_memory - allocates memory for an array of strings
* @num_words: the number of words
* Return: a pointer to the allocated memory or NULL on failure
*/
static char **allocate_memory(int num_words)
{
char **result = malloc((num_words + 1) * sizeof(char *));
if (result == NULL)
return (NULL);
result[num_words] = NULL;
return (result);
}

/**
* free_memory - frees any allocated memory
* @result: the array of strings
* @num_words: the number of words
*/
static void free_memory(char **result, int num_words)
{
int i;

for (i = 0; i < num_words; i++)
free(result[i]);
free(result);
}

/**
* split_string - splits a string into an array of words
* @str: the input string
* @delimiter: the delimiter character
* Return: a pointer to an array of strings, or NULL on failure
*/
char **split_string(char *str, char delimiter)
{
int i, j, k, m, num_words = 0;
char **result;

if (str == NULL || str[0] == '\0')
return (NULL);

num_words = count_words(str, delimiter);
if (num_words == 0)
return (NULL);

result = allocate_memory(num_words);
if (result == NULL)
return (NULL);

for (i = 0, j = 0; j < num_words; j++)
{
while (str[i] == delimiter && str[i] != '\0')
i++;
k = 0;
while (str[i + k] != delimiter && str[i + k] != '\0')
k++;
result[j] = malloc((k + 1) * sizeof(char));
if (result[j] == NULL)
{
free_memory(result, j);
return (NULL);
}
for (m = 0; m < k; m++)
result[j][m] = str[i++];
result[j][m] = '\0';
}

return (result);
}
