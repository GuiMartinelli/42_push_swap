/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:38:02 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 14:14:17 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Stack operations allowed

void	swap(int stack[], int size, char c)
{
	int	temp;

	if (size < 2)
		return ;
	size--;
	temp = stack[size];
	stack[size] = stack[(size - 1)];
	stack[(size - 1)] = temp;
	if (c)
		ft_printf("s%c\n", c);
}

void	rotate(int stack[], int size, char c)
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
	if (c)
		ft_printf("r%c\n", c);
}

void	rev_rotate(int stack[], int size, char c)
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
	if (c)
		ft_printf("rr%c\n", c);
}

int	push(int stack1[], int stack2[], int size1, int size2)
{
	size2--;
	stack1[size1] = stack2[size2];
	stack2[size2] = 0;
	return (size2);
}
