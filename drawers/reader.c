/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 10:50:17 by eramanit          #+#    #+#             */
/*   Updated: 2025/07/27 12:25:46 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_set_size(t_map	*map)
{
	size_t	h;
	size_t	w;
	size_t	min;

	h = 0;
	min = 0;
	while (map->rows[h])
	{
		w = 0;
		while (map->rows[h][w])
			w++;
		if (!h)
			min = w;
		if (w < min)
		{
			min = ((size_t)(-1));
			break ;
		}
		h++;
	}
	map->w = min;
	map->h = h;
}

void	ft_free_map(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (map.rows[i])
	{
		j = 0;
		while (map.rows[i][j])
		{
			free(map.rows[i][j]);
			j++;
		}
		free(map.rows[i][j]);
		free(map.rows[i]);
		i++;
	}
	free(map.rows[i]);
	free(map.rows);
}

t_map	ft_init_map(int fd)
{
	t_map	map;
	size_t	i;
	char	*line;
	char	*temp;

	i = 0;
	map.rows = ft_calloc(sizeof(void *), 1000 + 1);
	if (!map.rows)
		return (map);
	line = get_next_line(fd);
	while (line)
	{
		temp = ft_strtrim(line, "\n ");
		map.rows[i] = ft_split(temp, ' ');
		free(line);
		free(temp);
		line = get_next_line(fd);
		i++;
	}
	ft_set_size(&map);
	return (map);
}

int	ft_check_map(t_map map)
{
	int	err;

	err = map.w == (size_t) -1;
	err = err | !map.rows;
	if (err)
	{
		ft_free_map(map);
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	return (0);
}
