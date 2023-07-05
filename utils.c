/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 17:05:18 by gifulvi           #+#    #+#             */
/*   Updated: 2022/05/19 18:11:14 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	are_ok(int pc, int cc, int ec)
{
	if (pc != 1)
		return (0);
	if (cc < 1)
		return (0);
	if (ec != 1)
		return (0);
	return (1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	get_player(t_game *g, t_map *map)
{
	int	r;
	int	c;

	r = 0;
	while (r < map->r)
	{
		c = 0;
		while (c < map->c)
		{
			if (map->map[r][c] == 'P')
			{
				g->pg.x = c;
				g->pg.y = r;
			}
			c++;
		}
		r++;
	}
}

void	get_rows(t_map *map, char *file)
{
	int	rows;

	rows = 0;
	while (*file)
	{
		if (*file == '\n')
			rows++;
		file++;
	}
	if (*file == '\0')
		rows++;
	map->r = rows;
}

void	get_columns(t_map *map, char *file)
{
	int	col;
	int	max_len;

	col = 0;
	max_len = 0;
	while (*file++ != '\n')
		max_len++;
	while (*file != '\0')
	{
		while (*file != '\n' && *file)
		{
			col++;
			file++;
		}
		if (col != max_len)
			exit(0);
		col = 0;
		if (*file == '\0')
			break ;
		file++;
	}
	map->c = max_len;
}
