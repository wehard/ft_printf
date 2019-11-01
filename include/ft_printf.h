/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/01 11:35:43 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "stdint.h"

# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"
# define BASE8 "01234567"
# define BASE2 "01"
# define SPACE ' '
# define ZERO '0'

typedef struct	s_flags
{
	int			hash;
	int			zero;
	int			plus;
	int			minus;
	int			space;
	int			width;
	int			precision;
	int			length;
	int			bytes;
	char		*prefix;
	int			prefixlen;
}				t_flags;

typedef int		(*t_s_func)(va_list, t_flags *);

typedef struct	s_sp_type
{
	char		c;
	t_s_func	output_func;
}				t_sp_type;

void	ft_putnbr_uintmax_t(uintmax_t n);
void	ft_putnbr_base_uintmax_t(uintmax_t n, int base, char *digits);
char	*ft_itoa_base_uintmax_t(uintmax_t n, char *digits);
int		ft_ndigits_base_uintmax_t(uintmax_t n, int base);

t_flags	*ft_create_flags(void);
void	ft_init_flags(t_flags *flags);
void	ft_parse_flags(char **fstr, t_flags *flags);
void	ft_parse_width(char **fstr, t_flags *flags);
void	ft_parse_precision(char **fstr, t_flags *flags);

int		ft_outchar(const char *data, int len);
int		ft_format_output(t_flags *flags, char *data, int len);

/*
** Handle strings and chars
*/

int		ft_handle_c(va_list valist, t_flags *flags);
int		ft_handle_s(va_list valist, t_flags *flags);

/*
** Handle numbers
*/

int		ft_handle_di(va_list valist, t_flags *flags);
int		ft_handle_o(va_list valist, t_flags *flags);
int		ft_handle_u(va_list valist, t_flags *flags);
int		ft_handle_f(va_list valist, t_flags *flags);

/*
** Handle others (pointer and hex conversion)
*/

int		ft_handle_p(va_list valist, t_flags *flags);
int		ft_handle_x_low(va_list valist, t_flags *flags);
int		ft_handle_x_up(va_list valist, t_flags *flags);


#endif
