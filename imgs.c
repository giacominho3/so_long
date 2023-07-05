/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 11:20:10 by gifulvi           #+#    #+#             */
/*   Updated: 2022/05/19 17:58:57 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	set_image_dyn(t_game *g, char mat_elem, int i, int j)
{
	if (mat_elem == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, i * 64, j * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img.pg, i * 64, j * 64);
	}
	else if (mat_elem == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, i * 64, j * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img.coll, i * 64, j * 64);
	}
	else if (mat_elem == 'K')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, i * 64, j * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img.enemy, i * 64, j * 64);
	}
	else if (mat_elem == 'L')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, i * 64, j * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img.left, i * 64, j * 64);
	}
	else if (mat_elem == 'R')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, i * 64, j * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img.right, i * 64, j * 64);
	}
}

void	set_image_stat(t_game *g, char mat_elem, int i, int j)
{
	if (mat_elem == '1')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, i * 64, j * 64);
	}
	else if (mat_elem == '0')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, i * 64, j * 64);
	}
	else if (mat_elem == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.floor, i * 64, j * 64);
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, i * 64, j * 64);
	}
	else
		set_image_dyn(g, mat_elem, i, j);
}

void	load_imgs(t_game *g)
{
	int	x;
	int	y;

	g->img.wall = mlx_xpm_file_to_image(g->mlx, "./images/wall.xpm", &x, &y);
	g->img.floor = mlx_xpm_file_to_image(g->mlx, "./images/floor.xpm", &x, &y);
	g->img.exit = mlx_xpm_file_to_image(g->mlx, "./images/exit.xpm", &x, &y);
	g->img.pg = mlx_xpm_file_to_image(g->mlx, "./images/pg.xpm", &x, &y);
	g->img.coll = mlx_xpm_file_to_image(g->mlx, "./images/coll.xpm", &x, &y);
	g->img.enemy = mlx_xpm_file_to_image(g->mlx, "./images/enemy.xpm", &x, &y);
	g->img.go = mlx_xpm_file_to_image(g->mlx, "./images/game_over.xpm", &x, &y);
	g->img.win = mlx_xpm_file_to_image(g->mlx, "./images/win.xpm", &x, &y);
	g->img.left = mlx_xpm_file_to_image(g->mlx, "./images/left.xpm", &x, &y);
	g->img.right = mlx_xpm_file_to_image(g->mlx, "./images/right.xpm", &x, &y);
}

void	load_map(t_game *g)
{
	int	r;
	int	c;

	r = 0;
	while (r < g->map.r)
	{
		c = 0;
		while (c < g->map.c)
		{
			set_image_stat(g, g->map.map[r][c], c, r);
			c++;
		}
		r++;
	}
}

void	end_game(t_game *g, int status)
{
	if (!status)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.go, \
		(g->map.c * 32 - 160), (g->map.r * 32 - 160));
		g->pg.end = 0;
		mlx_loop_hook(g->mlx, &waiter, NULL);
	}
	else
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.win, \
		(g->map.c * 32 - 160), (g->map.r * 32 - 160));
		g->pg.end = 0;
		mlx_loop_hook(g->mlx, &waiter, NULL);
	}
}
