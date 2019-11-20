/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:42:28 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/20 18:27:53 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_p(t_p_buf *dest, va_list valist, t_flags *flags)
{
	char			*str;
	char			*tmp;
	unsigned long	p;
	int				bytes;

	flags->hash = 1;
	ft_set_prefix(flags, "0x", 2);
	p = va_arg(valist, unsigned long);
	if (!p)
		str = "0";
	else
		str = ft_itoa_base_uintmax_t(p, BASE16LOW);
	bytes = ft_format_output(dest, flags, str, ft_strlen(str));
	if (p)
		free(str);
	return (bytes);
}

int	ft_handle_x_low(t_p_buf *dest, va_list valist, t_flags *flags)
{
	char			*str;
	unsigned int	n;
	int				i;
	unsigned int	uintarg;

	uintarg = va_arg(valist, unsigned int);
	if (flags->length == LEN_HH)
		n = (unsigned char)uintarg;
	else if (flags->length == LEN_H)
		n = (unsigned short)uintarg;
	else if (flags->length == LEN_L)
		n = (unsigned long)uintarg;
	else if (flags->length == LEN_LL)
		n = (unsigned long long)uintarg;
	else
		n = uintarg;
	ft_set_prefix(flags, "0x", 2);
	str = ft_itoa_base(n, BASE16LOW);
	i = ft_format_output(dest, flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_x_up(t_p_buf *dest, va_list valist, t_flags *flags)
{
	char			*str;
	unsigned int	n;
	int				i;
	unsigned int	uintarg;

	uintarg = va_arg(valist, unsigned int);
	if (flags->length == LEN_HH)
		n = (unsigned char)uintarg;
	else if (flags->length == LEN_H)
		n = (unsigned short)uintarg;
	else if (flags->length == LEN_L)
		n = (unsigned long)uintarg;
	else if (flags->length == LEN_LL)
		n = (unsigned long long)uintarg;
	else
		n = uintarg;
	ft_set_prefix(flags, "0X", 2);
	str = ft_itoa_base(n, BASE16UP);
	i = ft_format_output(dest, flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_percent(t_p_buf *dest, t_flags *flags)
{
	size_t bytes;

	bytes = ft_format_output_w_zero_pad(dest, flags, PERCENT, 1);
	return (bytes);
}
