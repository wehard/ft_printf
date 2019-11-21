/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:39 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/21 17:16:38 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_format_output(t_p_buf *dest, t_flags *flags, char *data, int len)
{
	int padding;

	padding = flags->width - len - flags->prefixlen;
	if (flags->minus)
	{
		if (flags->prefix_specified)
			ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
		ft_outchar_buf(dest, data, len);
		while (padding-- > 0)
			ft_outchar_buf(dest, SPACE, 1);
	}
	else
	{
		while (padding-- > 0)
			ft_outchar_buf(dest, SPACE, 1);
		if (flags->prefix_specified)
			ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
		ft_outchar_buf(dest, data, len);
	}
	return (padding + len);
}

int		ft_format_output_w_zero_pad(t_p_buf *dest, t_flags *flags, char *data, int len)
{

	if (flags->precision_specified)
		flags->precision = flags->precision < len ? flags->precision - len : len;
	if (flags->zero_specified)
		flags->zero = len - flags->prefixlen - flags->precision;
	if (flags->width_specified)
		flags->width = flags->width - flags->prefixlen - len;
	if (flags->width_specified)
		while (flags->width-- > 0)
			ft_outchar_buf(dest, SPACE, 1);
	if (flags->prefix_specified)
		ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
	if (flags->precision_specified)
		while (flags->precision-- > 0)
			ft_outchar_buf(dest, ZERO, 1);
	ft_outchar_buf(dest, data, len);
	return (dest->start - dest->at);
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

void	ft_write(char *buf, size_t nbyte)
{
	write(1, buf, nbyte);
}
