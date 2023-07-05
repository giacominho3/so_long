/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 16:06:45 by gifulvi           #+#    #+#             */
/*   Updated: 2022/05/09 18:41:44 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_right(t_game *g)
{
	if (g->map.map[g->pg.y][g->pg.x + 1] == '1')
		return ;
	else if (g->map.map[g->pg.y][g->pg.x + 1] == '0')
		do_move_x(g, 1);
	else if (g->map.map[g->pg.y][g->pg.x + 1] == 'C')
	{
		do_move_x(g, 1);
		g->pg.coins--;
	}
	else if (g->map.map[g->pg.y][g->pg.x + 1] == 'E')
	{
		if (g->pg.coins)
			return ;
		else
			end_game(g, 1);
	}
	else if (g->map.map[g->pg.y][g->pg.x + 1] == 'K')
		end_game(g, 0);
	else if (g->map.map[g->pg.y][g->pg.x + 1] == 'L' \
	|| g->map.map[g->pg.y][g->pg.x + 1] == 'R')
		pacman_effect(g);
	move_counter(g);
}

void	move_left(t_game *g)
{
	if (g->map.map[g->pg.y][g->pg.x - 1] == '1')
		return ;
	else if (g->map.map[g->pg.y][g->pg.x - 1] == '0')
		do_move_x(g, -1);
	else if (g->map.map[g->pg.y][g->pg.x - 1] == 'C')
	{
		do_move_x(g, -1);
		g->pg.coins--;
	}
	else if (g->map.map[g->pg.y][g->pg.x - 1] == 'E')
	{
		if (g->pg.coins)
			return ;
		else
			end_game(g, 1);
	}
	else if (g->map.map[g->pg.y][g->pg.x - 1] == 'K')
		end_game(g, 0);
	else if (g->map.map[g->pg.y][g->pg.x - 1] == 'L' \
	|| g->map.map[g->pg.y][g->pg.x - 1] == 'R')
		pacman_effect(g);
	move_counter(g);
}

void	move_up(t_game *g)
{
	if (g->map.map[g->pg.y - 1][g->pg.x] == '1')
		return ;
	else if (g->map.map[g->pg.y - 1][g->pg.x] == '0')
		do_move_y(g, -1);
	else if (g->map.map[g->pg.y - 1][g->pg.x] == 'C')
	{
		do_move_y(g, -1);
		g->pg.coins--;
	}
	else if (g->map.map[g->pg.y - 1][g->pg.x] == 'E')
	{
		if (g->pg.coins)
			return ;
		else
			end_game(g, 1);
	}
	else if (g->map.map[g->pg.y - 1][g->pg.x] == 'K')
		end_game(g, 0);
	else if (g->map.map[g->pg.y - 1][g->pg.x] == 'L' \
	|| g->map.map[g->pg.y - 1][g->pg.x] == 'R')
		pacman_effect(g);
	move_counter(g);
}

void	move_down(t_game *g)
{
	if (g->map.map[g->pg.y + 1][g->pg.x] == '1')
		return ;
	else if (g->map.map[g->pg.y + 1][g->pg.x] == '0')
		do_move_y(g, 1);
	else if (g->map.map[g->pg.y + 1][g->pg.x] == 'C')
	{
		do_move_y(g, 1);
		g->pg.coins--;
	}
	else if (g->map.map[g->pg.y + 1][g->pg.x] == 'E')
	{
		if (g->pg.coins)
			return ;
		else
			end_game(g, 1);
	}
	else if (g->map.map[g->pg.y + 1][g->pg.x] == 'K')
		end_game(g, 0);
	else if (g->map.map[g->pg.y + 1][g->pg.x] == 'L' \
	|| g->map.map[g->pg.y + 1][g->pg.x] == 'R')
		pacman_effect(g);
	move_counter(g);
}

int	key_pressed(int key, t_game *g)
{
	if (key == ESC)
		exit(0);
	if ((key == D || key == K_RIGHT) && g->pg.end)
		move_right(g);
	if ((key == A || key == K_LEFT) && g->pg.end)
		move_left(g);
	if ((key == W || key == K_UP) && g->pg.end)
		move_up(g);
	if ((key == S || key == K_DOWN) && g->pg.end)
		move_down(g);
	return (0);
}
