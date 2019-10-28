/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uintmax_t.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:46:08 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/28 18:15:38 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base_uintmax_t(uintmax_t n, char *digits)
{
	char			*str;
	unsigned int	len;
	unsigned int	base;

	base = ft_strlen(digits);
	len = (unsigned int)ft_ndigits_base(n, base) + (n < 0);
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
