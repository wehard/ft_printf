/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_uintmax_t.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:59:48 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/28 19:06:17 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_base_uintmax_t(uintmax_t n, int base, char *digits)
{
	if (n < base)
	{
		ft_putchar(digits[n]);
	}
	else
	{
		ft_putnbr_base_uintmax_t(n / base, base, digits);
		ft_putnbr_base_uintmax_t(n % base, base, digits);
	}
}
