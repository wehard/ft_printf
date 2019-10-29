/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 17:22:46 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "stdbool.h"

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
		return ;
	flags->hash = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width = 0;
	flags->precision = 6; // ?
}

static t_flags	*ft_create_flags(void)
{
	t_flags *flags;

	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	ft_init_flags(flags);
	return (flags);
}

static void	ft_parse_flags(char **fstr, t_flags *flags)
{
	bool	is_parsing;

	is_parsing = true;
	while (is_parsing)
	{
		if (*(*fstr) == '#')
			flags->hash = true;
		else if (*(*fstr) == '0')
			flags->zero = true;
		else if (*(*fstr) == '-')
			flags->minus = true;
		else if (*(*fstr) == '+')
			flags->plus = true;
		else if (*(*fstr) == ' ')
			flags->space = true;
		else
		{
			is_parsing = false;
			break ;
		}
		(*fstr)++;
	}
}

static void	ft_parse_width(char **fstr, t_flags *flags)
{
	if (ft_isdigit(*(*fstr)))
	{
		flags->width = ft_atoi(*fstr);
	}
	(*fstr) += ft_ndigits(flags->width);
}

static void	ft_parse_precision(char **fstr, t_flags *flags)
{
	if (*(*fstr) == '.')
	{
		(*fstr)++;
		if (ft_isdigit(*(*fstr)))
		{
			flags->precision = ft_atoi(*fstr);
			(*fstr) += ft_ndigits(flags->precision);
		}
	}
}

int			ft_printf(const char *format,  ...)
{
	va_list			valist;
	char			*fstr;

	t_flags			*flags;

	if (!(flags = ft_create_flags()))
		return (-1);
	fstr = (char*)format;
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
				ft_putchar('%');
			if (*fstr == 'c')
				ft_handle_c(va_arg(valist, int), flags);
			if (*fstr == 's')
				ft_handle_s(va_arg(valist, char *), flags);
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
		}
		fstr++;
	}
	va_end(valist);
	free(flags);
	return (0);
}
