/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:33:27 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/06 21:15:40 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	testing(int sizea, int sizeb, int argc)
{
	char	*buffer;

	while (get_next_line(0, &buffer))
	{
		if (!valid_act(buffer))
		{
			write(2, "Error\n", 7);
			free(buffer);
			exit(1);
		}
		if (!ft_strncmp(buffer, "s", 1))
			do_swap(buffer, sizea, sizeb);
		else if (!ft_strncmp(buffer, "r", 1))
			do_rotate(buffer, sizea, sizeb);
		else
		{
			sizea = do_push(buffer, sizea, sizeb);
			sizeb = (argc - 1) - sizea;
		}
		free(buffer);
	}
	free (buffer);
}

int	main(int argc, char *argv[])
{
	int		sizea;
	int		sizeb;

	t_checker_stacks.stack_a = ft_calloc(argc, sizeof(int));
	t_checker_stacks.stack_b = ft_calloc(argc, sizeof(int));
	sizea = make_stack(argv, t_checker_stacks.stack_a, argc);
	if (sizea < 0)
	{
		free (t_checker_stacks.stack_a);
		free (t_checker_stacks.stack_b);
		write(2, "Error\n", 7);
		return (-1);
	}
	sizeb = (argc - 1) - sizea;
	testing(sizea, sizeb, argc);
	if (is_sorted(t_checker_stacks.stack_a, sizea) && argc > 1)
		write(1, "OK\n", 4);
	else if (!is_sorted(t_checker_stacks.stack_a, sizea) && argc > 1)
		write(1, "KO\n", 4);
	free (t_checker_stacks.stack_a);
	free (t_checker_stacks.stack_b);
	return (0);
}
