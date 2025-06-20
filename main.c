/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 22:22:59 by eramanit          #+#    #+#             */
/*   Updated: 2025/06/20 11:55:19 by eramanit         ###   ########.fr       */
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

// void	ft_handle_file(int ac, char const **av)
// {

// }

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
	fd = 0;

	while (fdf.map.rows[fd])
	{
		ft_putstr_fd(fdf.map.rows[fd], 1);
		fd++;
	}
	ft_free_map(fdf.map);
	return (0);
}
