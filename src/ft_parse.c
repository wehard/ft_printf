/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:48:44 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 16:14:46 by wkorande         ###   ########.fr       */
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
	flags->bytes = 0;
	flags->prefix = NULL;
	flags->prefixlen = 0;
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

void	ft_parse_width(char **fstr, t_flags *flags)
{
	if (ft_isdigit(*(*fstr)))
	{
		flags->width = ft_atoi(*fstr);
	}
	(*fstr) += ft_ndigits(flags->width);
}

void	ft_parse_precision(char **fstr, t_flags *flags)
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
