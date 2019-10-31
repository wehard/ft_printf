/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 12:19:50 by wkorande         ###   ########.fr       */
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

#define N_HANDLERS 10

t_sp_type g_output_types[N_HANDLERS] =
{
	{'c', ft_handle_c},
	{'s', ft_handle_s},
	{'p', ft_handle_p},
	{'d', ft_handle_di},
	{'i', ft_handle_di},
	{'o', ft_handle_o},
	{'u', ft_handle_u},
	{'x', ft_handle_x_low},
	{'X', ft_handle_x_up},
	{'f', ft_handle_f}
};

static int	ft_output_type(va_list valist, char c, t_flags *flags)
{
	int i;

	i = 0;
	while (i < N_HANDLERS)
	{
		if (g_output_types[i].c == c)
			flags->bytes = g_output_types[i].output_func(valist, flags);
		i++;
	}
	return (flags->bytes);
}

void		ft_parse_specifier(char **fstr, t_flags *flags)
{
	ft_init_flags(flags);
	ft_parse_flags(fstr, flags);
	ft_parse_width(fstr, flags);
	ft_parse_precision(fstr, flags);
}

int			ft_printf(const char *format, ...)
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
			ft_parse_specifier(&fstr, flags);
			if (*fstr == '%')
				ft_outchar("%", 1);
			else
				bytes += ft_output_type(valist, *fstr, flags);
		}
		else
			bytes += ft_outchar(fstr, 1);
		fstr++;
	}
	va_end(valist);
	free(flags);
	return (bytes);
}
