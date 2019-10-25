/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:48:42 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/25 16:42:44 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "../libft/includes/libft.h"

static int	is_arg(char *str)
{
	if (*str == '%' && *(str + 1) != '\0')
	{
		if (*(str + 1) == 'c' || *(str + 1) == 's' || *(str + 1) == 'p')
			return (1);
	}
	return (0);
}

static int	ft_countargs(char *str)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (str[i])
	{
		if (is_arg(str + i))
			n++;
		i++;
	}
	return (n);
}

/*
** You have to manage the following conversions: csp
** You have to manage the following conversions:
**						diouxX with the following flags: hh, h, l and ll.
** You have to manage the following conversion:
**						f with the following flags: l and L.
** You must manage %%
** You must manage the flags #0-+ and space
** You must manage the minimum field-width
** You must manage the precision
*/

int			ft_printf(const char *format,  ...)
{
	int		size;
	va_list	valist;
	int		i;

	size = ft_countargs((char*)format);

	va_start(valist, format);
	i = 0;
	while (i < size)
	{
		ft_putnbr(va_arg(valist, int));
		i++;
	}
	va_end(valist);
	ft_putchar('\n');
	return (0);
}
