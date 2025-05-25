/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:22:59 by eramanit          #+#    #+#             */
/*   Updated: 2025/05/25 05:43:03 by eramanit         ###   ########.fr       */
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

int gere_mouse(int x,int y,int button,void*toto)
{
	(void)x;
	(void)y;
	(void)button;
	(void)toto;
  	printf("Mouse event - new win\n");
	return (0);
}

int main(int ac, char const **av)
{
	char	**map;
	void 	*mlx;
	void 	*win;

	ft_handle_arg(ac, av);
	map = ft_read_file((char *) av[1]);
	freeMap(map);
	mlx = mlx_init();
	win = mlx_new_window(mlx,300,300,"win");
	mlx_mouse_hook(win,gere_mouse,0);
	mlx_loop(mlx);
	return (0);
}
