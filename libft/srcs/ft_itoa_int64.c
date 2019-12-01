/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_int64.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:46:08 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/22 15:04:34 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_int64(int64_t n)
{
	char		*str;
	uint64_t	nbr;
	int			len;

	if (n == INT64_MIN)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		nbr = (uint64_t)(n * -1);
	else
		nbr = (uint64_t)n;
	len = (size_t)ft_ndigits_base_int64(n, 10) + (n < 0);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
