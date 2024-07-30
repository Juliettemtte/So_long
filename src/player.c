/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:07:36 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 12:05:34 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw(t_game *game, int y, int x)
{
	if (game->n_collect == 0)
		game->image.exit = game->image.exit2;
	game->map[y][x] = FLOOR;
	game->moves++;
	draw_map(game);
}

void	press_w(t_game *game)
{
	game->player.y -= 1;
	if (game->map[game->player.y][game->player.x] == EXIT
			&& game->n_collect == 0)
	{
		game->endgame = 1;
		draw(game, game->player.y + 1, game->player.x);
	}
	else if (game->map[game->player.y][game->player.x] == WALL
			|| game->map[game->player.y][game->player.x] == EXIT)
		game->player.y += 1;
	else
	{
		if (game->map[game->player.y][game->player.x] == COLLECT)
			game->n_collect -= 1;
		game->map[game->player.y][game->player.x] = START;
		draw(game, game->player.y + 1, game->player.x);
	}
}

void	press_s(t_game *game)
{
	game->player.y += 1;
	if (game->map[game->player.y][game->player.x] == EXIT
			&& game->n_collect == 0)
	{
		game->endgame = 1;
		draw(game, game->player.y - 1, game->player.x);
	}
	else if (game->map[game->player.y][game->player.x] == WALL
			|| game->map[game->player.y][game->player.x] == EXIT)
		game->player.y -= 1;
	else
	{
		if (game->map[game->player.y][game->player.x] == COLLECT)
			game->n_collect -= 1;
		game->map[game->player.y][game->player.x] = START;
		draw(game, game->player.y - 1, game->player.x);
	}
}

void	press_d(t_game *game)
{
	game->player.x += 1;
	if (game->map[game->player.y][game->player.x] == EXIT
			&& game->n_collect == 0)
	{
		game->endgame = 1;
		draw(game, game->player.y, game->player.x - 1);
	}
	else if (game->map[game->player.y][game->player.x] == WALL
			|| game->map[game->player.y][game->player.x] == EXIT)
		game->player.x -= 1;
	else
	{
		if (game->map[game->player.y][game->player.x] == COLLECT)
			game->n_collect -= 1;
		game->map[game->player.y][game->player.x] = START;
		draw(game, game->player.y, game->player.x - 1);
	}
}

void	press_a(t_game *game)
{
	game->player.x -= 1;
	if (game->map[game->player.y][game->player.x] == EXIT
			&& game->n_collect == 0)
	{
		game->endgame = 1;
		draw(game, game->player.y, game->player.x + 1);
	}
	else if (game->map[game->player.y][game->player.x] == WALL
			|| game->map[game->player.y][game->player.x] == EXIT)
		game->player.x += 1;
	else
	{
		if (game->map[game->player.y][game->player.x] == COLLECT)
			game->n_collect -= 1;
		game->map[game->player.y][game->player.x] = START;
		draw(game, game->player.y, game->player.x + 1);
	}
}
