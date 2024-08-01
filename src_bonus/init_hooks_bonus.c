/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:48:14 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 13:25:23 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	game_events(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_RELEASE)
	{
		if (game->endgame == 0)
		{
			if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
				press_w(game);
			else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
				press_s(game);
			else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
				press_d(game);
			else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
				press_a(game);
			else if (keydata.key == MLX_KEY_ESCAPE)
				exit_game(game);
		}
		else if (keydata.key == MLX_KEY_ESCAPE)
			exit_game(game);
	}
	if (game->endgame != 0)
		endgame(game);
}

static void	animation(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (game->loop < 10)
	{
		game->loop++;
		return ;
	}
	game->loop = 0;
	if (game->pos_enemies == 1)
		game->image.ennemi = game->image.en1;
	else if (game->pos_enemies == 2)
		game->image.ennemi = game->image.en2;
	else if (game->pos_enemies == 3)
	{
		game->image.ennemi = game->image.en3;
		game->pos_enemies = 0;
	}
	draw_map(game);
	game->pos_enemies++;
}

void	init_hooks(t_game *game)
{
	mlx_loop_hook(game->mlx, &animation, game);
	mlx_key_hook(game->mlx, &game_events, game);
}
