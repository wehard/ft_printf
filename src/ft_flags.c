/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:09:48 by wkorande          #+#    #+#             */
/*   Updated: 2019/12/01 15:05:52 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	*ft_create_flags(void)
{
	t_flags *flags;

	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	ft_init_flags(flags);
	return (flags);
}

void	ft_init_flags(t_flags *flags)
{
	if (!flags)
		return ;
	flags->hash = 0;
	flags->zero_specified = 0;
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->width_specified = 0;
	flags->width = 0;
	flags->width_left = 0;
	flags->precision_specified = 0;
	flags->precision = 0;
	flags->precision_left = 0;
	flags->prefix_specified = 0;
	flags->prefix = NULL;
	flags->prefixlen = 0;
	flags->length = LEN_NONE;
}

void	ft_set_prefix(t_flags *flags, char *prefix, int len)
{
	flags->prefix = prefix;
	flags->prefixlen = len;
	flags->prefix_specified = 1;
}
