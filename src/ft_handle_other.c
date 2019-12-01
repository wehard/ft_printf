/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:42:28 by wkorande          #+#    #+#             */
/*   Updated: 2019/12/01 15:20:53 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_p(t_flags *flags, va_list valist)
{
	char				*str;
	unsigned long long	p;
	int					bytes;

	flags->hash = 1;
	ft_set_prefix(flags, "0x", 2);
	p = va_arg(valist, unsigned long);
	if (!p)
		str = "0";
	else
		str = ft_itoa_base_ull(p, BASE16LOW);
	bytes = ft_format(flags, str, ft_strlen(str));
	if (p)
		free(str);
	return (bytes);
}

int	ft_handle_x_low(t_flags *flags, va_list valist)
{
	char				*str;
	unsigned long long	n;
	int					bytes;

	n = ft_cast_unsigned(flags->length, valist);
	if (flags->hash && n != 0)
		ft_set_prefix(flags, "0x", 2);
	if (flags->precision_specified)
		flags->zero_specified = 0;
	if (flags->precision_specified && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_ull(n, BASE16LOW);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_x_up(t_flags *flags, va_list valist)
{
	char				*str;
	unsigned long long	n;
	int					bytes;

	n = ft_cast_unsigned(flags->length, valist);
	if (flags->hash && n != 0)
		ft_set_prefix(flags, "0X", 2);
	if (flags->precision_specified)
		flags->zero_specified = 0;
	if (flags->precision_specified && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_ull(n, BASE16UP);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_percent(t_flags *flags)
{
	int bytes;

	if (flags->minus && flags->zero_specified)
		flags->zero_specified = 0;
	bytes = ft_format_zp(flags, PERCENT, 1);
	return (bytes);
}
