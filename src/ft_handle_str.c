/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/01 13:07:18 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** int	ft_handle_c(int c, t_flags *flags)
*/

int	ft_handle_c(t_p_buf *dest, va_list valist, t_flags *flags)
{
	char c;

	c = va_arg(valist, int);
	return (ft_format_output(dest, flags, &c, 1));
}

int	ft_handle_s(t_p_buf *dest, va_list valist, t_flags *flags)
{
	char	*s;
	int		len;

	s = va_arg(valist, char *);
	len = flags->precision ? flags->precision : ft_strlen(s);
	return (ft_format_output(dest, flags, s, len));
}
