/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:39 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/29 18:31:35 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int			ft_format(t_flags *flags, char *data, int len)
{
	int bytes;
	int padding;

	bytes = 0;
	padding = flags->width - len - flags->prefixlen;
	if (flags->minus)
	{
		if (flags->prefix_specified)
			bytes += ft_outchar(flags->prefix, flags->prefixlen);
		bytes += ft_outchar(data, len);
		while (padding-- > 0)
			bytes += ft_outchar(SPACE, 1);
	}
	else
	{
		while (padding-- > 0)
			bytes += ft_outchar(SPACE, 1);
		if (flags->prefix_specified)
			bytes += ft_outchar(flags->prefix, flags->prefixlen);
		bytes += ft_outchar(data, len);
	}
	return (bytes);
}

static int	ft_format_zp_left(t_flags *flags, char *data, int len)
{
	int bytes;

	bytes = 0;
	if (flags->prefix_specified)
		bytes += ft_outchar(flags->prefix, flags->prefixlen);
	while (flags->precision_left-- > 0)
		bytes += ft_outchar(ZERO, 1);
	bytes += ft_outchar(data, len);
	while (flags->width_left-- > 0)
		bytes += ft_outchar(flags->zero_specified ? ZERO : SPACE, 1);
	return (bytes);
}

static int	ft_format_zp_right(t_flags *flags, char *data, int len)
{
	int bytes;

	bytes = 0;
	if (flags->zero_specified && flags->prefix_specified)
		bytes += ft_outchar(flags->prefix, flags->prefixlen);
	while (flags->width_left-- > 0)
		bytes += ft_outchar(flags->zero_specified ? ZERO : SPACE, 1);
	if (!flags->zero_specified && flags->prefix_specified)
		bytes += ft_outchar(flags->prefix, flags->prefixlen);
	while (flags->precision_left-- > 0)
		bytes += ft_outchar(ZERO, 1);
	bytes += ft_outchar(data, len);
	return (bytes);
}

int			ft_format_zp(t_flags *flags, char *data, int len)
{
	int bytes;

	bytes = 0;
	flags->precision_left = 0;
	flags->width_left = 0;
	if (flags->precision_specified)
	{
		if (flags->precision > len)
			flags->precision_left = flags->precision - len;
	}
	if (flags->width_specified)
	{
		if (flags->width > len + flags->precision_left + flags->prefixlen)
			flags->width_left =
				flags->width - len - flags->prefixlen - flags->precision_left;
	}
	if (flags->minus)
		bytes += ft_format_zp_left(flags, data, len);
	else
		bytes += ft_format_zp_right(flags, data, len);
	return (bytes);
}

int			ft_outchar(const char *data, unsigned int len)
{
	write(1, data, len);
	return (len);
}
