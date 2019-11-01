/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:39 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/01 14:07:24 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_format_output(t_p_buf *dest, t_flags *flags, char *data, int len)
{
	int spaces;

	spaces = flags->width - len - flags->prefixlen;
	if (flags->minus)
	{
		if (flags->plus || flags->space)
			ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
		ft_outchar_buf(dest, data, len);
		while (spaces-- > 0)
			ft_outchar_buf(dest, " ", 1);
	}
	else
	{
		while (spaces-- > 0)
			flags->zero ?\
				ft_outchar_buf(dest, ZERO, 1) : ft_outchar_buf(dest, SPACE, 1);
		if (flags->hash || flags->plus)
			ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
		ft_outchar_buf(dest, data, len);
	}
	return (spaces + len);
}

int		ft_outchar_buf(t_p_buf *dest, const char *data, unsigned int len)
{
	while (len)
	{
		*(dest->at++) = *(data++);
		len--;
	}
	return (len);
}
