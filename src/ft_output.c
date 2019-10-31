/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:39 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 12:00:05 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

void	ft_apply_width(t_flags *flags, int len,\
						int (*out_func)(const char *, int), void *data)
{
	int spaces;

	spaces = flags->width - len;
	if (flags->minus)
	{
		out_func(data, len);
		while (spaces-- > 0)
			ft_putchar(SPACE);
	}
	else
	{
		while (spaces-- > 0)
		{
			flags->zero ? ft_putchar(ZERO) : ft_putchar(SPACE);
		}
		out_func(data, len);
	}
}

int		ft_outchar(const char *data, int len)
{
	write(1, data, len);
	return (len);
}
