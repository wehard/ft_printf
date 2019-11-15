/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:17:13 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/15 13:04:36 by wkorande         ###   ########.fr       */
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

	SET_COLOR(BLUE);
	ft_printf("%12s", "printf: ");
	ft_putendl(buf1);
	SET_COLOR(YELLOW);
	ft_printf("%12s", "ft_printf: ");
	ft_putendl(buf2);
	ft_putchar('\n');
	SET_COLOR(NORMAL);
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

	test_ft_printf("Characters: %c %c", 'a', 65);
	test_ft_printf("Decimals: %d %ld", 1977, 650000L);
	test_ft_printf("Preceding with blanks: %10d", 1977);
	test_ft_printf("Preceding with zeros: %010d", 1977);
	test_ft_printf("Some different radices: %d %x %o %#x %#o", 100, 100, 100, 100, 100);
	test_ft_printf("floats: %4.2f %.6f", 3.1416, 3.1416);
	test_ft_printf("Width trick: %*d", 5, 10);
	test_ft_printf("%s", "A string");
	test_ft_printf("%50p", ptr);

	test_ft_printf("%.2s", "moi");

	return (0);
}
