/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 16:17:13 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 15:17:31 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_printf(const char *format, ...);

int	main(void)
{
	char c = 'a';
	int *p;
	int a;
	a = 55;
	p = &a;
	//char *str = "%cWorld";
	//printf("%-20s%s", "printf", "ft_printf");
	ft_printf("%10s World: %c\n", "Hello", 'x');
	printf("%10s World: %c\n", "Hello", 'x');
	ft_printf("ft_printf p:%30p\n", &p);
	printf("   printf p:%30p\n", &p);
	ft_printf("ft_printf di: %10d\n", 42);
	printf("   printf di: %10d\n", 42);
	//ft_printf("Hex (ff): %x\n", 255);
	//ft_printf("Hex (FF): %X\n", 255);
	ft_printf("ft_printf o (377): %15o\n", 255);
	printf("   printf o (377): %15o\n", 255);
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
