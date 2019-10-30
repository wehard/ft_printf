/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:42:28 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/30 11:46:17 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_p(uintmax_t p, t_flags *flags)
{
	char *pstr;

	pstr = ft_strjoin("0x", ft_itoa_base_uintmax_t(p, BASE16LOW));
	ft_apply_width(flags, ft_strlen(pstr), &ft_outchar, pstr);
	return (0);
}

int	ft_handle_x_low(unsigned int n, t_flags *flags)
{
	char *s;

	if (flags->hash)
		s = ft_strjoin("0x", ft_itoa_base(n, BASE16LOW));
	else
		s = ft_itoa_base(n, BASE16LOW);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
}

int	ft_handle_x_up(unsigned int n, t_flags *flags)
{
	char *s;

	if (flags->hash)
		s = ft_strjoin("0x", ft_itoa_base(n, BASE16UP));
	else
		s = ft_itoa_base(n, BASE16UP);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
}
