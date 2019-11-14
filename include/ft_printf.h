/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/14 16:10:49 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "stdint.h"

# define PRINT_BUFF_SIZE 1024
# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"
# define BASE8 "01234567"
# define BASE2 "01"
# define PERCENT "%"
# define SPACE " "
# define ZERO "0"

# define LEN_NONE 0
# define LEN_HH 1
# define LEN_H 2
# define LEN_L 3
# define LEN_LL 4
# define LEN_LD 5

typedef struct	s_p_buff
{
	char		*start;
	char		*at;
	size_t		size;
}				t_p_buf;

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
	char		*prefix;
	int			prefixlen;
}				t_flags;

typedef int		(*t_s_func)(t_p_buf *, va_list, t_flags *);

typedef struct	s_sp_type
{
	char		c;
	t_s_func	output_func;
}				t_sp_type;

int				ft_printf(const char *restrict format, ...); //__attribute__ ((format(printf, 1, 2)));

void			ft_putnbr_uintmax_t(uintmax_t n);
void			ft_putnbr_base_uintmax_t(uintmax_t n, int base, char *digits);
char			*ft_itoa_base_uintmax_t(uintmax_t n, char *digits);
int				ft_ndigits_base_uintmax_t(uintmax_t n, int base);

t_flags			*ft_create_flags(void);
void			ft_init_flags(t_flags *flags);
void			ft_set_prefix(t_flags *flags, char *prefix, int len);
void			ft_parse_flags(char **fstr, t_flags *flags);
void			ft_parse_width(char **fstr, t_flags *flags, va_list valist);
void			ft_parse_precision(char **fstr, t_flags *flags, va_list valist);
void			ft_parse_length(char **fstr, t_flags *flags);

int				ft_outchar_buf(t_p_buf *dest, const char *data,\
								unsigned int len);
int				ft_format_output(t_p_buf *dest, t_flags *flags,\
								char *data, int len);

/*
** Handle strings and chars
*/

int				ft_handle_c(t_p_buf *dest, va_list valist, t_flags *flags);
int				ft_handle_s(t_p_buf *dest, va_list valist, t_flags *flags);

/*
** Handle numbers
*/

int				ft_handle_di(t_p_buf *dest, va_list valist, t_flags *flags);
int				ft_handle_o(t_p_buf *dest, va_list valist, t_flags *flags);
int				ft_handle_u(t_p_buf *dest, va_list valist, t_flags *flags);
int				ft_handle_f(t_p_buf *dest, va_list valist, t_flags *flags);

/*
** Handle others (pointer and hex conversion)
*/

int				ft_handle_p(t_p_buf *dest, va_list valist, t_flags *flags);
int				ft_handle_x_low(t_p_buf *dest, va_list valist, t_flags *flags);
int				ft_handle_x_up(t_p_buf *dest, va_list valist, t_flags *flags);

#endif
