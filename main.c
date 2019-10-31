/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:17:13 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 11:29:06 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "ft_printf.h"
#include "libft.h"

int	ft_printf(const char *format, ...);

int	main(void)
{
	int a;
	int *ptr;

	a = 10;
	ptr = &a;

	ft_printf("%10s %c\n", "char", 'x');
	ft_printf("%10s %s\n", "string", "hello");
	ft_printf("%10s %d %i\n", "int", 42, 1234);
	ft_printf("%10s %o\n", "octal", 255);
	ft_printf("%10s %u\n", "uint", 42);
	ft_printf("%10s %.2f\n", "float.2", 3.14);

	ft_printf("%10s %p\n", "pointer", ptr);
	ft_printf("%10s %x\n", "hex", INT32_MAX);
	ft_printf("%10s %X\n", "HEX", INT32_MAX);
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
	//while (1);
	return (0);
}
