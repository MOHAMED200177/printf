#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


int _printf(const char *format, ...);
int _strlen(char *s);
int print_char(char a, int count);
int print_string(char *a, int count);
int print_int(int num, int count);
int power(int base, int pow);



#endif
