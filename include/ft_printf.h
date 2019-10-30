/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/30 11:59:10 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include "stdint.h"

# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"
# define BASE8 "01234567"
# define BASE2 "01"
# define SPACE ' '
# define ZERO '0'

typedef struct s_flags
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

void	ft_putnbr_uintmax_t(uintmax_t n);
void	ft_putnbr_base_uintmax_t(uintmax_t n, int base, char *digits);
char	*ft_itoa_base_uintmax_t(uintmax_t n, char *digits);
int		ft_ndigits_base_uintmax_t(uintmax_t n, int base);

t_flags	*ft_create_flags(void);
void	ft_init_flags(t_flags *flags);
void	ft_parse_flags(char **fstr, t_flags *flags);
void	ft_parse_width(char **fstr, t_flags *flags);
void	ft_parse_precision(char **fstr, t_flags *flags);

void	ft_outchar(const char *data, int len);
void	ft_apply_width(t_flags *flags, int len, void (*out_func)(const char *, int), void *data);

/*
** Handle strings and chars
*/

int		ft_handle_c(char c, t_flags *flags);
int		ft_handle_s(char *s, t_flags *flags);

/*
** Handle numbers
*/

int		ft_handle_di(int n, t_flags *flags);
int		ft_handle_o(int n, t_flags *flags);
int		ft_handle_u(unsigned int n, t_flags *flags);
int		ft_handle_f(double d, t_flags *flags);

/*
** Handle others (pointer and hex conversion)
*/

int		ft_handle_p(uintmax_t p, t_flags *flags);
int		ft_handle_x_low(unsigned int n, t_flags *flags);
int		ft_handle_x_up(unsigned int n, t_flags *flags);

#endif
