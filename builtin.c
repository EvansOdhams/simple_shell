#include "shell.h"

/**
* _myexit - set the exit status value of the program
* @info: information about the shell and command line arguments
*
* Return: -2 to indicate that the shell should exit, or 1 if an error occurs.
*/
int _myexit(info_t *info)
{
int exitcheck;

if (info->argv[1])
exitcheck = _erratoi(info->argv[1]);

/* Check if exit code is invalid */
if (exitcheck == -1)
{
info->status = 2;
print_error(info, "Illegal number: ");
_eputs(info->argv[1]);
_eputchar('\n');
return (1);
}

/* Set the exit code */
info->err_num = _erratoi(info->argv[1]);
return (-2);
}


/**
* _mycd - change the current working directory
* @info: information about the shell and command line arguments
*
* Return: always 0
*/
int _mycd(info_t *info)
{
char *dir;
int chdir_ret;

/* If no argument provided, go to home directory */
if (!info->argv[1])
chdir_ret = chdir((dir = _getenv(info, "HOME=")) ? dir : "/");
/* If argument is "-", go to previous directory */
else if (_strcmp(info->argv[1], "-") == 0)
chdir_ret = chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
/* Otherwise, go to the specified directory */
else
chdir_ret = chdir(info->argv[1]);

/* Check if change directory was successful */
if (chdir_ret == -1)
{
print_error(info, "can't cd to ");
_eputs(info->argv[1]), _eputchar('\n');
}
else
/* Set the value of the PWD and OLDPWD environment variables */
_setenv(info, "OLDPWD", _getenv(info, "PWD="));

return (0);
}


/**
* _myhelp - display help information
* @info: information about the shell and command line arguments
*
* Return: always 0
*/
int _myhelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_puts("help call works. Function not yet implemented \n");
if (0)
_puts(*arg_array); /* temp att_unused workaround */
return (0);
}
