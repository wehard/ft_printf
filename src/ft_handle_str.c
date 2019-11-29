/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/29 18:12:51 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** int	ft_handle_c(int c, t_flags *flags)
*/

int	ft_handle_c(va_list valist, t_flags *flags)
{
	char c;

	c = va_arg(valist, int);
	return (ft_format(flags, &c, 1));
}

int	ft_handle_s(va_list valist, t_flags *flags)
{
	char	*s;
	int		len;

	s = va_arg(valist, char *);
	if (!s)
		s = NULL_STRING;
	if (flags->precision_specified)
		len = ft_min(ft_strlen(s), flags->precision);
	else
		len = ft_strlen(s);
	return (ft_format(flags, s, len));
}
