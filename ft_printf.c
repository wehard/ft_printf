/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/26 23:23:07 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/includes/libft.h"

static int	is_arg(char *str)
{
	if (*str == '%' && *(str + 1) != '\0')
	{
		if (*(str + 1) == 'c' || *(str + 1) == 's' || *(str + 1) == 'p')
			return (1);
	}
	return (0);
}

static int	ft_countargs(char *str)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (is_arg(str + i))
			n++;
		i++;
	}
	return (n);
}

static char ft_remap(int n)
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
	while(num > 0)
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
*/

int			ft_printf(const char *format,  ...)
{
	int	i;
	va_list			valist;
	char			*str;
	char			*s;
	int				len;

	str = (char*)format;
	va_start(valist, format);

	len = ft_strlen(format);
	i = 0;
	while (i < len)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'c')
			{
				ft_putchar(va_arg(valist, int));
			}
			if (format[i] == 's')
			{
				s = va_arg(valist, char *);
				ft_putstr(s);
			}
			if (format[i] == 'p')
			{
				int a = va_arg(valist, unsigned int);
				ft_putstr(ft_convert_base(a, 16));
			}
			if (format[i] == 'i')
			{
				ft_putnbr(va_arg(valist, int));
			}
			if (format[i] == 'x')
			{
				int a = va_arg(valist, unsigned int);
				ft_putstr(ft_convert_base(a, 16));
			}
		}
		else
		{
			ft_putchar(format[i]);
		}
		i++;

	}
	va_end(valist);
	//ft_putchar('\n');
	return (0);
}
