/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 14:17:39 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 16:15:16 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "ft_printf.h"

int		ft_format_output(t_flags *flags, char *data, int len)
{
	int spaces;

	spaces = flags->width - len - flags->prefixlen;
	if (flags->minus)
	{
		if (flags->plus)
		{
			ft_outchar(flags->prefix, flags->prefixlen);
			spaces--;
		}
		ft_outchar(data, len);
		while (spaces-- > 0)
			ft_putchar(SPACE);
	}
	else
	{
		while (spaces-- > 0)
			flags->zero ? ft_putchar(ZERO) : ft_putchar(SPACE);
		if (flags->hash || flags->plus)
			ft_outchar(flags->prefix, flags->prefixlen);
		ft_outchar(data, len);
	}
	return (spaces + len);
}

int		ft_outchar(const char *data, int len)
{
	write(1, data, len);
	return (len);
}
