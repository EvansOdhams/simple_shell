#include "shell.h"

/**
 * is_chain - Determines whether the current position in the command buffer
 * represents a chain operator (e.g. '&&', '||', or ';').
 *
 * @info: Pointer to the info_t struct that contains the current
 *        command buffer type
 * @buf: Pointer to the command buffer string
 * @p: Pointer to the current position in the command buffer string
 *
 * Return: 1 if the current position represents a chain operator, 0 otherwise
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
size_t j = *p;

switch (buf[j])
{
case '|':
if (buf[j + 1] == '|')
{
buf[j] = 0;
info->cmd_buf_type = CMD_OR;
j++;
}
break;

case '&':
if (buf[j + 1] == '&')
{
buf[j] = 0;
info->cmd_buf_type = CMD_AND;
j++;
}
break;

case ';':
buf[j] = 0;
info->cmd_buf_type = CMD_CHAIN;
break;

default:
return (0);
}

*p = j;
return (1);
}

/**
 * check_chain - check for command chaining operators and update buffer
 * accordingly
 *
 * @info: pointer to info_t struct
 * @buf: pointer to command buffer
 * @p: pointer to current position in buffer
 * @i: current index
 * @len: length of buffer
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
size_t j = *p;

/*check for '&&' operator and update buffer*/
if (info->cmd_buf_type == CMD_AND && info->status)
{
buf[i] = '\0';
j = len;
}

/*check for '||' operator and update buffer*/
if (info->cmd_buf_type == CMD_OR && !info->status)
{
buf[i] = '\0';
j = len;
}

*p = j;
}

/**
 * replace_alias - Replaces a command with its aliased value, if it exists.
 *
 * @info: Pointer to an info_t struct
 * Return: 1 on success, 0 on failure
 */
int replace_alias(info_t *info)
{
list_t *node;
char *p;
int i = 0;

while (i < 10)
{
node = node_starts_with(info->alias, info->argv[0], '=');
if (!node)
return (0);
free(info->argv[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
info->argv[0] = p;
i++;
}
return (1);
}

/**
 * replace_vars - replaces variable names with their values
 * @info: a pointer to the info_t struct containing the variables to replace
 *
 * Return: Always 0.
 */
int replace_vars(info_t *info)
{
int i;
list_t *node;

for (i = 0; info->argv[i]; i++)
{
if (info->argv[i][0] != '$' || !info->argv[i][1])
continue;

if (!_strcmp(info->argv[i], "$?"))
{
/*replace with exit status value*/
replace_string(&info->argv[i], _strdup(convert_number(info->status, 10, 0)));
}
else if (!_strcmp(info->argv[i], "$$"))
{
/*replace with process ID value*/
replace_string(&info->argv[i], _strdup(convert_number(getpid(), 10, 0)));
}
else
{
/*look for environment variable and replace with its value*/
node = node_starts_with(info->env, &info->argv[i][1], '=');
if (node)
{
replace_string(&info->argv[i], _strdup(_strchr(node->str, '=') + 1));
}
else
{
/*no matching environment variable found; replace with empty string*/
replace_string(&info->argv[i], _strdup(""));
}
}
}

return (0);
}

/**
 * replace_string - replaces old string with a new one
 * @old: pointer to string that needs to be replaced
 * @new: pointer to the new string
 *
 * This function replaces the old string with a new one by freeing the
 * memory allocated for the old string and assigning the new string to
 * the pointer.
 *
 * Return: void
 */
int replace_string(char **old, char *new)
{
free(*old);
*old = new;
return (1);
}

