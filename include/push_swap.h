/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:33:03 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 14:13:17 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

struct	s_stacks
{
	int	*stack_a;
	int	*stack_b;
}		t_stacks;

//Checking errors
int		is_number(const char *nbr);
int		is_duplicated(int stack[], int index, int x);

//Parse args
int		make_stack(char *argv[], int stack[], int argc);

//Stack operations
void	swap(int stack[], int size, char c);
void	rotate(int stack[], int size, char c);
void	rev_rotate(int stack[], int size, char c);
int		push(int stack1[], int stack2[], int size1, int size2);

//Small sort
void	sort_3(int a[], int sizea);
void	sort_5(int a[], int b[], int sizea, int sizeb);

//Big sort
void	lightning_sort(int a[], int b[], int sizea, int sizeb);

//Utils
int		is_sorted(int a[], int sizea);
int		smallest_nbr(int stack[], int size);
void	go_to_nbr(int stack[], int size, int index, char c);
int		smallest_int(int stack[], int size);
int		biggest_int(int stack[], int size);
int		calculate_moves(int index_a, int index_b, int sizea, int sizeb);
void	double_rev_rotate(int a[], int b[], int sizea, int sizeb);
void	double_rotate(int a[], int b[], int sizea, int sizeb);

#endif