/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 12:31:14 by eramanit          #+#    #+#             */
/*   Updated: 2025/07/27 16:36:09 by eramanit         ###   ########.fr       */
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
	exit(0);
	return (0);
}

void	ft_init_addr(t_fdf *fdf)
{
	int	bpp;
	int	sl;
	int	endian;

	fdf->addr.addr = mlx_get_data_addr(fdf->canvas, &bpp, &sl, &endian);
	fdf->addr.bpp = bpp;
	fdf->addr.sl = sl;
	fdf->addr.endian = endian;
}

void	ft_init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "fdf");
	fdf->canvas = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	ft_init_addr(fdf);
	ft_draw_line("1", "2,0xff", *fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->canvas, 0, 0);
	mlx_hook(fdf->win, 17, 0, handle_quit, fdf);
}
