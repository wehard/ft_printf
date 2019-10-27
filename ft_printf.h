/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wkorande <wkorande@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:38:16 by wkorande          #+#    #+#             */
/*   Updated: 2019/10/27 18:43:01 by wkorande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

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

#endif
