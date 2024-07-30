/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_hooks_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:48:14 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/26 13:14:43 by jmouette         ###   ########.fr       */
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
		}
		else if (keydata.key == MLX_KEY_ESCAPE)
			exit_game(game);
	}
	if (game->endgame != 0)
		endgame(game);
}

void	init_hooks(t_game *game)
{
	mlx_key_hook(game->mlx, &game_events, game);
}
