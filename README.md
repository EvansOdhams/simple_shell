Simple Shell Project
This project is a simple implementation of a UNIX command line shell written in C. It provides basic functionality such as executing commands, handling input/output redirection, and managing pipelines.

Usage
To use the shell, simply compile the source code and run the resulting executable file in your terminal:

$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
$ ./hsh


Once the shell is running, you can enter commands as you would in a normal terminal.

Files
The project is composed of the following files:

shell.h: Header file containing function prototypes and struct definitions.
main.c: Main function that runs the shell and handles user input.
builtins.c: Implementation of built-in shell commands such as cd and exit.
execute.c: Functions that execute commands and handle input/output redirection and pipelines.
utils.c: Utility functions such as string manipulation and memory management.
vars.c: Functions that handle variables and aliases in commands.
Limitations
This shell has several limitations and does not implement many advanced features found in modern shells such as job control, command history, and tab completion. Additionally, it has not been extensively tested and may contain bugs or unexpected behavior.

Credits
This shell was developed by the following contributors:

Evance Odhiambo
Humphrew Abwao

License
This project is licensed under the MIT License. See LICENSE for more information.
