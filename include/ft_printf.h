/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/12/01 15:12:41 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

# define N_HANDLERS 10
# define NULL_STRING "(null)"
# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"
# define BASE10 "0123456789"
# define BASE8 "01234567"
# define PERCENT "%"
# define SPACE " "
# define ZERO "0"

# define LEN_NONE 0
# define LEN_HH 1
# define LEN_H 2
# define LEN_L 3
# define LEN_LL 4
# define LEN_LD 5

typedef struct		s_flags
{
	int				hash;
	int				zero_specified;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				width_specified;
	int				width;
	int				width_left;
	int				precision_specified;
	int				precision;
	int				precision_left;
	int				length;
	int				prefix_specified;
	char			*prefix;
	int				prefixlen;
}					t_flags;

typedef int			(*t_s_func)(t_flags *, va_list);

typedef struct		s_sp_type
{
	char			c;
	t_s_func		output_func;
}					t_sp_type;

int					ft_printf(const char *format, ...);
t_flags				*ft_create_flags(void);
void				ft_init_flags(t_flags *flags);
void				ft_set_prefix(t_flags *flags, char *prefix, int len);
int					ft_parse_flags(char **fstr, t_flags *flags);
int					ft_parse_width(char **fstr, t_flags *flags, va_list valist);
int					ft_parse_precision(char **fstr, t_flags *flags, va_list valist);
int					ft_parse_length(char **fstr, t_flags *flags);
int					ft_format(t_flags *flags, char *data, int len);
int					ft_format_zp(t_flags *flags, char *data, int len);
int					ft_outchar(const char *data, unsigned int len);
int					ft_handle_c(t_flags *flags, va_list valist);
int					ft_handle_s(t_flags *flags, va_list valist);
int					ft_handle_di(t_flags *flags, va_list valist);
int					ft_handle_o(t_flags *flags, va_list valist);
int					ft_handle_u(t_flags *flags, va_list valist);
int					ft_handle_f(t_flags *flags, va_list valist);
int					ft_handle_p(t_flags *flags, va_list valist);
int					ft_handle_x_low(t_flags *flags, va_list valist);
int					ft_handle_x_up(t_flags *flags, va_list valist);
int					ft_handle_percent(t_flags *flags);
long long			ft_cast_signed(int length, va_list valist);
unsigned long long	ft_cast_unsigned(int length, va_list valist);
long double			ft_cast_double(int length, va_list valist);

#endif
