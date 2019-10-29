/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:48:44 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 15:07:35 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_apply_width(t_flags *flags, int len, void (*out_func)(const char *, int), void *data)
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
