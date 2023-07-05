/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 19:19:57 by gifulvi           #+#    #+#             */
/*   Updated: 2022/04/28 17:02:05 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	check_features(char **map, int r, int c, int i)
{
	int	pg_counter;
	int	coll_counter;
	int	exit_counter;
	int	j;

	j = 0;
	pg_counter = 0;
	coll_counter = 0;
	exit_counter = 0;
	while (i < r)
	{
		while (j < c)
		{
			if (map[i][j] == 'P')
				pg_counter++;
			if (map[i][j] == 'C')
				coll_counter++;
			if (map[i][j] == 'E')
				exit_counter++;
			j++;
		}
		j = 0;
		i++;
	}
	return (are_ok(pg_counter, coll_counter, exit_counter));
}

int	map_checker(char **map, int r, int c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < r)
	{
		if (map[i][0] != '1' || map[i][c - 1] != '1')
			return (1);
		i++;
	}
	while (j < c)
	{
		if (map[0][j] != '1' || map[r - 1][j] != '1')
			return (1);
		j++;
	}
	i = 0;
	j = 0;
	if (!check_features(map, r, c, 0))
		return (1);
	return (0);
}

int	ft_check_map_name(char *filename)
{
	int	len;

	len = 0;
	while (filename[len])
		len++;
	if (filename[len - 4] != '.' || filename[len - 3] != 'b'
		|| filename[len - 2] != 'e' || filename[len - 1] != 'r')
		return (0);
	else
		return (1);
}

void	ft_get_map(char *path, t_game *g)
{
	int		fd;
	char	**map_matrix;
	int		i;

	if (!ft_check_map_name(path))
		exit(0);
	fd = open(path, O_RDONLY);
	read_all_file(fd, g);
	close(fd);
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(0);
	map_matrix = malloc(sizeof(char *) * g->map.r);
	i = 0;
	while (i < g->map.r)
	{
		map_matrix[i] = malloc(sizeof(char) * g->map.c);
		map_matrix[i] = get_next_line(fd);
		i++;
	}
	if (map_checker(map_matrix, g->map.r, g->map.c))
		exit(0);
	g->map.map = map_matrix;
	get_player(g, &(g->map));
	get_coins(g, &(g->map));
}
