/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:46:49 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/01 08:46:51 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	int	sizea;
	int	sizeb;

	t_stacks.stack_a = ft_calloc(argc, sizeof(int));
	t_stacks.stack_b = ft_calloc(argc, sizeof(int));
	if (!t_stacks.stack_a || !t_stacks.stack_b)
		return (-1);
	if (argc > 1024 || argc == 1)
		return (1);
	sizea = make_stack(argv, t_stacks.stack_a, argc);
	if (is_sorted(t_stacks.stack_a, sizea))
		return (0);
	if (sizea == -1)
		return (1);
	sizeb = (argc - 1) - sizea;
	if (sizea == 2 || sizea == 3)
		sort_3(t_stacks.stack_a, sizea);
	else if (sizea == 4 || sizea == 5)
		sort_5(t_stacks.stack_a, t_stacks.stack_b, sizea, sizeb);
	else
		lightning_sort(t_stacks.stack_a, t_stacks.stack_b, sizea, sizeb);
	free(t_stacks.stack_a);
	free(t_stacks.stack_b);
}
