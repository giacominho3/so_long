/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifulvi <gifulvi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 18:15:43 by gifulvi           #+#    #+#             */
/*   Updated: 2022/05/19 18:09:55 by gifulvi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pg
{
	int	x;
	int	y;
	int	moves;
	int	coins;
	int	end;
}		t_pg;

typedef struct s_map
{
	char	**map;
	int		r;
	int		c;
}		t_map;

typedef struct s_img
{
	void	*wall;
	void	*floor;
	void	*exit;
	void	*pg;
	void	*coll;
	void	*enemy;
	void	*go;
	void	*win;
	void	*left;
	void	*right;
}			t_img;

typedef struct s_game
{
	t_map	map;
	t_img	img;
	t_pg	pg;
	void	*mlx;
	void	*win;
}			t_game;

typedef enum e_keys
{
	ESC = 53,
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
	ENTER_1 = 36,
	ENTER_2 = 76,
}	t_keys;

int		main(int argc, char **argv);
void	get_rows(t_map *map, char *file);
void	get_columns(t_map *map, char *file);
void	get_player(t_game *g, t_map *map);
int		ft_check_map_name(char *filename);
void	ft_get_map(char *path, t_game *g);
int		key_pressed(int key, t_game *g);
void	load_map(t_game *g);
void	load_imgs(t_game *g);
void	set_image_stat(t_game *g, char mat_elem, int i, int j);
void	set_image_dyn(t_game *g, char mat_elem, int i, int j);
char	*get_next_line(int fd);
void	helper(char *new_a, int i);
int		lenght(int nb, int base);
char	*ft_itoa(int nb);
void	read_all_file(int fd, t_game *g);
void	get_coins(t_game *g, t_map *map);
void	move_right(t_game *g);
void	move_left(t_game *g);
void	move_up(t_game *g);
void	move_down(t_game *g);
void	move_counter(t_game *g);
void	do_move_x(t_game *g, int mod);
void	do_move_y(t_game *g, int mod);
void	ft_putstr(char *str);
int		check_features(char **map, int r, int c, int i);
int		are_ok(int pc, int cc, int ec);
void	end_game(t_game *g, int status);
void	pacman_effect(t_game *g);
int		waiter(void);

#endif
