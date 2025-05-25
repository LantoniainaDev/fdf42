/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:06:39 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:42:57 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	s = 0;
	i = 0;
	while (src[s])
		s++;
	while (i < size)
	{
		dest[i] = src[i];
		if (!src[i])
			break ;
		i++;
	}
	if (i == size)
		dest[i - 1] = 0;
	return (s);
}
