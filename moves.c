/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:33:56 by gifulvi           #+#    #+#             */
/*   Updated: 2022/05/12 15:43:20 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_counter(t_game *g)
{
	char	*s;

	if (g->pg.end == 0)
		return ;
	s = ft_itoa(g->pg.moves);
	mlx_put_image_to_window(g->mlx, g->win, g->img.wall, 0, 0);
	mlx_put_image_to_window(g->mlx, g->win, g->img.wall, 1, 0);
	mlx_string_put(g->mlx, g->win, 32, 32, 16393683, s);
	ft_putstr(s);
	ft_putstr("\n");
	free(s);
}

void	do_move_x(t_game *g, int mod)
{
	g->map.map[g->pg.y][g->pg.x] = '0';
	set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
	g->pg.x += mod;
	g->map.map[g->pg.y][g->pg.x] = 'P';
	set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
	g->pg.moves++;
}

void	do_move_y(t_game *g, int mod)
{
	g->map.map[g->pg.y][g->pg.x] = '0';
	set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
	g->pg.y += mod;
	g->map.map[g->pg.y][g->pg.x] = 'P';
	set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
	g->pg.moves++;
}

void	pacman_effect(t_game *g)
{
	if (g->pg.x == 2 && g->pg.y == 9)
	{
		if (g->map.map[9][16] == 'C')
			g->pg.coins--;
		g->map.map[g->pg.y][g->pg.x] = '0';
		set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
		g->pg.x = 16;
		g->pg.y = 9;
		g->map.map[g->pg.y][g->pg.x] = 'P';
		set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
	}
	else if (g->pg.x == 16 && g->pg.y == 9)
	{
		if (g->map.map[9][2] == 'C')
			g->pg.coins--;
		g->map.map[g->pg.y][g->pg.x] = '0';
		set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
		g->pg.x = 2;
		g->pg.y = 9;
		g->map.map[g->pg.y][g->pg.x] = 'P';
		set_image_stat(g, g->map.map[g->pg.y][g->pg.x], g->pg.x, g->pg.y);
	}
	g->pg.moves++;
}
