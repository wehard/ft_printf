/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/30 17:48:18 by wkorande         ###   ########.fr       */
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

#define N_TYPES 9

t_sp_type g_typetab[N_TYPES] =
{
	{'c', &ft_handle_c},
	{'s', &ft_handle_s},
	{'p', &ft_handle_p},
	{'d', &ft_handle_di},
	{'i', &ft_handle_di},
	{'o', &ft_handle_o},
	{'u', &ft_handle_u},
	{'x', &ft_handle_x_low},
	{'X', &ft_handle_x_up}
};

static int	ft_select_type(va_list valist, char c, t_flags *flags)
{
	int i;

	i = 0;
	while (i < N_TYPES)
	{
		if (g_typetab[i].c == c)
		{
			g_typetab[i].func(valist, *flags);
		}
		i++;
	}

}

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
			else
			{
				ft_select_type(valist, *fstr, flags);

			}
			/* if (*fstr == 'c')
				ft_handle_c(ft_get_va_arg_int(valist), flags);
			if (*fstr == 's')
				bytes += ft_handle_s(ft_get_va_arg_cstr(valist), flags);
			if (*fstr == 'p')
				ft_handle_p(ft_get_va_arg_pointer(valist), flags);
			if ((*fstr == 'd') || (*fstr == 'i') || (*fstr == 'o'))
				ft_handle_di(ft_get_va_arg_int(valist), flags);
			if (*fstr == 'u' || (*fstr == 'x') || (*fstr == 'X'))
				ft_handle_u(ft_get_va_arg_uint(valist), flags);
			if (*fstr == 'f')
				ft_handle_f(ft_get_va_arg_double(valist), flags); */
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
