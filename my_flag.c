#include "main.h"

/**
 * get_flags - Calculates active flags
 * @format: Formatted string in which to print the arguments
 * @i: take a parameter.
 * Return: Flags:
 */

int get_flags(const char *format, int *i)
{
	int k, cur_i;
	int flags = 0;

	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const char FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (cur_i = *i + 1; format[cur_i] != '\0'; cur_i++)
	{
		for (k = 0; FLAG_CH[k] != '\0'; k++)
			if (format[cur_i] == FLAG_CH[k])
			{
				flags |= FLAG_ARR[k];
				break;
			}
		if (FLAG_CH[k] == 0)
			break;
	}
	*i = cur_i - 1;
	return (flags);
}
