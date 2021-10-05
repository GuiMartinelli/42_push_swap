/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:33:27 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/05 13:52:29 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	print(int size)
{
	size--;

	while (size >= 0)
	{
		ft_printf("%d\n", t_checker_stacks.stack_a[size]);
		size--;
	}
	ft_printf("\n");
}

int	testing(int sizea, int sizeb)
{
	char	*buffer;
	
	while(get_next_line(0, &buffer))
	{
		if (!ft_strncmp(buffer, "sa", 2))
			checker_s(t_checker_stacks.stack_a, sizea);
		else if (!ft_strncmp(buffer, "sb", 2))
			checker_s(t_checker_stacks.stack_b, sizeb);
		else if (!ft_strncmp(buffer, "ss", 2))
		{
			checker_s(t_checker_stacks.stack_a, sizea);
			checker_s(t_checker_stacks.stack_b, sizeb);
		}
		else if (!ft_strncmp(buffer, "pa", 2))
		{
			sizeb = checker_p(t_checker_stacks.stack_a, t_checker_stacks.stack_b, sizea, sizeb);
			sizea++;
		}
		else if (!ft_strncmp(buffer, "pb", 2))
		{
			sizea = checker_p(t_checker_stacks.stack_b, t_checker_stacks.stack_a, sizeb, sizea);
			sizeb++;
		}
		else if (!ft_strncmp(buffer, "rra", 3))
			checker_rr(t_checker_stacks.stack_a, sizea);
		else if (!ft_strncmp(buffer, "rrb", 3))
			checker_rr(t_checker_stacks.stack_b, sizeb);
		else if (!ft_strncmp(buffer, "rrr", 3))
		{
			checker_rr(t_checker_stacks.stack_a, sizea);
			checker_rr(t_checker_stacks.stack_b, sizeb);
		}
		else if (!ft_strncmp(buffer, "ra", 2))
			checker_r(t_checker_stacks.stack_a, sizea);
		else if (!ft_strncmp(buffer, "rb", 2))
			checker_r(t_checker_stacks.stack_b, sizeb);
		else if (!ft_strncmp(buffer, "rr", 2))
		{
			checker_r(t_checker_stacks.stack_a, sizea);
			checker_r(t_checker_stacks.stack_b, sizeb);
		}
		else
		{
			write(2, "Error\n", 7);
			free (buffer);
			return (0);
		}
	}
	free (buffer);
	return (1);
}

int	main(int argc, char *argv[])
{
	int		sizea;
	int		sizeb;
	
	t_checker_stacks.stack_a = ft_calloc(argc, sizeof(int));
	t_checker_stacks.stack_b = ft_calloc(argc, sizeof(int));
	if (!t_checker_stacks.stack_a || !t_checker_stacks.stack_b
		|| argc == 1)
	{
		write(2, "Error\n", 7);
		return (-1);
	}
	sizea = make_stack(argv, t_checker_stacks.stack_a, argc);
	if (sizea == -1)
		return (1);
	sizeb = (argc - 1) - sizea;
	if (testing(sizea, sizeb))
	{
		if (is_sorted(t_checker_stacks.stack_a, sizea))
			write(1, "OK\n", 4);
		else
			write(1, "KO\n", 4);
	}
	free (t_checker_stacks.stack_a);
	free (t_checker_stacks.stack_b);
	return (0);
}