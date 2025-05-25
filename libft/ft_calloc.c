/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:22:05 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:40:57 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void		*ptr;
	size_t		i;

	i = 0;
	ptr = NULL;
	if (!nmemb || !size)
		return (malloc(0));
	else if (nmemb > (((size_t) -1) / (size_t) size))
		return (ptr);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (ptr);
	while (i < nmemb * size)
	{
		*(unsigned char *)(ptr + i) = 0;
		i++;
	}
	return (ptr);
}
