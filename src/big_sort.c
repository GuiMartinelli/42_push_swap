/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:08:55 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 14:22:08 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Find the position of int nbr, it search for a index where (index + 1) < nbr < (index-1)

int	find_position(int a[], int size, int nbr)
{
	int	x;

	size--;
	x = size;
	if (a[size] > nbr && a[0] < nbr)
		return (size);
	while (!(a[x] < nbr && a[x - 1] > nbr))
		x--;
	return (x - 1);
}

//Search for situations where i can use double_rotate or double_reverse_rotate and return how many i can do

int	reduce_moves(int index_a, int index_b, int sizea, int sizeb)
{
	int	x;

	x = 0;
	if (index_a == sizea - 1 || index_b == sizeb - 1)
		return (x);
	if (index_a >= sizea / 2 && index_b >= sizeb / 2)
	{
		if ((sizea - 1) - index_a > (sizeb - 1) - index_b)
			x = (sizeb - 1) - index_b;
		else if ((sizea - 1) - index_a < (sizeb - 1) - index_b)
			x = (sizea - 1) - index_a;
		else
			x = (sizea - 1) - index_a;
	}
	else if (index_a < sizea / 2 && index_b < sizeb / 2)
	{
		if (index_a > index_b)
			x = (index_b + 1) * -1;
		else if (index_a < index_b)
			x = (index_a + 1) * -1;
		else
			x = (index_a + 1) * -1;
	}
	return (x);
}

//Execute the double_moves

void	double_moves(int sizea, int sizeb, int moves)
{
	if (moves < 0)
	{
		while (moves < 0)
		{
			double_rev_rotate(t_stacks.stack_a, t_stacks.stack_b, sizea, sizeb);
			moves++;
		}
	}
	if (moves > 0)
	{
		while (moves > 0)
		{
			double_rotate(t_stacks.stack_a, t_stacks.stack_b, sizea, sizeb);
			moves--;
		}
	}
}

//Calculate what element of stack B takes less moves to put in the right position, and put ir on top, as well as its position

void	push_b_to_a(int a[], int b[], int sizea, int sizeb)
{
	int	index;
	int	a_index;
	int	b_index;
	int	temp;
	int	moves;

	temp = sizeb - 1;
	moves = sizeb + sizea;
	while (temp >= 0)
	{
		index = find_position(a, sizea, b[temp]);
		if (calculate_moves(index, temp, sizea, sizeb) < moves)
		{
			moves = calculate_moves(index, temp, sizea, sizeb);
			b_index = temp;
			a_index = index;
		}
		temp--;
	}
	moves = reduce_moves(a_index, b_index, sizea, sizeb);
	go_to_nbr(a, sizea, (a_index + moves), 'a');
	go_to_nbr(b, sizeb, (b_index + moves), 'b');
	double_moves(sizea, sizeb, moves);
}

//Put every element in stack B, unless its already sorted, then return all of them to stack A, sorted.

void	lightning_sort(int a[], int b[], int sizea, int sizeb)
{
	int	x;

	x = sizea + 30;
	while (x >= 0 && !is_sorted(a, sizea))
	{
		if ((a[sizea - 1] < a[sizea - 2] && a[sizea - 1] > a[0])
			|| a[sizea - 1] == smallest_int(a, sizea)
			|| a[sizea - 1] == biggest_int(a, sizea))
			rotate(a, sizea, 'a');
		else
		{
			sizea = push(b, a, sizeb, sizea);
			write(1, "pb\n", 3);
			sizeb++;
		}
		x--;
	}
	while (sizeb > 0)
	{
		push_b_to_a(a, b, sizea, sizeb);
		sizeb = push(a, b, sizea, sizeb);
		write(1, "pa\n", 3);
		sizea++;
	}
	go_to_nbr(a, sizea, smallest_nbr(a, sizea), 'a');
}
