/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:22:59 by eramanit          #+#    #+#             */
/*   Updated: 2025/05/30 14:25:27 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_handle_arg(int ac, char const **av)
{
	if (ac != 2)
	{
		ft_putstr_fd("Usage : ", 1);
		ft_putstr_fd((char *) av[0], 1);
		ft_putstr_fd(" <filename>\n", 1);
		exit(1);
	}
}

char	**ft_read_file(char *file)
{
	char	**map = NULL;
	char	*buff;
	int		fd;
	ssize_t	s;
	
	fd = open(file, O_RDONLY);
	buff = ft_calloc(28017630 + 1 , sizeof(char));
	if (!buff)
		exit(1);
	s = read(fd, buff, 28017630);
	if(s == -1 || s >= 28017630)
	{
		perror("Le fichier n'existe pas");
		exit(1);
	}
	map = ft_split((const char *) buff, '\n');
	close(fd);
	free(buff);
	return (map);
}

void	freeMap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int gere_mouse(int button, int x,int y,void*toto)
{
	(void)button;
	(void)toto;
  	printf("Mouse event - new win (%d,%d)\n", x, y);
	return (0);
}

void	ft_draw_vector(void	*mlx, void *win, t_point p1, t_point p2)
{
	int	i;
	int	j;
	int color;
	float	a;
	float	b;

	a =(float) (p1.y - p2.y) / (p1.x - p2.x);
	b =(float) a * -(p1.x) + p1.y;
	color = 0xffffff;
	if (p2.x < p1.x)
		i = p2.x;
	else
		i = p1.x;
	while ((i <= p2.x && i >= p1.x) || (i <= p1.x && i >= p2.x))
	{
		j = a * i + b;
		mlx_pixel_put(mlx, win, i, j, color);
		i++;
	}
}

int main(int ac, char const **av)
{
	char	**map;
	void 	*mlx;
	void 	*win;
	void 	*canvas;
	void 	*img;

	t_point p1 = {1, 0};
	t_point p2 = {20, 250};

	ft_handle_arg(ac, av);
	map = ft_read_file((char *) av[1]);
	freeMap(map);
	mlx = mlx_init();
	win = mlx_new_window(mlx,WIDTH,HEIGHT,"FdF");
	canvas = mlx_new_image(mlx, WIDTH, HEIGHT);
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	
	ft_draw_vector(mlx, win, p1, p2);
	
	mlx_mouse_hook(win,gere_mouse,0);
	mlx_loop(mlx);
	mlx_destroy_image(mlx, img);
	mlx_destroy_window(mlx, win);
	return (0);
}
