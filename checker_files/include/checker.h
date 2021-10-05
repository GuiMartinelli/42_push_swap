/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:32:03 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 13:55:19 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include "../../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include "../../include/push_swap.h"

struct	s_checker_stacks
{
	int	*stack_a;
	int	*stack_b;
}		t_checker_stacks;

int		make_stack(char *argv[], int stack[], int argc);
void	checker_s(int stack[], int size);
void	checker_r(int stack[], int size);
void	checker_rr(int stack[], int size);
int		checker_p(int stack1[], int stack2[], int size1, int size2);
int		is_sorted(int a[], int sizea);

#endif