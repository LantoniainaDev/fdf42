/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:34:31 by eramanit          #+#    #+#             */
/*   Updated: 2025/05/31 19:39:19 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup2(char *src)
{
	char	*clone;
	size_t	l;

	l = 0;
	if (!src)
		return (NULL);
	while (src[l] && src[l] != '\n')
		l++;
	if (src[l])
		l++;
	clone = malloc((l + 1) * sizeof(char));
	if (!clone)
		return (clone);
	clone[l] = '\0';
	while (l)
	{
		l--;
		clone[l] = src[l];
	}
	return (clone);
}

int	ft_strlen2(char *s)
{
	int	l;

	l = 0;
	if (!s)
		return (0);
	while (s[l])
		l++;
	return (l);
}

int	ft_int_l_i(size_t *l, size_t *i, char *buff)
{
	*i = 0;
	while (buff[*i] && buff[*i] != '\n')
		*i += 1;
	if (buff[*i] == '\n')
		*i += 1;
	*l = ft_strlen2(buff + *i);
	return (!l);
}

char	*ft_refresh(char *buff)
{
	char	*clone;
	size_t	l;
	size_t	i;

	if (ft_int_l_i(&l, &i, buff))
	{
		free(buff);
		return (NULL);
	}
	clone = malloc((l + 2) * sizeof(char));
	if (!clone)
	{
		free(buff);
		return (clone);
	}
	clone[l] = '\0';
	l = 0;
	while (buff[l + i])
	{
		clone[l] = buff[l + i];
		l++;
	}
	free(buff);
	return (clone);
}

char	*ft_read(int fd, ssize_t *rd)
{
	char	*buff;
	int		i;

	i = 0;
	if (BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(BUFFER_SIZE + 2);
	if (!buff)
	{
		return (NULL);
	}
	while (i < BUFFER_SIZE)
	{
		buff[i] = 0;
		i++;
	}
	buff[BUFFER_SIZE] = 0;
	if (!buff)
		return (NULL);
	*rd = read(fd, buff, BUFFER_SIZE);
	return (buff);
}
