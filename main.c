/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:17:13 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/22 18:07:59 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

#define SET_COLOR(color) ft_putstr(color)
#define WHITEBLACK "\033[107;30m"
#define GRAYWHITE "\033[97;100m"
#define BLUE "\033[22;34m"
#define YELLOW "\033[22;33m"
#define BLACK "\033[30;107m"
#define NORMAL "\033[0;0m"
#define WHITE "\033[97;49m"
#define RESET "\033[0m"

int	ft_printf(const char *format, ...);
int	ft_vsprintf(char *dest, const char *format, va_list valist);

static int test_ft_printf(char *info, char *format, ...)
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

	ft_putendl(info);

	SET_COLOR(BLUE);
	ft_putstr("printf:    ");

	SET_COLOR(GRAYWHITE);
	ft_putstr(buf1);
	SET_COLOR(NORMAL);
	ft_putchar('\n');

	SET_COLOR(WHITE);
	ft_putstr("ft_printf: ");
	SET_COLOR(WHITEBLACK);
	ft_putstr(buf2);
	SET_COLOR(NORMAL);
	ft_putchar('\n');
	ft_putchar('\n');
	return (1);
}

int	main(void)
{
	//int a;
	//int *ptr;

	//a = 10;
	//ptr = &a;
	//int c = 200;
	//ft_printf("%d", 200);

	//test_ft_printf("", "%3c", 'c');
	//test_ft_printf("Characters: ", "%c %c", 'a', 65);
	//test_ft_printf("Decimals: ", "%d %ld", 1977, 650000L);
	//test_ft_printf("Preceding with blanks: ", "%10d", 1977);
	//test_ft_printf("Preceding with zeros: ", "%010d", 1977);
	//test_ft_printf("Some different radices: ", "%d %x %o %#x %#o", 100, 100, 100, 100, 100);
	//test_ft_printf("floats: ", "%4.2f %.6f", 3.1416, 3.1416);
	//test_ft_printf("Width trick: ", "%*d", 5, 10);
	//test_ft_printf("", "%s", "A string");
	//test_ft_printf("", "%50p", NULL);

	//test_ft_printf("", "%-5c", 'c');
	//test_ft_printf("test", "%s", "hello");
	//test_ft_printf("test", "hello, %s", "gavin");
	//test_ft_printf("test", "hello, %s.", NULL);
	//test_ft_printf("d_width_as_zero", "%+7d", 0);
	//test_ft_printf("d_prec_fits_pos", "%.5d", 2);
	//test_ft_printf("s_prec_09_no_width_s_hidden", "%.09s", "hi low");

	//test_ft_printf("", "this %d number", -267);
	//test_ft_printf("%.6d, -3", "%.6d", -3);
	//test_ft_printf("%-7d -14", "%-7d", -14);
	//test_ft_printf("%.5d 2", "%.5d", 2);
	//test_ft_printf("%+.7d 234", "%+.7d", 234);
	//test_ft_printf("%7d, -14", "%7d", -14);
	//test_ft_printf("%+18.5d 34", "%+18.5d", 34);
	//test_ft_printf("%8.5d, 34", "%8.5d", 34);
	SET_COLOR(NORMAL);
	test_ft_printf("", "%+10.3d", 1234);
	test_ft_printf("", "%07d", -54);
	test_ft_printf("", "%08.5d", 34);
	test_ft_printf("", "% 0+-3.3d", 6983);
	test_ft_printf("", "%5.0d", 0);
	test_ft_printf("long_max", "%ld", __INT64_MAX__);
	test_ft_printf("long_min", "%ld", INT64_MIN);
	test_ft_printf("", "%.0o", 0);
	test_ft_printf("", "%.0d", 0);
	test_ft_printf("f", "%f", 573.924);
	return (0);
}
