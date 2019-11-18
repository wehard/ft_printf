/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:17:13 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/18 19:09:50 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

#define SET_COLOR(color) ft_printf(color)
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

	ft_printf("%-10s\n", info);

	SET_COLOR(BLUE);
	ft_printf("%12s", "printf: ");

	SET_COLOR(GRAYWHITE);
	ft_putstr(buf1);
	SET_COLOR(NORMAL);
	ft_putchar('\n');

	SET_COLOR(WHITE);
	ft_printf("%12s", "ft_printf: ");
	SET_COLOR(WHITEBLACK);
	ft_putstr(buf2);
	SET_COLOR(NORMAL);
	ft_putchar('\n');
	ft_putchar('\n');
	return (1);
}

int	main(void)
{
	int a;
	int *ptr;

	a = 10;
	ptr = &a;
	//int c = 200;
	//ft_printf("%d", 200);

	test_ft_printf("Characters: ", "%c %c", 'a', 65);
	test_ft_printf("Decimals: ", "%d %ld", 1977, 650000L);
	test_ft_printf("Preceding with blanks: ", "%10d", 1977);
	test_ft_printf("Preceding with zeros: ", "%010d", 1977);
	test_ft_printf("Some different radices: ", "%d %x %o %#x %#o", 100, 100, 100, 100, 100);
	test_ft_printf("floats: ", "%4.2f %.6f", 3.1416, 3.1416);
	test_ft_printf("Width trick: ", "%*d", 5, 10);
	test_ft_printf("", "%s", "A string");
	test_ft_printf("", "%50p", ptr);

	test_ft_printf("", "%-5c", 'c');
	return (0);
}
