/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 16:35:39 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_di(va_list valist, t_flags *flags)
{
	char	*str;
	int		n;
	int		i;

	n = va_arg(valist, int);
	if (flags->plus && n > 0)
	{
		flags->prefix = "+";
		flags->prefixlen = 1;
	}
	else if (n > 0 && flags->space)
	{
		flags->prefix = " ";
		flags->prefixlen = 1;
	}
	str = ft_itoa(n);
	i += ft_format_output(flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_o(va_list valist, t_flags *flags)
{
	char	*str;
	int		n;
	int		i;

	n = va_arg(valist, int);
	str = ft_itoa_base(n, BASE8);
	i = ft_format_output(flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_u(va_list valist, t_flags *flags)
{
	char			*str;
	unsigned int	n;
	int				i;

	n = va_arg(valist, unsigned int);
	str = ft_itoa(n);
	i = ft_format_output(flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_f(va_list valist, t_flags *flags)
{
	char	*str;
	double	d;
	int		i;

	if (flags->precision == 0)
		flags->precision = 6;
	d = va_arg(valist, double);
	str = ft_dtoa(d, flags->precision);
	i = ft_format_output(flags, str, ft_strlen(str));
	free(str);
	return (i);
}
