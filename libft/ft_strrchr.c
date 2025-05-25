/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 16:14:44 by eramanit          #+#    #+#             */
/*   Updated: 2025/03/24 08:44:42 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;

	pointer = (char *) s;
	c = (char) c;
	while (pointer[0])
		pointer++;
	if (c == 0)
		return (pointer);
	while (pointer >= s)
	{
		if (c == *pointer)
			return (pointer);
		pointer--;
	}
	return (0);
}
