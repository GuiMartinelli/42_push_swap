/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_actions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:41:17 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 13:52:13 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	checker_s(int stack[], int size)
{
	int	temp;

	if (size < 2)
		return ;
	size--;
	temp = stack[size];
	stack[size] = stack[(size - 1)];
	stack[(size - 1)] = temp;
}

void	checker_r(int stack[], int size)
{
	int	temp;

	if (size < 2)
		return ;
	size--;
	temp = stack[size];
	while (size > 0)
	{
		stack[size] = stack[size - 1];
		size--;
	}
	stack[0] = temp;
}

void	checker_rr(int stack[], int size)
{
	int	temp;
	int	x;

	if (size < 2)
		return ;
	size--;
	temp = stack[0];
	x = 0;
	while (x < size)
	{
		stack[x] = stack[x + 1];
		x++;
	}
	stack[x] = temp;
}

int	checker_p(int stack1[], int stack2[], int size1, int size2)
{
	size2--;
	stack1[size1] = stack2[size2];
	stack2[size2] = 0;
	return (size2);
}
