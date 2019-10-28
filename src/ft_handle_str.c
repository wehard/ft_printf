/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/28 18:56:09 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_output_c(char c, t_flags *flags)
{
	ft_putchar(c);
}

void	ft_output_s(char *s, t_flags *flags)
{
	ft_putstr(s);
}

void	ft_output_p(uintmax_t p, t_flags *flags)
{
	ft_putstr("0x");
	ft_putnbr_base_uintmax_t(p, 16, BASE16LOW);
}
