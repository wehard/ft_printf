/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 23:25:29 by wkorande         ###   ########.fr       */
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

int	ft_handle_p(uintmax_t p, t_flags *flags)
{
	char *pstr;

	pstr = ft_strjoin("0x", ft_itoa_base_uintmax_t(p, BASE16LOW));
	ft_apply_width(flags, ft_strlen(pstr), &ft_outchar, pstr);
	return (0);
}
