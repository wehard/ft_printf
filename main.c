/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:17:13 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/02 16:45:52 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

#define SET_COLOR(color) ft_printf(color)
#define BLUE "\033[22;34m"
#define YELLOW "\033[22;33m"
#define BLACK "\033[30;107m"
#define NORMAL "\033[0;0m"

int	ft_printf(const char *format, ...);
int	ft_vsprintf(char *dest, const char *format, va_list valist);

static int test_ft_printf(char *format, ...)
{
	char buf1[PRINT_BUFF_SIZE];
	char buf2[PRINT_BUFF_SIZE];

	va_list valist1;
	va_list valist2;

	ft_bzero(buf1, PRINT_BUFF_SIZE);
	ft_bzero(buf2, PRINT_BUFF_SIZE);

	va_start(valist1, format);
	va_copy(valist2, valist1);
	vsprintf(buf1, format, valist1);
	ft_vsprintf(buf2, format, valist2);
	va_end(valist1);
	va_end(valist2);

	ft_putstr(buf1);
	ft_putstr(" vs ");
	ft_putstr(buf2);
	ft_putchar('\n');
	return (1);
}


int	main(void)
{
	int a;
	int *ptr;

	a = 10;
	ptr = &a;

	SET_COLOR(BLUE);
	ft_printf("printf:\n");
	printf("Characters: %c %c \n", 'a', 65);
	printf("Decimals: %d %ld\n", 1977, 650000L);
	printf("Preceding with blanks: %10d \n", 1977);
	printf("Preceding with zeros: %010d \n", 1977);
	printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf("floats: %4.2f %.6f \n", 3.1416, 3.1416);
	printf("Width trick: %*d \n", 5, 10);
	printf("%s \n", "A string");

	SET_COLOR(YELLOW);
	ft_printf("\nft_printf:\n");
	ft_printf("Characters: %c %c \n", 'a', 65);
	ft_printf("Decimals: %d %ld\n", 1977, 650000L);
	ft_printf("Preceding with blanks: %10d \n", 1977);
	ft_printf("Preceding with zeros: %010d \n", 1977);
	ft_printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	ft_printf("floats: %4.2f %.6f \n", 3.1416, 3.1416);
	ft_printf("Width trick: %*d \n", 5, 10);
	ft_printf("%s \n", "A string");

	SET_COLOR(NORMAL);
	ft_printf("\nflag test:\n");
	ft_printf("%010i\n", 42);
	ft_printf("%10s\n", "hello");

	test_ft_printf("%s", "hello world");

	//ft_printf("\033[22;34mHello, \033[22;33mworld!\033[0m\n");
	//ft_printf("%10s %c\n", "char", 'x');
	//ft_printf("%10s %20.3s\n", "string", "hello");
	//printf("%10s %20.3s\n", "std", "hello");
	//ft_printf("%10s %05d %05i\n", "int", 42, 1234);
	//ft_printf("%10s %o\n", "octal", 255);
	//ft_printf("%10s %u\n", "uint", 42);
	//ft_printf("%10s %.4f\n", "float.4", 3.141592);
//
	//ft_printf("%10s %p\n", "pointer", ptr);
	//ft_printf("%10s %#x\n", "hex", INT32_MAX);
	//ft_printf("%10s %#X\n", "HEX", INT32_MAX);
	//ft_printf("'%+15d'\n", 10);
	//printf("'%+15d'\n", 10);
	//ft_printf("'%- 15d'\n", 10);
	//printf("'%- 15d'\n", 10);
	//char c = 'a';
	//int *p;
	//int a;
	//a = 55;
	//p = &a;
	//char *str = "%cWorld";
	//printf("%-20s%s", "printf", "ft_printf");
	//ft_printf("%10s World: %c\n", "Hello", 'x');
	//printf("%10s World: %c\n", "Hello", 'x');
	//ft_printf("ft_printf p:%30p\n", &p);
	//printf("   printf p:%30p\n", &p);
	//ft_printf("ft_printf di: %+05d\n", 55);
	//printf("   printf di: %+05d\n", 55);

	// hex
	//int h = 2147483647;
	//char *f = "hex (ff FF): [%#5x] [%#5X]\n";
	//ft_printf("%10s", "ft_printf:");
	//ft_printf(f, h, h);
	//printf("%10s", "printf:");
	//printf(f, h, h);


	//ft_printf("ft_printf o (377): %15o\n", 255);
	//printf("   printf o (377): %15o\n", 255);

	// Float
	//double d = 1234.56789;
	//ft_printf("ft_printf f: %-50.3f\n", d);
	//printf("   printf f: %-50.3f\n", d);
	//printf("\n");

	//int l1 = ft_printf("%10s\n", "hello");
	//int l2 = printf("%10s\n", "hello");

	//ft_printf("\n\n");
	//ft_printf("ft_printf %d", l1);
	//ft_printf("   printf %d", l2);

	//ft_printf("\n\n");
	//ft_printf("%s", ft_dtoa(-3.1456, 2));

	//printf("Octal (377): %o\n", 255);
	//printf("%s World: %x %p", "Hello", 15, &p);
	//ft_printf("%x\n", 16);
	//printf(str, "Hello");
	//printf("\n");
	//printf("Characters: %c %c \n", 'a', 65);
	//printf("Decimals: %d %ld\n", 1977, 650000L);
	//printf("Preceding with blanks: %10d \n", 1977);
	//printf("Preceding with zeros: %010d \n", 1977);
	//ft_printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	//printf("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	//printf("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	//printf("Width trick: %*d \n", 5, 10);
	//printf("%s \n", "A string");
	return (0);
}
