/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 12:06:11 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_di(va_list valist, t_flags *flags)
{
	char	*s;
	int		n;

	n = va_arg(valist, int);
	if (flags->plus && n > 0)
		s = ft_strjoin("+", ft_itoa(n));
	else
		s = ft_itoa(n);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
	free(s);
	return (1);
}

int	ft_handle_o(va_list valist, t_flags *flags)
{
	char	*str;
	int		n;

	n = va_arg(valist, int);
	str = ft_itoa_base(n, BASE8);
	ft_apply_width(flags, ft_strlen(str), &ft_outchar, str);
	free(str);
	return (1);
}

int	ft_handle_u(va_list valist, t_flags *flags)
{
	char			*str;
	unsigned int	n;

	n = va_arg(valist, unsigned int);
	str = ft_itoa(n);
	ft_apply_width(flags, ft_strlen(str), &ft_outchar, str);
	free(str);
	return (1);
}

int	ft_handle_f(va_list valist, t_flags *flags)
{
	char	*str;
	double	d;

	d = va_arg(valist, double);
	str = ft_dtoa(d, flags->precision);
	ft_apply_width(flags, ft_strlen(str), &ft_outchar, str);
	free(str);
	return (1);
}
