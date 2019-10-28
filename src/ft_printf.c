/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/28 15:56:02 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "stdbool.h"

static char	ft_remap(int n)
{
	if (n >= 0 && n <= 9)
		return ((char)('0' + n));
	else
		return ((char)(n - 10 + 'a'));
}

static char	*ft_convert_base(unsigned int num, int base)
{
	char digits[] = "0123456789abcdef";
	char buffer[50];
	char *ptr;

	ptr = &buffer[49];
	*ptr = '\0';
	while (num > 0)
	{
		*--ptr = digits[num % base];
		num /= base;
	}
	return(ptr);
}

/*
** You have to manage the following conversions: csp
** You have to manage the following conversions:
**						diouxX with the following flags: hh, h, l and ll.
** You have to manage the following conversion:
**						f with the following flags: l and L.
** You must manage %%
** You must manage the flags #0-+ and space
** You must manage the minimum field-width
** You must manage the precision
**
** %[flags][width][.precision][length]specifier
*/

static void	ft_init_flags(t_flags *flags)
{
	if (!flags)
	{
		// Malloc??
	}
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
}

int			ft_printf(const char *format,  ...)
{
	int				i;
	va_list			valist;
	char			*fstr;
	int				len;
	bool			parsing_flags;
	t_flags			*flags;

	fstr = (char*)format;
	va_start(valist, format);

	flags = (t_flags*)malloc(sizeof(t_flags));

	len = ft_strlen(format);
	i = 0;
	parsing_flags = true;
	while (*fstr != '\0')
	{
		if (*fstr == '%')
		{
			fstr++;
			/*
			** Parse flags first
			*/
			ft_init_flags(flags);
			while (parsing_flags)
			{
				if (*fstr == '#') { flags->hash = true; fstr++; }
				else if (*fstr == '0') { flags->zero = true; fstr++; }
				else if (*fstr == '-') { flags->minus = true; fstr++; }
				else if (*fstr == '+') { flags->plus = true; fstr++; }
				else if (*fstr == ' ') { flags->space = true; fstr++; }
				else { parsing_flags = false; }
			}

			if (*fstr == 'c')
			{
				int value = va_arg(valist, int);
				ft_output_c(value, flags);
			}
			if (*fstr == 's')
			{
				char *value = va_arg(valist, char *);
				ft_output_s(value, flags);
			}
			if (*fstr == 'p')
			{
				unsigned long value = va_arg(valist, unsigned int);
				ft_output_p(value, flags);
			}
			if (*fstr == 'd')
			{
				int i = va_arg(valist, int);
				ft_output_di(i, flags);
			}
			if (*fstr == 'i')
			{
				int i = va_arg(valist, int);
				ft_output_di(i, flags);
			}
			if (*fstr == 'o')
			{
				int i = va_arg(valist, unsigned int);
				ft_output_o(ft_atoi(ft_convert_base(i, 8)), flags);
			}
			if (*fstr == 'u')
			{
				ft_putnbr(va_arg(valist, int));
			}
			if (*fstr == 'x')
			{
				int a = va_arg(valist, unsigned int);
				ft_output_x_low(a, flags);
			}
			if (*fstr == 'X')
			{
				int a = va_arg(valist, unsigned int);
				ft_output_x_up(a, flags);
			}
		}
		else
		{
			ft_putchar(*fstr);
		}
		fstr++;
	}
	va_end(valist);
	free(flags);
	return (0);
}
