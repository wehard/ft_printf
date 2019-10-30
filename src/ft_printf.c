/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/30 11:53:52 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

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

int	ft_printf(const char *format, ...)
{
	va_list		valist;
	char		*fstr;
	t_flags		*flags;
	int			bytes;

	if (!(flags = ft_create_flags()))
		return (-1);
	fstr = (char*)format;
	bytes = 0;
	va_start(valist, format);
	while (*fstr != '\0')
	{
		if (*fstr == '%')
		{
			fstr++;
			ft_init_flags(flags);
			ft_parse_flags(&fstr, flags);
			ft_parse_width(&fstr, flags);
			ft_parse_precision(&fstr, flags);

			if (*fstr == '%')
				ft_outchar("%", 1);
			if (*fstr == 'c')
				ft_handle_c(va_arg(valist, int), flags);
			if (*fstr == 's')
				bytes += ft_handle_s(va_arg(valist, char *), flags);
			if (*fstr == 'p')
			{
				void *value = va_arg(valist, void *);
				ft_handle_p(*(uintmax_t*)&value, flags);
			}
			if (*fstr == 'd' || (*fstr == 'i'))
				ft_handle_di(va_arg(valist, int), flags);
			if (*fstr == 'o')
				ft_handle_o(va_arg(valist, int), flags);
			if (*fstr == 'u')
				ft_handle_u(va_arg(valist, unsigned int), flags);
			if (*fstr == 'x')
				ft_handle_x_low(va_arg(valist, unsigned int), flags);
			if (*fstr == 'X')
				ft_handle_x_up(va_arg(valist, unsigned int), flags);
			if (*fstr == 'f')
				ft_handle_f(va_arg(valist, double), flags);
		}
		else
		{
			ft_putchar(*fstr);
			bytes++;
		}
		fstr++;
	}
	va_end(valist);
	free(flags);
	return (bytes);
}
