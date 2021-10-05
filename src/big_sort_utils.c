/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 09:08:27 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 14:17:10 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"


//Find the smallest int of the stack

int	smallest_int(int stack[], int size)
{
	int	nbr;

	size--;
	nbr = stack[size];
	while (size >= 0)
	{
		if (stack[size] < nbr)
		{
			nbr = stack[size];
		}
		size--;
	}
	return (nbr);
}

//Find the biggest int of the stack

int	biggest_int(int stack[], int size)
{
	int	nbr;

	size--;
	nbr = stack[size];
	while (size >= 0)
	{
		if (stack[size] > nbr)
		{
			nbr = stack[size];
		}
		size--;
	}
	return (nbr);
}

//Calculate and return the minimum moves i need to put stack1[index_a] on stack2[index_b]

int	calculate_moves(int index_a, int index_b, int sizea, int sizeb)
{
	int	ret;

	ret = 0;
	if (index_a >= sizea / 2)
		ret = (sizea - 1) - index_a;
	else if (index_a < sizea / 2)
		ret = index_a + 1;
	if (index_b >= sizeb / 2)
		ret += (sizeb - 1) - index_b;
	else if (index_b < sizeb / 2)
		ret += index_b + 1;
	return (ret);
}

//Makes the doube rotate and double_reverse_rotate

void	double_rotate(int a[], int b[], int sizea, int sizeb)
{
	rotate(a, sizea, 0);
	rotate(b, sizeb, 'r');
}

void	double_rev_rotate(int a[], int b[], int sizea, int sizeb)
{
	rev_rotate(a, sizea, 0);
	rev_rotate(b, sizeb, 'r');
}
