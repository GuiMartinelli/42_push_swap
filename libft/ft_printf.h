/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 15:34:57 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/01 08:21:58 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include "libft.h"

struct	s_flags
{
	bool	is_minus;
	bool	is_zero;
	bool	is_space;
	bool	is_signal;
	bool	is_hash;
	bool	is_dot;
	int		width;
	int		precision;
}		t_flags;

int		ft_printf(const char *str, ...);
int		chr_type(char type, va_list args);
int		str_type(va_list args);
int		ptr_type(va_list args);
int		int_type(va_list args);
int		unsigned_type(va_list args);
int		hexa_type(va_list args, char x);
void	print_width(int i, char c);
void	print_int(int i);
void	print_uns(unsigned int u);
void	print_signal(void);
int		ft_printf_strlen(const char *ptr);

#endif
