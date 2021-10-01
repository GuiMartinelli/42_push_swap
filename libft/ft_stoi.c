/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 13:53:43 by guferrei          #+#    #+#             */
/*   Updated: 2021/09/16 07:54:19 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	overflow(int signal, long x)
{
	if (x > 2147483648 || (x == 2147483648 && signal == 1))
		return (1);
	else
		return (0);
}

int	ft_stoi(const char *ptr)
{
	int			s;
	long int	n;

	s = 1;
	n = 0;
	if (*ptr == '-')
	{
		s = s * -1;
		ptr++;
	}
	else if (*ptr == '+')
		ptr++;
	while (*ptr >= 48 && *ptr <= 57)
	{
		n = n * 10;
		n = n + ((int)*ptr - 48);
		ptr++;
	}
	if (overflow(s, n))
		return (0);
	return (n * s);
}
