/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/19 17:22:13 by wkorande         ###   ########.fr       */
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

static int	ft_output_type(t_p_buf *dst, va_list valist, char c, t_flags *flags)
{
	int i;
	int bytes;

	bytes = 0;
	i = 0;
	while (i < N_HANDLERS)
	{
		if (g_output_types[i].c == c)
			bytes = g_output_types[i].output_func(dst, valist, flags);
		i++;
	}
	return (bytes);
}



static t_p_buf	*ft_create_p_buf(char *dest)
{
	t_p_buf *pbuf;

	if (!(pbuf = (t_p_buf*)malloc(sizeof(t_p_buf))))
		return (NULL);
	pbuf->start = dest;
	pbuf->at = dest;
	pbuf->size = 0;
	return (pbuf);
}

static int	ft_parse_formatting_and_output(t_p_buf *pbuf, char **fstr, t_flags *flags, va_list valist)
{
	int flags_done;
	int bytes;

	bytes = 0;
	flags_done = 0;
	ft_init_flags(flags);
	while (ft_parse_flags(fstr, flags) ||
					ft_parse_width(fstr, flags, valist) ||
					ft_parse_precision(fstr, flags, valist) ||
					ft_parse_length(fstr, flags))
		flags_done = 1;
	bytes += ft_output_type(pbuf, valist, *(*fstr), flags);
	(*fstr)++;
	return (bytes);
}

int			ft_vsprintf(char *dest, const char *format, va_list valist)
{
	t_p_buf		*pbuf;
	t_flags		*flags;
	char		*fstr;
	int			bytes;
	int			flags_done;

	if (!(pbuf = (t_p_buf*)malloc(sizeof(t_p_buf))))
		return (-1);
	pbuf->start = dest;
	pbuf->at = dest;
	pbuf->size = 0;
	if (!(flags = ft_create_flags()))
		return (-1);
	flags_done = 0;
	fstr = (char*)format;
	while (*fstr != '\0')
	{
		if (*fstr == '%')
		{
			fstr++;
			ft_parse_formatting_and_output(pbuf, &fstr, flags, valist);
		}
		else
			while (*fstr && *fstr != '%')
				ft_outchar_buf(pbuf, fstr++, 1);
	}
	bytes = pbuf->at - pbuf->start;
	free(flags);
	free(pbuf);
	return (bytes);
}

int			ft_sprintf(char *dest, const char *format, ...)
{
	va_list	valist;
	t_p_buf *pbuf;
	int		bytes;

	va_start(valist, format);
	bytes = ft_vsprintf(dest, format, valist);
	va_end(valist);
	return (bytes);
}

int			ft_printf(const char *format, ...)
{
	char	buffer[PRINT_BUFF_SIZE];
	va_list	valist;
	int		bytes;

	ft_bzero(buffer, PRINT_BUFF_SIZE);
	bytes = 0;
	va_start(valist, format);
	bytes = ft_vsprintf(buffer, format, valist);
	va_end(valist);
	ft_write(buffer, bytes);
	return (bytes);
}
