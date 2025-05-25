/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 19:25:49 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/25 12:42:03 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;
	size_t	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	s = ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!s)
		return (s);
	i = 0;
	while (i < len1)
	{
		s[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < len2)
	{
		s[i + len1] = s2[i];
		i++;
	}
	return (s);
}
