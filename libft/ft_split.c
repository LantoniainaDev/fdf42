/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:22:32 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/25 13:03:41 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char *trimed, char sep)
{
	size_t	i;
	size_t	c;
	_Bool	wasword;

	wasword = 1;
	i = 0;
	c = 1;
	while (trimed[i])
	{
		if (trimed[i] != sep)
			wasword = 1;
		else
		{
			if (wasword)
			{
				c++;
				trimed[i] = 0;
			}
			wasword = 0;
		}
		i++;
	}
	return (c);
}

static char	*ft_trim(char const *s1, char set)
{
	char	*res;
	size_t	i;
	size_t	l;
	size_t	j;

	i = 0;
	j = 1;
	if (!*s1)
		return (ft_calloc(1, sizeof(char)));
	while (s1[i] == set && s1[i])
		i++;
	if (!s1[i])
		return (ft_calloc(1, sizeof(char)));
	l = ft_strlen(s1 + i);
	while (s1[i + l - j] == set && j <= l)
		j++;
	res = ft_calloc(l - j + 2, sizeof(char));
	if (res)
		ft_memcpy(res, s1 + i, l - j + 1);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	char	*clone;
	size_t	start;
	size_t	len;
	size_t	i;

	start = 0;
	i = 0;
	clone = ft_trim(s, c);
	if (!*clone)
	{
		free(clone);
		return (ft_calloc(1, sizeof(char **)));
	}
	len = ft_strlen(clone);
	tab = ft_calloc(ft_count_word(clone, c) + 1, sizeof(char *));
	tab[i] = ft_trim(clone + start, c);
	while (start < len)
	{
		if (!clone[start])
			tab[++i] = ft_trim(clone + start + 1, c);
		start++;
	}
	free(clone);
	return (tab);
}
