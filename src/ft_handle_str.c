/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 10:41:41 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
** int	ft_handle_c(int c, t_flags *flags)
*/

int	ft_handle_c(va_list valist, t_flags *flags)
{
	char c;

	c = va_arg(valist, int);
	ft_apply_width(flags, 1, &ft_outchar, &c);
	return (1);
}

int	ft_handle_s(va_list valist, t_flags *flags)
{
	char *s;

	s = va_arg(valist, char *);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
	return (ft_max(ft_strlen(s), flags->width));
}
