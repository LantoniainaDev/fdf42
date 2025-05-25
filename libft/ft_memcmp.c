/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 23:41:39 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:42:05 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				diff;
	unsigned char	c1;
	unsigned char	c2;
	size_t			i;

	i = 0;
	diff = 0;
	c1 = *(unsigned char *)(s1 + i);
	c2 = *(unsigned char *)(s2 + i);
	while (!diff && i < n)
	{
		c1 = *(unsigned char *)(s1 + i);
		c2 = *(unsigned char *)(s2 + i);
		diff = c1 - c2;
		i++;
	}
	return (diff);
}
