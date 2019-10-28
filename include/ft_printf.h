/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/28 12:48:33 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BASE16LOW "0123456789abcdef"
# define BASE16UP "0123456789ABCDEF"
# define BASE8 "01234567"
# define BASE2 "01"

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

void	ft_output_c(char c, t_flags *flags);
void	ft_output_s(char *s, t_flags *flags);

void	ft_output_p(unsigned int, t_flags *flags);

void	ft_output_di(int n, t_flags *flags);
void	ft_output_o(int n, t_flags *flags);
void	ft_output_u(unsigned int n, t_flags *flags);
void	ft_output_x_low(unsigned int n, t_flags *flags);
void	ft_output_x_up(unsigned int n, t_flags *flags);

#endif
