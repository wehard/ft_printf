/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 17:26:11 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_handle_di(int n, t_flags *flags)
{
	ft_apply_width(flags, ft_strlen(ft_itoa(n)), &ft_outchar, ft_itoa(n));
}

void	ft_handle_o(int n, t_flags *flags)
{
	ft_apply_width(flags, ft_strlen(ft_itoa_base(n, BASE8)), &ft_outchar, ft_itoa_base(n, BASE8));
}

void	ft_handle_u(unsigned int n, t_flags *flags)
{
	ft_apply_width(flags, ft_strlen(ft_itoa(n)), &ft_outchar, ft_itoa(n));
}

void	ft_handle_x_low(unsigned int n, t_flags *flags)
{
	char *s;
	if (flags->hash)
		s = ft_strjoin("0x", ft_itoa_base(n, BASE16LOW));
	else
		s = ft_itoa_base(n, BASE16LOW);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
}

void	ft_handle_x_up(unsigned int n, t_flags *flags)
{
	char *s;
	if (flags->hash)
		s = ft_strjoin("0x", ft_itoa_base(n, BASE16UP));
	else
		s = ft_itoa_base(n, BASE16UP);
	ft_apply_width(flags, ft_strlen(s), &ft_outchar, s);
}

void	ft_handle_f(double d, t_flags *flags)
{
	int 	dec;
	double	frac;

	frac = d;
	dec = (int)d;
	frac -= dec;
	ft_putnbr(dec);
	ft_outchar(".", 1);
	frac *= ft_pow(10, flags->precision);
	dec = (signed long int)(frac + 0.5); // Round up?
	ft_outchar(ft_itoa(dec), ft_ndigits(dec));
}
