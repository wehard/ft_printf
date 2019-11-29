/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/29 19:40:28 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_di(t_flags *flags, va_list valist)
{
	char	*str;
	char	*tmp;
	int64_t	n;
	int		bytes;
	size_t	len;

	n = ft_cast_signed(flags->length, valist);
	if (n < 0)
		ft_set_prefix(flags, "-", 1);
	else
	{
		if (flags->plus)
			ft_set_prefix(flags, "+", 1);
		if (!flags->plus && flags->space)
			ft_set_prefix(flags, " ", 1);
	}
	if (flags->precision_specified)
		flags->zero_specified = 0;
	if (flags->precision_specified && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_uint64(n < 0 ? (uint64_t)(n * -1) : (uint64_t)n);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_o(t_flags *flags, va_list valist)
{
	char		*str;
	uint64_t	n;
	int			bytes;

	n = ft_cast_unsigned(flags->length, valist);
	if (flags->precision_specified)
	{
		flags->zero_specified = 0;
		flags->precision -= (n != 0) ? flags->hash : 0;
	}
	if (flags->hash && n != 0)
		ft_set_prefix(flags, ZERO, 1);
	if (flags->precision_specified && flags->precision == 0 && !flags->hash)
		str = ft_strdup("");
	else
		str = ft_itoa_base_uint64(n, BASE8);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_u(t_flags *flags, va_list valist)
{
	char		*str;
	uint64_t	n;
	int			bytes;

	n = ft_cast_unsigned(flags->length, valist);
	if (flags->precision_specified)
		flags->zero_specified = 0;
	if (flags->precision_specified && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_uint64(n);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_f(t_flags *flags, va_list valist)
{
	char		*str;
	long double	d;
	int			bytes;

	if (!flags->precision_specified)
		flags->precision = 6;
	d = ft_cast_double(flags->length, valist);
	if (d < 0)
		ft_set_prefix(flags, "-", 1);
	else
	{
		if (flags->plus)
			ft_set_prefix(flags, "+", 1);
		if (!flags->plus && flags->space)
			ft_set_prefix(flags, " ", 1);
	}
	if (flags->minus)
		flags->zero_specified = 0;
	if (flags->hash && flags->precision_specified && flags->precision == 0)
		str = ft_strjoin(ft_dtoa((d < 0 ? -d : d), flags->precision), ".");
	else
		str = ft_dtoa((d < 0 ? -d : d), flags->precision);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}
