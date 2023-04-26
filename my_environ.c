#include "shell.h"

/**
* _myenv - prints the current environment variables.
* @info: Pointer to a structure of type info_t.
* Used to maintain constant function prototype.
* Return: Always returns 0.
*/
int _myenv(info_t *info)
{
/* call print_list_str function from shell.h*/
print_list_str(info->env);

/* Always return 0 */
return (0);
}


/**
* _getenv - Returns the value of an environment variable
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* @name: Name of the environment variable to retrieve
* Return: The value of the environment variable, or NULL if not found.
*/

char *_getenv(info_t *info, const char *name)
{
list_t *env_node = info->env;
char *value;

while (env_node)
{
value = starts_with(env_node->str, name);
if (value && *value)
return (value);
env_node = env_node->next;
}
return (NULL);
}


/**
* _mysetenv - Initialize a new environment variable,
* or modify an existing one
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int _mysetenv(info_t *info)
{
if (info->argc != 3)
{
_eputs("Incorrect number of arguements\n");
return (1);
}
if (_setenv(info, info->argv[1], info->argv[2]))
return (0);
return (1);
}

/**
* _myunsetenv - Remove an environment variable
* @info: Structure containing potential arguments. Used to maintain
* constant function prototype.
* Return: Always 0
*/
int _myunsetenv(info_t *info)
{
int index;

/* Check if there are enough arguments */
if (info->argc == 1)
{
_eputs("Too few arguments.\n");
return (1);
}

/* Loop through each argument and remove the corresponding environment */
for (index = 1; index < info->argc; index++)
{
_unsetenv(info, info->argv[index]);
}

/* Return 0 to indicate successful completion */
return (0);
}

/**
* populate_env_list - populates linked list with environment variables
* @info: pointer to struct containing potential arguments
* Return: 0 on success, 1 on failure
*/
int populate_env_list(info_t *info)
{
list_t *head = NULL;
size_t index;

/* Traverse through the environment variables */
for (index = 0; environ[index]; index++)
{
/* Add the variable to the end of the list */
add_node_end(&head, environ[index], 0);
}

/* Update the info struct with the head of the list */
info->env = head;

/* Return success */
return (0);
}

