/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 21:35:58 by guferrei          #+#    #+#             */
/*   Updated: 2021/09/21 07:49:19 by guferrei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	int	cont;

	cont = 0;
	while (cont < (int)n)
	{
		if (*(unsigned char *)src == (unsigned char)c)
		{
			*(unsigned char *)dest = *(unsigned char *)src;
			dest++;
			return (dest);
		}
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
		cont++;
	}
	return (NULL);
}
