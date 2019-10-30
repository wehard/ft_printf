/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/30 12:00:47 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_di(int n, t_flags *flags)
{
	char *s;

	if (flags->plus && n > 0)
		s = ft_strjoin("+", ft_itoa(n));
	else
		s = ft_itoa(n);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
}

int	ft_handle_o(int n, t_flags *flags)
{
	char	*str;

	str = ft_itoa_base(n, BASE8);
	ft_apply_width(flags, ft_strlen(str), &ft_outchar, str);
}

int	ft_handle_u(unsigned int n, t_flags *flags)
{
	ft_apply_width(flags, ft_strlen(ft_itoa(n)), &ft_outchar, ft_itoa(n));
}

int	ft_handle_f(double d, t_flags *flags)
{
	char	*str;

	str = ft_dtoa(d, flags->precision);
	ft_apply_width(flags, ft_strlen(str), &ft_outchar, str);
}
