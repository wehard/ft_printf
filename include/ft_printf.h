/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/29 12:35:20 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "stdint.h"

# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"
# define BASE8 "01234567"
# define BASE2 "01"
# define SPACE ' '

typedef struct s_flags
{
	int			hash;
	int			zero;
	int			plus;
	int			minus;
	int			space;
	int			width;
	int			precision;
}				t_flags;

void	ft_putnbr_uintmax_t(uintmax_t n);
void	ft_putnbr_base_uintmax_t(uintmax_t n, int base, char *digits);
char	*ft_itoa_base_uintmax_t(uintmax_t n, char *digits);
int		ft_ndigits_base_uintmax_t(uintmax_t n, int base);

void	ft_output_c(char c, t_flags *flags);
void	ft_output_s(char *s, t_flags *flags);

void	ft_output_p(uintmax_t p, t_flags *flags);

void	ft_output_di(int n, t_flags *flags);
void	ft_output_o(int n, t_flags *flags);
void	ft_output_u(unsigned int n, t_flags *flags);
void	ft_output_x_low(unsigned int n, t_flags *flags);
void	ft_output_x_up(unsigned int n, t_flags *flags);

#endif
