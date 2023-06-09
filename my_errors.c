#include "shell.h"

/**
* _erratoi - This function converts a string to integer
* @s: The pointer here contains string to be converted
*
* Return: An integer value for the string
* Negative one if an error occurred in a conversion
*/
int _erratoi(char *s)
{
int i;
unsigned long int result = 0;

if (*s == '+')
s++; /* Skip the '+' character */

for (i = 0; s[i] != '\0'; i++)
{
/* Check if the character is a digit */
if (s[i] >= '0' && s[i] <= '9')
{
/* Convert the character to an integer and add it to the result */
result *= 10;
result += (s[i] - '0');

/* Check if the result is too large to fit in an int */
if (result > INT_MAX)
return (-1);
}
else
{
/* If a non-digit character is encountered, return an error */
return (-1);
}
}

/* Return the converted integer value */
return (result);
}
/**
* print_error - This function prints an error message
* @info: This is the parameter and return information struct
* @estr: string containing specified error type
* Return: 0 if no numbers in string, converted number otherwise
* -1 on error
*/
void print_error(info_t *info, char *estr)
{
_eputs(info->fname);
_eputs(": ");
print_d(info->line_count, STDERR_FILENO);
_eputs(": ");
_eputs(info->argv[0]);
_eputs(": ");
_eputs(estr);
}

/**
* print_d - prints a decimal (integer) number (base 10)
* @input: the number to be printed
* @fd: the filedescriptor to write to
*
* Return: number of characters printed
*/
int print_d(int input, int fd)
{
int count = 0;
unsigned int _abs_;
int i, current, leading_zeroes;

if (fd == STDERR_FILENO)
count += _putsfd("Error: ", STDERR_FILENO);
if (input < 0)
{
_abs_ = -input;
count += _putfd('-', fd);
}
else
{
_abs_ = input;
}

/* count number of digits */
leading_zeroes = 1;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
leading_zeroes = 0;
break;
}
}

/* print digits */
current = _abs_;
for (i = 1000000000; i >= 1; i /= 10)
{
if (current / i || i == 1 || !leading_zeroes)
{
count += _putfd('0' + current / i, fd);
leading_zeroes = 0;
}
current %= i;
}

return (count);
}


/**
* convert_number - function that converts a number to a string
* representation
* @num: number to convert
* @base: base of the number
* @flags: argument flags
*
* Return: string representation of the number
*/
char *convert_number(long int num, int base, int flags)
{
static char *digits;
static char buffer[50];
char sign = 0;
char *ptr;
unsigned long n = num;

if (!(flags & CONVERT_UNSIGNED) && num < 0)
{
n = -num;
sign = '-';
}

digits = flags & CONVERT_LOWERCASE ?
"0123456789abcdef" : "0123456789ABCDEF";
ptr = &buffer[49];
*ptr = '\0';

do {
*--ptr = digits[n % base];
n /= base;
} while (n != 0);

if (sign)
*--ptr = sign;

return (ptr);
}

/**
* remove_comments - This function replaces first instance of '#' with '\0'
* @str: pointer to the string to modify
*
* Return: Always void
*/
void remove_comments(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
{
if (str[i] == '#' && (i == 0 || str[i - 1] == ' '))
{
str[i] = '\0';
break;
}
}
}

