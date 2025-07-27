/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramanit <eramanit@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:16:57 by eramanit          #+#    #+#             */
/*   Updated: 2025/07/27 16:36:33 by eramanit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_color(unsigned int color, int x, int y, t_addr addr)
{
	char	*pxl;

	pxl = addr.addr + (y * addr.sl + x * (addr.bpp / 8));
	*(unsigned int *)pxl = color;
}

void	ft_draw_line(char *p1, char *p2, t_fdf env)
{
	ft_putstr_fd(p1, 1);
	ft_putstr_fd("\n", 1);
	ft_putstr_fd(p2, 1);
	ft_put_color(0xffff0000, WIDTH / 2, HEIGHT / 2, env.addr);
}
