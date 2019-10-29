/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 11:05:48 by wkorande         ###   ########.fr       */
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
	flags->precision = 0;
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
		flags->precision = ft_atoi(*fstr);
	}
	(*fstr) += ft_ndigits(flags->precision);
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
				void *value = va_arg(valist, void *);
				ft_output_p(*(uintmax_t*)&value, flags);
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
				int i = va_arg(valist, int);
				ft_output_o(i, flags);
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
