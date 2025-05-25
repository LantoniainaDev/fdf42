/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 15:56:29 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:42:39 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	char	*pointer;

	pointer = (char *) s;
	c = (char ) c;
	while (*pointer)
	{
		if (c == *pointer)
			return (pointer);
		pointer++;
	}
	if (c == 0)
		return (pointer);
	return (0);
}
