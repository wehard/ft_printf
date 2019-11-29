/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:42:28 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/29 19:05:50 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_p(va_list valist, t_flags *flags)
{
	char		*str;
	char		*tmp;
	uint64_t	p;
	int			bytes;

	flags->hash = 1;
	ft_set_prefix(flags, "0x", 2);
	p = va_arg(valist, unsigned long);
	if (!p)
		str = "0";
	else
		str = ft_itoa_base_uint64(p, BASE16LOW);
	bytes = ft_format(flags, str, ft_strlen(str));
	if (p)
		free(str);
	return (bytes);
}

int	ft_handle_x_low(va_list valist, t_flags *flags)
{
	char			*str;
	uint64_t		n;
	int				bytes;

	n = ft_cast_unsigned(flags->length, valist);
	if (flags->hash && n != 0)
		ft_set_prefix(flags, "0x", 2);
	if (flags->precision_specified)
		flags->zero_specified = 0;
	if (flags->precision_specified && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_uint64(n, BASE16LOW);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_x_up(va_list valist, t_flags *flags)
{
	char			*str;
	uint64_t		n;
	int				bytes;

	n = ft_cast_unsigned(flags->length, valist);
	if (flags->hash && n != 0)
		ft_set_prefix(flags, "0X", 2);
	if (flags->precision_specified)
		flags->zero_specified = 0;
	if (flags->precision_specified && flags->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa_base_uint64(n, BASE16UP);
	bytes = ft_format_zp(flags, str, ft_strlen(str));
	free(str);
	return (bytes);
}

int	ft_handle_percent(t_flags *flags)
{
	size_t bytes;

	if (flags->minus && flags->zero_specified)
		flags->zero_specified = 0;
	bytes = ft_format_zp(flags, PERCENT, 1);
	return (bytes);
}
