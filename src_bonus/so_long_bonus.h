/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:15:08 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 11:04:47 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# define ENNEMI 'K'

# define KEY_ESC 65307
# define KEY_Q 113

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_image
{
	void	*floor;
	void	*wall;
	void	*player;
	void	*play_d;
	void	*play_a;
	void	*collect;
	void	*exit;
	void	*exit2;
	void	*ennemi;
	void	*moves;
	void	*end;
	void	*end2;
}	t_image;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	**map_access;
	char	*path;
	int		img_w;
	int		img_h;
	int		n_collect;
	int		n_player;
	int		n_exit;
	int		moves;
	int		endgame;
	int		exit_access;
	int		collect_access;
	int		pos_enemies;
	int		loop;
	t_image	texture;
	t_image	image;
	t_point	player;
	t_point	start_pos;
	t_point	map_size;
}	t_game;

/*********** check_map ************/
int		check_map(t_game *game);
int		is_accessible(t_game *game, int x, int y);

/*********** read_map *************/
char	**read_map(char *path);

/********* put_ennemies ***********/
int		random_between(int min, int max);
void	put_ennemies(t_game *game);

/*********** init_game ************/
void	init_game(t_game *game);

/*********** init_hooks ***********/
void	init_hooks(t_game *game);

/*********** draw_map *************/
void	img_draw(t_game *game, void *image, int x, int y);
int		draw_map(t_game *game);

/************* moves **************/
void	display_moves(t_game *game);

/************* player *************/
void	press_w(t_game *game);
void	press_s(t_game *game);
void	press_d(t_game *game);
void	press_a(t_game *game);

/*********** exit_free ***********/
void	map_error_message(char *str, t_game *game);
void	map_error(t_game *game);
void	endgame(t_game *game);
void	free_map(t_game *game, char **map);
int		exit_game(t_game *game);

#endif