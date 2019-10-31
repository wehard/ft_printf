/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/31 12:02:00 by wkorande         ###   ########.fr       */
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
void	ft_apply_width(t_flags *flags, int len, int (*out_func)(const char *, int), void *data);

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

/*
** va_arg helpers
*/

int				ft_get_va_arg_int(va_list valist);
unsigned int	ft_get_va_arg_uint(va_list valist);
double			ft_get_va_arg_double(va_list valist);
char			*ft_get_va_arg_cstr(va_list valist);
uintmax_t		ft_get_va_arg_pointer(va_list valist);

#endif
