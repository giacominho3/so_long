/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 17:58:34 by gifulvi           #+#    #+#             */
/*   Updated: 2022/05/19 18:10:02 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_game	g;

	if (argc != 2)
		return (0);
	ft_get_map(argv[1], &g);
	g.mlx = mlx_init();
	g.win = mlx_new_window(g.mlx, 64 * g.map.c, 64 * g.map.r, \
	"Lithuania Simulator");
	load_imgs(&g);
	load_map(&g);
	g.pg.end = 1;
	mlx_hook(g.win, 2, 1L << 0, key_pressed, &g);
	mlx_loop(g.mlx);
}
