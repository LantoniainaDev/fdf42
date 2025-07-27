/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:50:17 by eramanit          #+#    #+#             */
/*   Updated: 2025/07/27 09:31:24 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

size_t	ft_get_len(char *row)
{
	size_t	len;
	size_t	i;

	i = 1;
	len = 0;
	while (row[i])
	{
		if (row[i - 1] > ' ' && row[i] <= ' ')
			len++;
		i++;
	}
	return (len);
}

t_map	ft_init_map(int fd)
{
	t_map	map;
	char	*first_r;
	size_t	i;

	i = 0;
	first_r = get_next_line(fd);
	map.w = ft_get_len(first_r);
	map.rows = ft_calloc(sizeof(void *), map.w + 1);
	if (!map.rows)
		exit(0);
	map.rows[i] = first_r;
	while (map.rows[i])
	{
		i++;
		if (i < map.w)
			map.rows[i] = get_next_line(fd);
		else
			free(get_next_line(fd));
	}
	return (map);
}

void	ft_free_map(t_map map)
{
	size_t	i;

	i = 0;
	while (map.rows[i])
	{
		free(map.rows[i]);
		i++;
	}
	free(map.rows);
}
