/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:34:51 by eramanit          #+#    #+#             */
/*   Updated: 2025/05/31 21:24:14 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_detect_nl(char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_check_buff(ssize_t rd, char *buff)
{
	if (!buff)
		return (NULL);
	if ((!rd && !ft_strlen2(buff)) || rd < 0)
	{
		free(buff);
		return (NULL);
	}
	else
		return (buff);
}

char	*ft_join2(char *s1, char *s2)
{
	char	*dest;
	int		l1;
	int		l2;

	l1 = 0;
	l2 = 0;
	dest = malloc(ft_strlen2(s1) + ft_strlen2(s2) + BUFFER_SIZE);
	if (!dest)
		return (NULL);
	while (s1[l1])
	{
		dest[l1] = s1[l1];
		l1++;
	}
	while (s2[l2])
		dest[l1++] = s2[l2++];
	dest[l1] = 0;
	free(s1);
	free(s2);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char		*line;
	ssize_t		rd;

	rd = 1;
	if (!readed)
	{
		readed = ft_read(fd, &rd);
		readed = ft_check_buff(rd, readed);
		if (!readed)
			return (NULL);
	}
	while (!(ft_detect_nl(readed) || rd == 0 || rd == -1))
	{
		line = ft_read(fd, &rd);
		readed = ft_check_buff(rd, ft_join2(readed, line));
		if (!readed)
			return (NULL);
	}
	line = ft_strdup2(readed);
	readed = ft_refresh(readed);
	return (line);
}
