#include "shell.h"

/**
* hsh - main function for the simple shell
* @info: struct containing information about the shell
* @av: array of arguments passed to the shell
*
* Return: the exit status of the last executed command or the value of
*         the corresponding shell built-in function
*/
int hsh(info_t *info, char **av)
{
ssize_t r = 0;
int builtin_ret = 0;

while (r != -1 && builtin_ret != -2)
{
clear_info(info);
if (interactive(info))
_puts("$ ");
_eputchar(BUF_FLUSH);
r = get_input(info);
if (r != -1)
{
set_info(info, av);
builtin_ret = find_builtin(info);
if (builtin_ret == -1)
find_cmd(info);
}
else if (interactive(info))
_putchar('\n');
free_info(info, 0);
}
write_history(info);
free_info(info, 1);
if (!interactive(info) && info->status)
exit(info->status);
if (builtin_ret == -2)
{
if (info->err_num == -1)
exit(info->status);
exit(info->err_num);
}
return (builtin_ret);
}

/**
* find_builtin - searches for a built-in function in the command table
* @info: a pointer to a struct containing information about the command entered
* Return: the exit status of the built-in function if found, otherwise -1
*/
int find_builtin(info_t *info)
{
int i, built_in_ret = -1;
char *built_in_cmds[] = {"exit", "env", "help", "history",
"setenv", "unsetenv", "cd", "alias", NULL};
int (*built_in_funcs[])(info_t *) = {_myexit, _myenv, _myhelp,
_myhistory, _mysetenv, _myunsetenv, _mycd, _myalias, NULL};

for (i = 0; built_in_cmds[i] != NULL; i++)
{
if (_strcmp(info->argv[0], built_in_cmds[i]) == 0)
{
info->line_count++;
built_in_ret = built_in_funcs[i](info);
break;
}
}

return (built_in_ret);
}
/**
* find_cmd - finds a command in PATH
* @info: the parameter & return info struct
*
* Return: void
*/
void find_cmd(info_t *info)
{
char *path = NULL;
int i, k;

info->path = info->argv[0];
if (info->linecount_flag == 1)
{
info->line_count++;
info->linecount_flag = 0;
}
for (i = 0, k = 0; info->arg[i]; i++)
if (!is_delim(info->arg[i], " \t\n"))
k++;
if (!k)
return;

path = find_path(info, _getenv(info, "PATH="), info->argv[0]);
if (path)
{
info->path = path;
fork_cmd(info);
}
else
{
if ((interactive(info) || _getenv(info, "PATH=")
|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
fork_cmd(info);
else if (*(info->arg) != '\n')
{
info->status = 127;
print_error(info, "not found\n");
}
}
}

/**
* fork_cmd - forks a an exec thread to run cmd
* @info: the parameter & return info struct
*
* Return: void
*/
void fork_cmd(info_t *info)
{
pid_t child_pid;

child_pid = fork();
if (child_pid == -1)
{
/* TODO: PUT ERROR FUNCTION */
perror("Error:");
return;
}
if (child_pid == 0)
{
if (execve(info->path, info->argv, get_environ(info)) == -1)
{
free_info(info, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
/* TODO: PUT ERROR FUNCTION */
}
else
{
wait(&(info->status));
if (WIFEXITED(info->status))
{
info->status = WEXITSTATUS(info->status);
if (info->status == 126)
print_error(info, "Permission denied\n");
}
}
}

