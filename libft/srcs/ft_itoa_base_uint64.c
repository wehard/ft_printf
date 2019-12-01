/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uint64.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:46:08 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/22 15:18:18 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base_uint64(uint64_t n, char *digits)
{
	char	*str;
	size_t	len;
	size_t	base;

	if (n == 0)
		return (ft_strdup("0"));
	base = ft_strlen(digits);
	len = (size_t)ft_ndigits_base_uint64(n, base);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len--] = '\0';
	while (n != 0)
	{
		str[len] = digits[n % base];
		n /= base;
		len--;
	}
	return (str);
}
