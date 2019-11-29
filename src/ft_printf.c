/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/29 20:22:32 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

t_sp_type	g_output_types[N_HANDLERS] =
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

int			ft_output_type(va_list valist, char c, t_flags *flags)
{
	int i;
	int bytes;

	bytes = 0;
	i = 0;
	while (i < N_HANDLERS)
	{
		if (g_output_types[i].c == c)
			bytes = g_output_types[i].output_func(flags, valist);
		i++;
	}
	return (bytes);
}

static int	ft_output_format(char **fstr, t_flags *flags, va_list valist)
{
	int bytes;
	int flags_done;

	if (*(*fstr) == '\0')
		return (-1);
	bytes = 0;
	flags_done = 0;
	ft_init_flags(flags);
	while (ft_parse_flags(fstr, flags) ||
					ft_parse_width(fstr, flags, valist) ||
					ft_parse_precision(fstr, flags, valist) ||
					ft_parse_length(fstr, flags))
		flags_done = 1;
	if (*(*fstr) == '\0')
		return (-1);
	bytes += ft_output_type(valist, *(*fstr), flags);
	if (*(*fstr) == '%')
		bytes += ft_handle_percent(flags);
	(*fstr)++;
	return (bytes);
}

static int	ft_output_nonformat(char **fstr)
{
	int bytes;

	bytes = 0;
	while (*(*fstr) && *(*fstr) != '%')
	{
		bytes += ft_outchar(*fstr, 1);
		(*fstr)++;
	}
	return (bytes);
}

int			ft_printf(const char *format, ...)
{
	t_flags		*flags;
	char		*fstr;
	size_t		bytes;
	va_list		valist;

	if (!format)
		return (-1);
	if (*format == '\0')
		return (0);
	if (!(flags = ft_create_flags()))
		return (-1);
	bytes = 0;
	fstr = (char*)format;
	va_start(valist, format);
	while (*fstr)
	{
		if (*fstr == '%' && (fstr++))
			bytes += ft_output_format(&fstr, flags, valist);
		else
			bytes += ft_output_nonformat(&fstr);
	}
	va_end(valist);
	free(flags);
	return (bytes);
}
