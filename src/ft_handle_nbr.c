/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/20 13:16:39 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_di(t_p_buf *dest, va_list valist, t_flags *flags)
{
	char	*str;
	char	*tmp;
	int64_t	n;
	int		bytes;
	size_t	len;

	if (flags->length == LEN_HH)
		n = (char)va_arg(valist, int);
	else if (flags->length == LEN_H)
		n = (short)va_arg(valist, int);
	else if (flags->length == LEN_L)
		n = (long)va_arg(valist, int);
	else if (flags->length == LEN_LL)
		n = (long long)va_arg(valist, int);
	else
		n = va_arg(valist, int);
	if (flags->plus && n >= 0)
		ft_set_prefix(flags, "+", 1);
	else if (n > 0 && flags->space)
		ft_set_prefix(flags, " ", 1);
	else if (n < 0)
	{
		flags->plus = 1;
		ft_set_prefix(flags, "-", 1);
	}
	if (flags->precision_specified)
	{
		if (ft_ndigits(n) < flags->precision)
		{
			flags->zero = 1;
			flags->width = flags->precision + ft_ndigits(n);
		}
	}
	str = ft_itoa(n < 0 ? n * -1 : n);
	bytes += ft_format_output(dest, flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_o(t_p_buf *dest, va_list valist, t_flags *flags)
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
	ft_set_prefix(flags, "0", 1);
	str = ft_itoa_base(n, BASE8);
	i = ft_format_output(dest, flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_u(t_p_buf *dest, va_list valist, t_flags *flags)
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
	str = ft_itoa(n);
	i = ft_format_output(dest, flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_f(t_p_buf *dest, va_list valist, t_flags *flags)
{
	char	*str;
	double	d;
	int		i;

	if (flags->precision == 0)
		flags->precision = 6;
	d = va_arg(valist, double);
	str = ft_dtoa(d, flags->precision);
	i = ft_format_output(dest, flags, str, ft_strlen(str));
	free(str);
	return (i);
}
