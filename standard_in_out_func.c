#include "shell.h"

/**
 * _putchar - prints a given character to stdout
 * @c: character given
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - prints a string to stdout.
 * @str: string given.
 *
 * Return: Nothing.
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
}

