/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:17:13 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/29 18:19:14 by wkorande         ###   ########.fr       */
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
	int bytes;

	SET_COLOR(NORMAL);
	bytes = ft_printf("%c\n", 'c');
	ft_putnbr(bytes);
	ft_putchar('\n');
}
