/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 17:22:03 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:44:48 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	l;

	if (start > ft_strlen(s))
		return (ft_calloc(1, 1));
	l = ft_min(len, ft_strlen(s + start));
	res = (char *)ft_calloc(l + 1, sizeof(char));
	i = 0;
	if (!res)
		return (res);
	while (i < l && s[i + start])
	{
		res[i] = s[i + start];
		i++;
	}
	return (res);
}
