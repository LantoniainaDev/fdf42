/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 03:45:12 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:42:54 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = 0;
	slen = 0;
	i = 0;
	while (dest[dlen])
		dlen++;
	while (src[slen])
		slen++;
	if ((!*dest && !size) || dlen >= size)
	{
		if (slen)
			return (slen + size);
		else
			return (0);
	}
	while (src[i] && dlen + i < size - 1)
	{
		dest[i + dlen] = src[i];
		i++;
	}
	dest[i + dlen] = 0;
	return (slen + dlen);
}
