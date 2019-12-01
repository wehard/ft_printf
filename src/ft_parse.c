/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:48:44 by wkorande          #+#    #+#             */
/*   Updated: 2019/12/01 15:03:16 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_parse_flags(char **fstr, t_flags *flags)
{
	if (*(*fstr) == '#')
		flags->hash = 1;
	else if (*(*fstr) == '0')
	{
		flags->zero = 1;
		flags->zero_specified = 1;
	}
	else if (*(*fstr) == '-')
		flags->minus = 1;
	else if (*(*fstr) == '+')
		flags->plus = 1;
	else if (*(*fstr) == ' ')
		flags->space = 1;
	else
		return (0);
	(*fstr)++;
	return (1);
}

int		ft_parse_width(char **fstr, t_flags *flags, va_list valist)
{
	int w;

	if ((w = ft_atoi(*fstr)) > 0 || *(*fstr) == '*')
	{
		if (*(*fstr) == '*')
		{
			w = va_arg(valist, int);
			if (w < 0)
				flags->minus = 1;
			flags->width = (w < 0 ? w * -1 : w);
			flags->width_specified = 1;
			w = 1;
		}
		else
		{
			flags->width = w;
			flags->width_specified = 1;
		}
		(*fstr) += ft_ndigits(w);
		return (1);
	}
	return (0);
}

int		ft_parse_precision(char **fstr, t_flags *flags, va_list valist)
{
	if (*(*fstr) == '.')
	{
		flags->precision_specified = 1;
		flags->precision = 0;
		(*fstr)++;
		if (ft_isdigit(*(*fstr)))
		{
			while (ft_isdigit(*(*fstr)))
			{
				flags->precision = flags->precision * 10 + (*(*fstr) - '0');
				(*fstr)++;
			}
		}
		else if (*(*fstr) == '*')
		{
			flags->precision = va_arg(valist, int);
			(*fstr)++;
		}
		return (1);
	}
	return (0);
}

int		ft_parse_length(char **fstr, t_flags *flags)
{
	if (*(*fstr) == 'h')
	{
		if (*(*fstr + 1) == 'h' && (*fstr)++)
			flags->length = LEN_HH;
		else
			flags->length = LEN_H;
		(*fstr)++;
		return (1);
	}
	else if (*(*fstr) == 'l')
	{
		if (*(*fstr + 1) == 'l' && (*fstr)++)
			flags->length = LEN_LL;
		else
			flags->length = LEN_L;
		(*fstr)++;
		return (1);
	}
	else if (*(*fstr) == 'L')
	{
		flags->length = LEN_LD;
		(*fstr)++;
		return (1);
	}
	return (0);
}
