/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:31:14 by eramanit          #+#    #+#             */
/*   Updated: 2025/07/27 15:37:34 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_quit(t_fdf *fdf)
{
	mlx_loop_end(fdf->mlx);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_image(fdf->mlx, fdf->canvas);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	ft_free_map(fdf->map);
	ft_putstr_fd("quitting!\n", 1);
	exit(0);
	return (0);
}
