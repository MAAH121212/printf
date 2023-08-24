#include "main.h"

/**
 * _puts - print a string with a new line
 * @str: the string to print
 * Return: void
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _putchar - writes the character c to stdout
 * @c: the character to print
 *
 * Return: on Success 1
 * On error, -1 is returned, and errno is set appropriately
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUFF_SIZE];

	if (c == BUFF_FLUSH || i >= OUTPUT_BUFF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUFF_FLUSH)
		buf[i++] = c;
	return (1);
}
