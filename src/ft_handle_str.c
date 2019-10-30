/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/30 12:03:30 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_c(char c, t_flags *flags)
{
	ft_apply_width(flags, 1, &ft_outchar, &c);
	return (1);
}

int	ft_handle_s(char *s, t_flags *flags)
{
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
	return (ft_max(ft_strlen(s), flags->width));
}
