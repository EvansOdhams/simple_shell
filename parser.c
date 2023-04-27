#include "shell.h"

/**
* is_cmd - Determines whether a given file path points to an executable file
*
* @info: Pointer to a struct containing information about the current process
* @file_path: Pointer to a string representing the file path to check
*
* Return: 1 if the file is executable, 0 otherwise
*/
int is_cmd(info_t *info, char *file_path)
{
struct stat file_stats;

(void)info;

if (!file_path || stat(file_path, &file_stats))
return (0);

if (file_stats.st_mode & S_IFREG)
return (1);

return (0);
}

/**
 * dup_chars - Duplicates a substring of a string into a buffer.
 * @path_str: The string to extract the substring from.
 * @start: The start position of the substring.
 * @stop: The stop position of the substring.
 *
 * Return: The duplicated substring.
 */
char *dup_chars(char *path_str, int start, int stop)
{
static char buffer[1024];
int i = 0, k = 0;

for (k = 0, i = start; i < stop; i++)
{
if (path_str[i] != ':')
{
buffer[k++] = path_str[i];
}
}

buffer[k] = '\0';
return (buffer);
}

/**
* find_path - finds the full path of a command in the PATH environment variable
* @info: pointer to the info struct
* @path_str: the PATH environment variable
* @command: the command to find in the PATH
* Return: the full path of the command if found, otherwise NULL
*/
char *find_path(info_t *info, char *path_str, char *command)
{
int index = 0, curr_pos = 0;
char *full_path;

if (!path_str)
return (NULL);
if ((_strlen(command) > 2) && starts_with(command, "./"))
{
if (is_cmd(info, command))
return (command);
}
while (1)
{
if (!path_str[index] || path_str[index] == ':')
{
full_path = dup_chars(path_str, curr_pos, index);
if (!*full_path)
_strcat(full_path, command);
else
{
_strcat(full_path, "/");
_strcat(full_path, command);
}
if (is_cmd(info, full_path))
return (full_path);
if (!path_str[index])
break;
curr_pos = index;
}
index++;
}
return (NULL);
}






