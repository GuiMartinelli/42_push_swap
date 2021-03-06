/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 08:08:39 by guferrei          #+#    #+#             */
/*   Updated: 2021/10/01 08:08:42 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	c;
	size_t	a;

	c = 0;
	if (!*little)
		return ((char *)big);
	while (*big && c < len)
	{
		a = 0;
		while (*(big + a) == *(little + a))
		{
			if ((c + 1) + a > len)
				return (NULL);
			else if (*(little + (a + 1)) == '\0')
				return ((char *)big);
			a++;
		}
		big++;
		c++;
	}
	return (NULL);
}
