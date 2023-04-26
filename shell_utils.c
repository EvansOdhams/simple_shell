#include "shell.h"

/**
* _myhistory - Prints the list of previously executed commands
* @info: Pointer to a struct containing potential arguments
*
* Return: Always 0
*/
int _myhistory(info_t *info)
{
print_list(info->history);
return (0);
}

/**
* unset_alias - removes an alias from the list of aliases
* @info: struct containing program information
* @str: string representing the alias to be removed
*
* Return: 0 on success, 1 on error
*/
int unset_alias(info_t *info, char *str)
{
char *equals_pos, c;
int ret;

equals_pos = _strchr(str, '=');
if (!equals_pos)
return (1);

c = *equals_pos;
*equals_pos = '\0';

ret = delete_node_at_index(
&(info->alias),
get_node_index(info->alias, node_starts_with(info->alias, str, -1))
);

*equals_pos = c;
return (ret);
}

/**
* set_alias - sets an alias to a string
* @info: structure containing potential arguments
* @str: the string to set the alias to
*
* Return: 0 on success, 1 on error
*/
int set_alias(info_t *info, char *str)
{
char *equal;

equal = _strchr(str, '=');
if (!equal)
return (1);
if (!*++equal)
return (unset_alias(info, str));

unset_alias(info, str);
return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - prints the value of an alias
* @node: the node of the alias to print
*
* Return: Always 0 on success, 1 on error
*/
int print_alias(list_t *node)
{
char *equal_sign = NULL, *alias_value = NULL;

if (node)
{
equal_sign = _strchr(node->str, '=');
for (alias_value = node->str; alias_value <= equal_sign; alias_value++)
_putchar(*alias_value);
_putchar('\'');
_puts(equal_sign + 1);
_puts("'\n");
return (0);
}
return (1);
}

/**
* _myalias - Mimics the alias builtin (man alias)
* @info: Structure containing potential arguments
*
* Return: Always 0
*/
int _myalias(info_t *info)
{
int i;
char *equal_sign;
list_t *alias_node;

/* If no arguments, print all aliases */
if (info->argc == 1)
{
alias_node = info->alias;
while (alias_node)
{
print_alias(alias_node);
alias_node = alias_node->next;
}
return (0);
}

/* Otherwise, iterate through arguments and set or print aliases */
for (i = 1; info->argv[i]; i++)
{
equal_sign = _strchr(info->argv[i], '=');
if (equal_sign)
{
set_alias(info, info->argv[i]); /* Set the alias */
}
else
{
alias_node = node_starts_with(info->alias, info->argv[i], '=');
print_alias(alias_node); /* Print the alias */
}
}

return (0);
}

