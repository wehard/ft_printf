/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:42:28 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 11:22:52 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_p(va_list valist, t_flags *flags)
{
	char		*pstr;
	char		*tmp;
	uintmax_t	p;
	void		*ptr;

	ptr = va_arg(valist, void *);
	p = *(uintmax_t*)&ptr;
	tmp = ft_itoa_base_uintmax_t(p, BASE16LOW);
	pstr = ft_strjoin("0x", tmp);
	ft_apply_width(flags, ft_strlen(pstr), &ft_outchar, pstr);
	free(pstr);
	free(tmp);
	return (1);
}

int	ft_handle_x_low(va_list valist, t_flags *flags)
{
	char			*s;
	unsigned int	n;

	n = va_arg(valist, unsigned int);
	if (flags->hash)
		s = ft_strjoin("0x", ft_itoa_base(n, BASE16LOW));
	else
		s = ft_itoa_base(n, BASE16LOW);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
	free(s);
	return (1);
}

int	ft_handle_x_up(va_list valist, t_flags *flags)
{
	char			*s;
	unsigned int	n;

	n = va_arg(valist, unsigned int);
	if (flags->hash)
		s = ft_strjoin("0x", ft_itoa_base(n, BASE16UP));
	else
		s = ft_itoa_base(n, BASE16UP);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
	free(s);
	return (1);
}
