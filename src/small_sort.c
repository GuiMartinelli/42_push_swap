/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 07:37:52 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/08 13:47:29 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//With 3 numbers, you have 6 possible cases of order, this function finds which one is
int	check_order(int a[])
{
	if (a[2] > a[1] && a[2] < a[0])
		return (1);
	if (a[1] > a[0] && a[1] < a[2])
		return (2);
	if (a[0] > a[1] && a[0] < a[2])
		return (3);
	if (a[0] < a[1] && a[0] > a[2])
		return (4);
	if (a[2] > a[0] && a[2] < a[1])
		return (5);
	if (a[1] > a[2] && a[1] < a[0])
		return (0);
	else
		return (-1);
}

//Sort a stack with 2 elements
void	sort_2(int a[])
{
	if (a[1] > a[0])
		swap(a, 2, 'a');
}

//Check whats the initial order of the given stack, and sort
void	sort_3(int a[], int sizea)
{
	int	x;

	if (sizea == 2)
	{
		sort_2(a);
		return ;
	}
	x = check_order(a);
	if (x == 1)
		swap(a, 3, 'a');
	else if (x == 2)
	{
		swap(a, sizea, 'a');
		rev_rotate(a, sizea, 'a');
	}
	else if (x == 3)
		rotate(a, sizea, 'a');
	else if (x == 4)
	{
		swap(a, sizea, 'a');
		rotate(a, sizea, 'a');
	}
	else if (x == 5)
		rev_rotate(a, sizea, 'a');
}

//Pull the 2 smallest elements to stack b, sort stack a 3 remaining elements, then pull back the elements at b to a
void	sort_5(int a[], int b[], int sizea, int sizeb)
{
	go_to_nbr(a, sizea, smallest_nbr(a, sizea), 'a');
	sizea = push(b, a, sizeb, sizea);
	ft_printf("pb\n");
	sizeb++;
	if (sizea == 4)
	{
		go_to_nbr(a, sizea, smallest_nbr(a, sizea), 'a');
		sizea = push(b, a, sizeb, sizea);
		ft_printf("pb\n");
		sizeb++;
	}
	sort_3(a, sizea);
	sizeb = push(a, b, sizea, sizeb);
	ft_printf("pa\n");
	sizea++;
	if (sizea == 4)
	{
		sizeb = push(a, b, sizea, sizeb);
		ft_printf("pa\n");
		sizea++;
	}
}
