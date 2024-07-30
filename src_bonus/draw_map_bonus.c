/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 14:42:30 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 12:20:58 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_draw(t_game *game, void *image, int x, int y)
{
	mlx_image_to_window(game->mlx, image, x * 64, y * 64);
}

static void	player_draw(t_game *game, void *image, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	img_draw(game, image, x, y);
}

static void	image(t_game *game, int x, int y)
{
	if (game->map[y][x] == WALL)
		img_draw(game, game->image.wall, x, y);
	else if (game->map[y][x] == FLOOR)
		img_draw(game, game->image.floor, x, y);
	else if (game->map[y][x] == START)
		player_draw(game, game->image.player, x, y);
	else if (game->map[y][x] == COLLECT)
		img_draw(game, game->image.collect, x, y);
	else if (game->map[y][x] == EXIT)
		img_draw(game, game->image.exit, x, y);
	else if (game->map[y][x] == ENNEMI)
		img_draw(game, game->image.ennemi, x, y);
}

int	draw_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			image(game, x, y);
			x++;
		}
		y++;
	}
	display_moves(game);
	return (0);
}
