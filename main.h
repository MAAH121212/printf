#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define F_MINUS 1
#define F_HASH 8
#define F_ZERO 4
#define F_SPACE 16
#define F_PLUS 2
#define S_LONG 2
#define S_SHORT 1

/**
 * struct format - Struct op
 *
 * @id: the format
 *
 * @f: the function associated
 */

struct format
{
	char *id;
	int (*f)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct fmt fmt_t - Structop
 *
 * @fmt: the format
 * @fmt_t: the function associated.
 */

typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int _putchar(char c);
int handle_print(const char *fmt, int *i, va_list list, char buffer[],
int flags, int width, int precision, int size);

/* Funtions to print chars and strings */

int print_char(va_list types, char buffer[],
int flags, int width, int precision, int size);

int print_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags,
int width, int precicion, int size);

/* Functions to print numbers */

int print_int(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags,
int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[],char buffer[], 
int flags, char flag_ch, int width, int precision, int size);

/* Funcion to print memory address */

int print_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */

int get_flags(const char *format, int *i);
int get_size(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_width(const char *format, int *i, va_list list);

/*Function to print string in reverse*/

int print_reverse(va_list types, char buffer[], int flags, int width,
int precision, int size);

/*Function to print a string in rot 13*/

int print_rot13_string(va_list types, char buffer[], int flags,
int width, int precision, int size);

/* width handler */

int handler_write_char(char c, char buffer[], int flags,
int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width,
int precision, int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
int flags, int width, int precision, int size);
int write_unsned(int is_negative, int ind, char buffer[],
int flags, int width, int precision, int size);

int is_printable(char);

int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsned(unsigned long int num, int size);








#endif