/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:33:37 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/25 12:39:02 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				diff;
	unsigned int	i;

	i = 0;
	diff = 0;
	if (!(unsigned char *)(s1) && !(unsigned char *)(s2))
		return (diff);
	while (i < n)
	{
		diff = *(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i);
		if (diff || !*(unsigned char *)(s1 + i) || !*(unsigned char *)(s2 + i))
			return (diff);
		i++;
	}
	return (0);
}
