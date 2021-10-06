/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:31:10 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/04 13:32:30 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_number(const char *nbr)
{
	while (*nbr)
	{
		if (*nbr == '-' || *nbr == '+')
			nbr++;
		if (!ft_isdigit(*nbr))
			return (0);
		nbr++;
	}
	return (1);
}

int	is_duplicated(int stack[], int index, int x)
{
	while (index >= 0)
	{
		if (stack[index] == x)
			return (0);
		index--;
	}
	return (1);
}

int	smallest_nbr(int stack[], int size)
{
	int	nbr;
	int	index;

	size--;
	index = size;
	nbr = stack[size];
	while (size >= 0)
	{
		if (stack[size] < nbr)
		{
			nbr = stack[size];
			index = size;
		}
		size--;
	}
	return (index);
}

void	go_to_nbr(int stack[], int size, int index, char c)
{
	if (index >= size / 2)
	{
		while (size - index > 0)
		{
			if (index == size - 1)
				return ;
			rotate(stack, size, c);
			index++;
		}
	}
	else
	{
		while (index >= 0)
		{
			rev_rotate(stack, size, c);
			index--;
		}
	}
}

int	is_sorted(int a[], int sizea)
{
	sizea--;
	while ((sizea - 1) >= 0)
	{
		if (a[sizea] < a[sizea - 1])
			sizea--;
		else
			return (0);
	}
	return (1);
}
