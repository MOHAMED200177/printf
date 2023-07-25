#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1


#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 *
 * @unsign: flag if unsigned value
 *
 * @plus_flag: on if plus_flag specified
 * @space_flag: on if hashtag_flag specified
 * @hashtag_flag: on if _flag specified
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/* put.c */
int _puts(char *str);
int _putchar(int c);

/* 0-prinf.c */
int _printf(const char *format, ...);

/* number1.c */
int printNum1(va_list args, params_t *params);
int printNum2(va_list args, params_t *params);
int printBinary(va_list args, params_t *params);
int printOctal(va_list args, params_t *params);

/* number2.c */
char *convertNum(long int num, int base, int flags, params_t *params);
int printUnsigned(va_list args, params_t *params);
int printAddress(va_list args, params_t *params);

/* params.c */
void countParams(params_t *params, va_list args);

/* functions.c */
int returnChar(va_list args, params_t *params);
int returnInt(va_list args, params_t *params);
int returnStr(va_list args, params_t *params);
int returnPercent(va_list args, params_t *params);
int sFunction(va_list args, params_t *params);

/* numbers2.c module */
int _isdigit(int c);
int _strlen(char *s);
<<<<<<< HEAD
int returnNum(char *str, params_t *params);
int returnNum1(char *str, params_t *params);
int returnNum2(char *str, params_t *params);

/* printers.c  */
int returnFromTo(char *start, char *stop, char *except);
int returnRev(va_list args, params_t *params);
int returnRot13(va_list args, params_t *params);

/* specifier.c */
int (*printSpecifier(char *s))(va_list args, params_t *params);
int get_print_func(char *s, va_list args, params_t *params);
int printFlag(char *s, params_t *params);
int printModifire(char *s, params_t *params);
char *printWidth(char *s, params_t *params, va_list args);

/* string_fields.c  */
char *printPrecision(char *p, params_t *params, va_list args)
=======
int print_char(char a, int count);
int print_string(char *a, int count);
int _putchar(char c);
>>>>>>> d6be6325f5df6a0b016376d48c9e94f00b73aa5e

#endif
