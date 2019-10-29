/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_uintmax_t.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:46:08 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 12:31:50 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include "libft.h"

char	*ft_itoa_base_uintmax_t(uintmax_t n, char *digits)
{
	char			*str;
	size_t			len;
	uintmax_t		base;

	base = ft_strlen(digits);
	len = (size_t)ft_ndigits_base_uintmax_t(n, base);
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
