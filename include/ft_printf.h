/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/11/29 18:17:10 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include "stdint.h"

# define N_HANDLERS 10
# define PRINT_BUFF_SIZE 9000
# define NULL_STRING "(null)"
# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"
# define BASE10 "0123456789"
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

typedef struct	s_flags
{
	int			hash;
	int			zero_specified;
	int			zero;
	int			plus;
	int			minus;
	int			space;
	int			width_specified;
	int			width;
	int			precision_specified;
	int			precision;
	int			length;
	int			prefix_specified;
	char		*prefix;
	int			prefixlen;
}				t_flags;

typedef int		(*t_s_func)(va_list, t_flags *);

typedef struct	s_sp_type
{
	char		c;
	t_s_func	output_func;
}				t_sp_type;


int				ft_printf(const char *format, ...);

t_flags			*ft_create_flags(void);
void			ft_init_flags(t_flags *flags);
void			ft_set_prefix(t_flags *flags, char *prefix, int len);

int				ft_parse_flags(char **fstr, t_flags *flags);
int				ft_parse_width(char **fstr, t_flags *flags, va_list valist);
int				ft_parse_precision(char **fstr, t_flags *flags, va_list valist);
int				ft_parse_length(char **fstr, t_flags *flags);

int				ft_outchar(const char *data, unsigned int len);
int				ft_format(t_flags *flags, char *data, int len);
int				ft_format_zp(t_flags *flags, char *data, int len);
//void			ft_write(char *buf, size_t nbyte);

/*
** Handle strings and chars
*/

int				ft_handle_c(va_list valist, t_flags *flags);
int				ft_handle_s(va_list valist, t_flags *flags);

/*
** Handle numbers
*/

int				ft_handle_di(va_list valist, t_flags *flags);
int				ft_handle_o(va_list valist, t_flags *flags);
int				ft_handle_u(va_list valist, t_flags *flags);
int				ft_handle_f(va_list valist, t_flags *flags);

/*
** Handle others (pointer and hex conversion) + percent
*/

int				ft_handle_p(va_list valist, t_flags *flags);
int				ft_handle_x_low(va_list valist, t_flags *flags);
int				ft_handle_x_up(va_list valist, t_flags *flags);
int				ft_handle_percent(t_flags *flags);

#endif
