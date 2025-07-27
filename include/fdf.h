/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 00:22:12 by eramanit          #+#    #+#             */
/*   Updated: 2025/07/27 10:00:00 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "get_next_line.h"
# define WIDTH 300
# define HEIGHT 300

typedef struct s_map
{
	size_t	w;
	size_t	h;
	char	**rows;
}	t_map;

typedef struct s_fdf
{
	void	*win;
	void	*canvas;
	void	*mlx;
	t_map	map;
}	t_fdf;

t_map	ft_init_map(int fd);
size_t	ft_get_len(char *row);
void	ft_free_map(t_map map);

#endif
