/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:07:48 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 12:05:54 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error_message(char *str, t_game *game)
{
	if (game->map)
		free_map(game, game->map);
	if (game->map_access)
		free_map(game, game->map_access);
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
	ft_printf("\n\nCONGRATULATIONS!!!");
	ft_printf("You completed the game in %d moves!\n", game->moves);
	exit_game(game);
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
	mlx_delete_image(game->mlx, game->image.collect);
	mlx_delete_image(game->mlx, game->image.exit);
	mlx_delete_image(game->mlx, game->image.exit2);
	mlx_close_window(game->mlx);
	mlx_terminate(game->mlx);
	exit(0);
	return (0);
}
