/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_uintmax_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 17:34:31 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/28 19:06:32 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	ft_putnbr_uintmax_t(uintmax_t n)
{
	if (n < 10)
	{
		ft_putchar('0' + n);
	}
	else
	{
		ft_putnbr_uintmax_t(n / 10);
		ft_putnbr_uintmax_t(n % 10);
	}
}
