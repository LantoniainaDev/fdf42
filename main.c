/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:22:59 by eramanit          #+#    #+#             */
/*   Updated: 2025/07/27 11:58:36 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	test_map(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map.rows[i])
	{
		j = 0;
		while (j < map.w && map.rows[i][j])
		{
			ft_putstr_fd(map.rows[i][j], 1);
			ft_putstr_fd(" ", 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}

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

int	handle_key(int button)
{
	printf("Keyboard event - new win %d\n", button);
	return (0);
}

int	main(int ac, char const **av)
{
	t_fdf	fdf;
	int		fd;

	ft_handle_arg(ac, av);
	fd = open(av[1], O_RDONLY);
	fdf.map = ft_init_map(fd);
	close(fd);
	if (ft_check_map(fdf.map))
		exit(0);
	ft_init_fdf(&fdf);
	ft_free_map(fdf.map);
	return (0);
}
