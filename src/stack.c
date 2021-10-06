/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 07:21:57 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/01 08:47:09 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	make_stack(char *argv[], int stack[], int argc)
{
	int	x;
	int	y;

	x = 0;
	y = argc - 1;
	while (x < y)
	{
		stack[x] = ft_stoi(argv[(y - x)]);
		if (!is_duplicated(stack, (x - 1), stack[x])
			|| !is_number(argv[(y - x)]) || (stack[x] == 0
				&& ft_strncmp(argv[(y - x)], "0", 1)))
		{
			write(2, "Error\n", 7);
			return (-1);
		}
		x++;
	}
	return (x);
}
