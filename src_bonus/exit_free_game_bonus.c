/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_game_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:07:48 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 11:28:05 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	map_error_message(char *str, t_game *game)
{
	if (game->map)
		free_map(game, game->map);
	ft_printf("Error\n");
	ft_printf("%s\n", str);
	exit (1);
}

void	map_error(t_game *game)
{
	if (game->map)
		free_map(game, game->map);
	if (game->map_access)
		free_map(game, game->map_access);
	exit (1);
}

void	endgame(t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->moves);
	if (game->endgame == 1)
	{
		mlx_put_string(game->mlx,
			"Congratulation!", game->img_w / 3, game->img_h / 3 + 10);
		mlx_put_string(game->mlx, "You completed the game.",
			game->img_w / 4 + 30, game->img_h / 3 + 30);
	}
	if (game->endgame == 2)
	{
		mlx_put_string(game->mlx, "Oh no! Next time"
			" try to avoid the fire.", game->img_w / 4, game->img_h / 3 + 30);
	}
	mlx_put_string(game->mlx, "MOVES: ", game->img_w / 4,
		(game->img_h / 3) + 60);
	mlx_put_string(game->mlx, move_count,
		game->img_w / 3 + 25, game->img_h / 3 + 60);
	free(move_count);
}

void	free_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	while (i < game->map_size.y)
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

int	exit_game(t_game *game)
{
	free_map(game, game->map);
	mlx_delete_image(game->mlx, game->image.floor);
	mlx_delete_image(game->mlx, game->image.wall);
	mlx_delete_image(game->mlx, game->image.player);
	mlx_delete_image(game->mlx, game->image.play_d);
	mlx_delete_image(game->mlx, game->image.play_a);
	mlx_delete_image(game->mlx, game->image.collect);
	mlx_delete_image(game->mlx, game->image.exit);
	mlx_delete_image(game->mlx, game->image.exit2);
	mlx_delete_image(game->mlx, game->image.ennemi);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(0);
	return (0);
}
