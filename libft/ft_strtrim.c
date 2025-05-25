/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 21:01:53 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/25 12:52:07 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	j = 1;
	if (!*s1)
		return (ft_calloc(1, sizeof(char)));
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (!s1[i])
		return (ft_calloc(1, sizeof(char)));
	l = ft_strlen(s1 + i);
	while (ft_strchr(set, s1[i + l - j]) && j <= l)
		j++;
	res = ft_calloc(l - j + 2, sizeof(char));
	if (res)
		ft_memcpy(res, s1 + i, l - j + 1);
	return (res);
}
