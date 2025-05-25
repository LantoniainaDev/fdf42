/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 22:53:14 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/25 12:32:49 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*pointer;
	unsigned char	cl;

	i = 0;
	pointer = (unsigned char *) s;
	cl = (unsigned char) c;
	while (i < n)
	{
		if (pointer[i] == cl)
			return ((void *)(pointer + i));
		i++;
	}
	return (0);
}
