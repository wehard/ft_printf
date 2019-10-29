/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:25:24 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 12:43:18 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_outchar(const char *data, int len)
{
	write(1, data, len);
}

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
			ft_putchar(SPACE);
		out_func(data, len);
	}
}

void	ft_output_c(char c, t_flags *flags)
{
	ft_apply_width(flags, 1, &ft_outchar, &c);
}

void	ft_output_s(char *s, t_flags *flags)
{
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
}

void	ft_output_p(uintmax_t p, t_flags *flags)
{
	char *pstr;
	char *pf;

	pf = "0x";
	pstr = ft_strjoin(pf, ft_itoa_base_uintmax_t(p, BASE16LOW));
	ft_apply_width(flags, ft_strlen(pstr), &ft_outchar, pstr);
}
