/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 17:21:39 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_handle_c(char c, t_flags *flags)
{
	ft_apply_width(flags, 1, &ft_outchar, &c);
}

void	ft_handle_s(char *s, t_flags *flags)
{
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
}

void	ft_handle_p(uintmax_t p, t_flags *flags)
{
	char *pstr;

	pstr = ft_strjoin("0x", ft_itoa_base_uintmax_t(p, BASE16LOW));
	ft_apply_width(flags, ft_strlen(pstr), &ft_outchar, pstr);
}
