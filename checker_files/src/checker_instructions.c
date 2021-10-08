/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:21:40 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/08 13:13:54 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	do_swap(char *buffer, int sizea, int sizeb)
{
	if (!ft_strncmp(buffer, "sa", 2))
		checker_s(t_checker_stacks.stack_a, sizea);
	else if (!ft_strncmp(buffer, "sb", 2))
		checker_s(t_checker_stacks.stack_b, sizeb);
	else if (!ft_strncmp(buffer, "ss", 2))
	{
		checker_s(t_checker_stacks.stack_a, sizea);
		checker_s(t_checker_stacks.stack_b, sizeb);
	}
}

int	do_push(char *buffer, int sizea, int sizeb)
{
	if (!ft_strncmp(buffer, "pa", 2))
	{
		sizeb = checker_p(t_checker_stacks.stack_a, t_checker_stacks.stack_b,
				sizea, sizeb);
		sizea++;
	}
	else if (!ft_strncmp(buffer, "pb", 2))
	{
		sizea = checker_p(t_checker_stacks.stack_b, t_checker_stacks.stack_a,
				sizeb, sizea);
		sizeb++;
	}
	return (sizea);
}

void	do_rotate(char *buffer, int sizea, int sizeb)
{
	if (!ft_strncmp(buffer, "rra", 4))
		checker_rr(t_checker_stacks.stack_a, sizea);
	else if (!ft_strncmp(buffer, "rrb", 3))
		checker_rr(t_checker_stacks.stack_b, sizeb);
	else if (!ft_strncmp(buffer, "rrr", 3))
	{
		checker_rr(t_checker_stacks.stack_a, sizea);
		checker_rr(t_checker_stacks.stack_b, sizeb);
	}
	else if (!ft_strncmp(buffer, "ra", 2))
		checker_r(t_checker_stacks.stack_a, sizea);
	else if (!ft_strncmp(buffer, "rb", 2))
		checker_r(t_checker_stacks.stack_b, sizeb);
	else if (!ft_strncmp(buffer, "rr", 2))
	{
		checker_r(t_checker_stacks.stack_a, sizea);
		checker_r(t_checker_stacks.stack_b, sizeb);
	}
}
