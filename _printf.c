#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Our custom printf function
 * @format: The format string
 * @...: Variable number of arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	int i = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
				return (-1);
			if (format[i] == 'c')
				printed += _putchar(va_arg(args, int));
			else if (format[i] == 's')
				printed += _puts(va_arg(args, char *));
			else if (format[i] == 'd' || format[i] == 'i')
				printed += _putint(va_arg(args, int));
			else
			{
				_putchar('%');
				_putchar(format[i]);
				printed += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			printed++;
		}
		i++;
	}
	va_end(args);
	return (printed);
}

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: The number of characters printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - Writes a string to stdout
 * @str: The string to print
 *
 * Return: The number of characters printed
 */
int _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}

	return (i);
}

/**
 * _putint - Writes an integer to stdout
 * @n: The integer to print
 *
 * Return: The number of characters printed
 */
int _putint(int n)
{
	int printed = 0;

	if (n < 0)
	{
		_putchar('-');
		printed++;
		n = -n;
	}

	if (n / 10)
	{
		printed += _putint(n / 10);
	}

	_putchar(n % 10 + '0');

	return (printed + 1);
}
