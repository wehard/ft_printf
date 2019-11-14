/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:48:44 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/14 16:18:58 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "ft_printf.h"

t_flags	*ft_create_flags(void)
{
	t_flags *flags;

	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	ft_init_flags(flags);
	return (flags);
}

void	ft_init_flags(t_flags *flags)
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
	flags->prefix = NULL;
	flags->prefixlen = 0;
	flags->length = LEN_NONE;
}

void	ft_set_prefix(t_flags *flags, char *prefix, int len)
{
	flags->prefix = prefix;
	flags->prefixlen = len;
}

void	ft_parse_flags(char **fstr, t_flags *flags)
{
	int	is_parsing;

	is_parsing = 1;
	while (is_parsing)
	{
		if (*(*fstr) == '#')
			flags->hash = 1;
		else if (*(*fstr) == '0')
			flags->zero = 1;
		else if (*(*fstr) == '-')
			flags->minus = 1;
		else if (*(*fstr) == '+')
			flags->plus = 1;
		else if (*(*fstr) == ' ')
			flags->space = 1;
		else
		{
			is_parsing = 0;
			break ;
		}
		(*fstr)++;
	}
}

void	ft_parse_width(char **fstr, t_flags *flags, va_list valist)
{
	if (*(*fstr) == '*')
	{
		flags->width = va_arg(valist, int);
		(*fstr)++;
		return ;
	}
	if (ft_isdigit(*(*fstr)))
	{
		flags->width = ft_atoi(*fstr);
	}
	(*fstr) += ft_ndigits(flags->width);
}

void	ft_parse_precision(char **fstr, t_flags *flags, va_list valist)
{
	if (*(*fstr) == '.')
	{
		(*fstr)++;
		if (ft_isdigit(*(*fstr)))
		{
			flags->precision = ft_atoi(*fstr);
			(*fstr) += ft_ndigits(flags->precision);
		}
		else if (*(*fstr) == '*')
		{
			flags->precision = va_arg(valist, int);
			(*fstr)++;
		}
	}
}

void	ft_parse_length(char **fstr, t_flags *flags)
{
	if (*(*fstr) == 'h')
	{
		if (*(*fstr + 1) == 'h')
		{
			flags->length = LEN_HH;
			(*fstr)++;
		}
		else
			flags->length = LEN_H;
		(*fstr)++;
	}
	else if (*(*fstr) == 'l')
	{
		if (*(*fstr + 1) == 'l')
		{
			flags->length = LEN_LL;
			(*fstr)++;
		}
		else
			flags->length = LEN_L;
		(*fstr)++;
	}
	else if (*(*fstr) == 'L')
	{
		flags->length = LEN_LD;
		(*fstr)++;
	}
}
