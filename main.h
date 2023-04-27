#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handle_print(const char *fmt, int *nd, va_list ls, char buff[],
		int flags, int width, int precision, int size);

void print_buf(char buff[], int *buff_n);
int print_char(va_list argument, char buff[],
		int flags, int width, int precision, int size);
int print_str(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_percent(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_int(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_binary(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_unsigned(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_octal(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_hexadecimal(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_hexa_upper(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_hexa(va_list argument, char run_to[], char buff[],
	int flags, char flag_ch, int width, int pec, int size);
int print_pointer(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_non_printable(va_list argument, char buff[],
		int flags, int width, int pec, int size);
int print_reverse(va_list argument, char buff[],
	int flags, int width, int pec, int size);
int print_rot13string(va_list argument, char buff[],
		int flags, int width, int pec, int size);

int figure_flags(const char *format, int *k);
int figure_precision(const char *format, int *j, va_list ls);
int figure_size(const char *format, int *k);
int figure_width(const char *format, int *k, va_list ls);


int hold_view_char(char c, char buff[],
		int flags, int width, int precision, int size);
int view_numb(int is_neg, int nd, char buff[],
		int flags, int width, int pec, int size);
int view_num(int nd, char buff[], int flags,
		int width, int pec, int wen, char ad, char xt_c);
int write_pointer(char buff[], int j, int length,
		int width, int flags, char ad, char xt_c, int ad_start);
int view_unsgnd(int is_neg, int j, char buff[],
		int flags, int width, int pec, int size);

int is_printable(char c);
int add_hexa_code(char ascii_value, char buff[], int j);
int is_digit(char c);
long int change_size_value(long int numb, int size);
long int change_size_unsgnd(unsigned long int numb, int size);


#endif /* MAIN_H */
