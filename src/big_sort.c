/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:08:55 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/08 13:42:12 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//Find the index where nbr will be sorted at stack
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

//Calculate where it can change 2 moves for 1. Example = ra + rb => rr
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

//Execute double moves the right times
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

//Calculate and int at b it can sort in a with the less possible moves, and put it at top
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

//Put stack a elements at b until stack a is sorted, then put stack b elements back at a, sorted
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
