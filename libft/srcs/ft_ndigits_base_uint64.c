/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigits_base_uint64.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:22:51 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/24 12:06:39 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ndigits_base_uint64(uint64_t n, int base)
{
	int i;

	i = 0;
	while (n != 0)
	{
		n /= base;
		i++;
	}
	return (i);
}
