#include "shell.h"

/**
 * list_len - This funtion determines length of linked list
 * @h: This is a pointer to the first node
 *
 * Return: The size of the list
 */
size_t list_len(const list_t *h)
{
if (!h)
return (0);
else
return (1 + list_len(h->next));
}

/**
 * list_to_strings - Converts a linked list to an array of strings
 * @head: A pointer to the head of the linked list
 *
 * Return: An array of strings containing the strings from the linked list
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_len(head), j;
char **strs;
char *str;

if (!head || !i)
return (NULL);

strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
return (NULL);

for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}
str = _strcpy(str, node->str);
strs[i] = str;
}

strs[i] = NULL;
return (strs);
}

/**
 * print_list - prints all the elements of a linked list of strings
 * @head: pointer to the head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_list(const list_t *head)
{
size_t count = 0;

while (head)
{
printf("%d: %s\n", head->num, (head->str) ? head->str : "(nil)");
head = head->next;
count++;
}

return (count);
}

/**
 * node_starts_with - finds the first node in a linked list whose string value
 * starts with a given prefix and has an optional specific
 * character at a specific position
 * @head: pointer to the first node of the linked list
 * @prefix: pointer to the prefix string to search for
 * @c: optional character to match at the specified position
 *
 * Return: pointer to the first node that matches the criteria or NULL if none
 * is found
 */
list_t *node_starts_with(list_t *head, char *prefix, char c)
{
char *str_start = NULL;

while (head)
{
str_start = starts_with(head->str, prefix);
if (str_start && ((c == -1) || (*str_start == c)))
return (head);
head = head->next;
}

return (NULL);
}

/**
 * get_node_index - returns the index of a given node in a linked list
 * @head: pointer to the head of the list
 * @node: pointer to the node to find the index of
 *
 * Return: the index of the node, or -1 if the node is not found
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;

while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}

