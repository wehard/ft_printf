/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 11:42:28 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 16:15:41 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_handle_p(va_list valist, t_flags *flags)
{
	char		*str;
	char		*tmp;
	uintmax_t	p;
	void		*ptr;
	int			i;

	flags->hash = 1;
	flags->prefix = "0x";
	flags->prefixlen = 2;
	ptr = va_arg(valist, void *);
	p = *(uintmax_t*)&ptr;
	str = ft_itoa_base_uintmax_t(p, BASE16LOW);
	i = ft_format_output(flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_x_low(va_list valist, t_flags *flags)
{
	char			*str;
	unsigned int	n;
	int				i;

	flags->prefix = "0x";
	flags->prefixlen = 2;
	n = va_arg(valist, unsigned int);
	str = ft_itoa_base(n, BASE16LOW);
	i = ft_format_output(flags, str, ft_strlen(str));
	free(str);
	return (i);
}

int	ft_handle_x_up(va_list valist, t_flags *flags)
{
	char			*str;
	unsigned int	n;
	int				i;

	flags->prefix = "0X";
	flags->prefixlen = 2;
	n = va_arg(valist, unsigned int);
	str = ft_itoa_base(n, BASE16UP);
	i = ft_format_output(flags, str, ft_strlen(str));
	free(str);
	return (i);
}
