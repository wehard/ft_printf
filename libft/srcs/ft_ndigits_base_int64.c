/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ndigits_base_int64.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 12:22:51 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/22 13:37:08 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ndigits_base_int64(int64_t n, int base)
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
