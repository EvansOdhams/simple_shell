#include "shell.h"

/**
* _myexit - sets the exit status value of the program
* @info: struct containing information about the shell and
* command line arguments
*
* Return: -2 to indicate that the shell should exit, or 1 if an error occurs.
*/
int _myexit(info_t *info)
{
int exit_code;

/* Check if an argument has been provided */
if (!info->argv[1])
{
info->err_num = _erratoi(info->argv[1]);
return (-2);
}

/* Convert argument to integer */
exit_code = _erratoi(info->argv[1]);

/* Check if exit code is invalid */
if (exit_code == -1)
{
info->status = 2;
print_error(info, "Invalid exit code: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}

/* Set the exit code */
info->err_num = exit_code;
return (-2);
}

/**
* _mycd - Change the current working directory
* @info: A pointer to the info_t structure containing
* info about the shell and command line arguments
* This function changes the current working directory
* to either the home directory, the previous directory,
* or the directory specified in the command line arguments.
* It also sets the value of the PWD and OLDPWD environment
* variables.
* Return: Always 0
*/
int _mycd(info_t *info)
{
char *dir;
int chdir_ret;

/* If no argument provided, go to home directory */
if (!info->argv[1])
{
chdir_ret = chdir((dir = _getenv(info, "HOME=")) ? dir : "/");
}
/* If argument is "-", go to previous directory */
else if (_strcmp(info->argv[1], "-") == 0)
{
chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
}
/* Otherwise, go to the specified directory */
else
{
chdir_ret = chdir(info->argv[1]);
}
/* Check if change directory was successful */
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
{
/* Set the value of the PWD and OLDPWD environment variables */
_setenv(info, "OLDPWD", _getenv(info, "PWD="));
}

return (0);
}

/**
* _myhelp - This function alters the current directory of the procedure
* @info: This pointer contains arguments will are used
* to maintain constant function prototype.
* Return: Always (0)
*/
int _myhelp(info_t *info)
{
/*  Pointer to array of arguments */
char **args = info->argv;

/* Display message indicating that the help function is not yet implemented */
_puts("The help function is not yet implemented.\n");

if (0)
{
/* Temporary workaround to avoid unused variable warning */
_puts(*args);
}
/* Return success */
return (0);
}

