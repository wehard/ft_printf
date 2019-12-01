/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/12/01 15:20:30 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_di(t_flags *flags, va_list valist)
{
	char		*str;
	long long	n;
	int			bytes;

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
		str = ft_itoa_ull(n < 0 ? (long long)(n * -1) : (long long)n);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_o(t_flags *flags, va_list valist)
{
	char				*str;
	unsigned long long	n;
	int					bytes;

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
		str = ft_itoa_base_ull(n, BASE8);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_u(t_flags *flags, va_list valist)
{
	char				*str;
	unsigned long long	n;
	int					bytes;

	n = ft_cast_unsigned(flags->length, valist);
	if (flags->precision_specified)
		flags->zero_specified = 0;
	if (flags->precision_specified && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_ull(n);
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
