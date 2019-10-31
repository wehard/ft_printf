/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_va_arg_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:04:29 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 10:56:45 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>

int				ft_get_va_arg_int(va_list valist)
{
	return (va_arg(valist, int));
}

unsigned int	ft_get_va_arg_uint(va_list valist)
{
	return (va_arg(valist, unsigned int));
}

double			ft_get_va_arg_double(va_list valist)
{
	return (va_arg(valist, double));
}

char			*ft_get_va_arg_cstr(va_list valist)
{
	return (va_arg(valist, char *));
}

uintmax_t		ft_get_va_arg_pointer(va_list valist)
{
	void *value;

	value = va_arg(valist, void *);
	return (*(uintmax_t*)&value);
}
