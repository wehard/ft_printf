/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 10:41:22 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/28 15:56:26 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_output_di(int n, t_flags *flags)
{
	ft_putnbr(n);
}

void	ft_output_o(int n, t_flags *flags)
{
	ft_putstr(ft_itoa_base(n, BASE8));
}

void	ft_output_u(unsigned int n, t_flags *flags)
{
	ft_putnbr(n);
}

void	ft_output_x_low(unsigned int n, t_flags *flags)
{
	ft_putstr(ft_itoa_base(n, BASE16LOW));
}

void	ft_output_x_up(unsigned int n, t_flags *flags)
{
	ft_putstr(ft_itoa_base(n, BASE16UP));
}
