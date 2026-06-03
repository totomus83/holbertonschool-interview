#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * is_digits - Checks if a string contains only digit characters
 * @s: The string to check
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digits(const char *s)
{
	int i;

	for (i = 0; s[i]; i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * print_error - Prints "Error" followed by newline and exits with code 98
 */
void print_error(void)
{
	write(1, "Error\n", 6);
	exit(98);
}

/**
 * multiply - Multiplies two non-negative integer strings
 * @a: First number as a string
 * @b: Second number as a string
 *
 * Return: Pointer to a heap-allocated string with the result
 */
char *multiply(const char *a, const char *b)
{
	int la, lb, i, j, digit, pos, total;
	char *result;

	la = strlen(a);
	lb = strlen(b);
	total = la + lb;
	result = calloc(total + 1, sizeof(char));
	if (!result)
		return (NULL);

	for (i = la - 1; i >= 0; i--)
	{
		for (j = lb - 1; j >= 0; j--)
		{
			pos = (la - 1 - i) + (lb - 1 - j);
			digit = (a[i] - '0') * (b[j] - '0') + result[pos];
			result[pos] = digit % 10;
			result[pos + 1] += digit / 10;
		}
	}

	/* reverse: result is stored least-significant first */
	for (i = 0; i < total / 2; i++)
	{
		char tmp = result[i];

		result[i] = result[total - 1 - i];
		result[total - 1 - i] = tmp;
	}

	/* skip leading zeros (keep at least one digit) */
	i = 0;
	while (i < total - 1 && result[i] == 0)
		i++;

	for (j = 0; i + j < total; j++)
		result[j] = result[i + j] + '0';
	result[j] = '\0';

	return (result);
}

/**
 * main - Entry point for infinite multiplication program
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, exits with 98 on error
 */
int main(int argc, char *argv[])
{
	char *result;
	int i;

	if (argc != 3)
		print_error();

	for (i = 1; i <= 2; i++)
	{
		if (!argv[i][0] || !is_digits(argv[i]))
			print_error();
	}

	result = multiply(argv[1], argv[2]);
	if (!result)
		print_error();

	printf("%s\n", result);
	free(result);
	return (0);
}
