/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:39 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/20 18:09:41 by wkorande         ###   ########.fr       */
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
	int width;
	int zeros;

	zeros = 0;
	if (flags->precision_specified)
		zeros = flags->precision - len;
	if (flags->width)
	{
		width = flags->width - len - flags->precision;
		if (flags->prefix_specified)
			width -= flags->prefixlen;
	}
	else
		width = 0;
	if (flags->minus)
	{
		if (flags->prefix_specified)
			ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
		while (zeros-- > 0)
			ft_outchar_buf(dest, ZERO, 1);
		ft_outchar_buf(dest, data, len);
		while (width-- > 0)
			ft_outchar_buf(dest, SPACE, 1);
	}
	else
	{
		if (flags->prefix_specified && flags->zero)
			ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
		while (width-- > 0)
			ft_outchar_buf(dest, flags->zero ? ZERO : SPACE, 1);
		if (flags->prefix_specified && !flags->zero)
			ft_outchar_buf(dest, flags->prefix, flags->prefixlen);
		while (zeros-- > 0)
			ft_outchar_buf(dest, ZERO, 1);
		ft_outchar_buf(dest, data, len);
	}
	return (width + len);
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
