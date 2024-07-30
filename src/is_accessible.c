/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_accessible.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:45:22 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/26 12:09:51 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	position_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == START)
			{
				game->start_pos.x = j;
				game->start_pos.y = i;
			}
			j++;
		}
		i++;
		game->map_size.x = j;
	}
	game->map_size.y = i;
}

static void	fill(t_game *game, t_point size, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (game->map_access[row][col] == WALL)
		return ;
	if (game->map_access[row][col] == EXIT)
		game->exit_access = 1;
	if (game->map_access[row][col] == COLLECT)
		game->collect_access++;
	game->map_access[row][col] = WALL;
	fill(game, size, row -1, col);
	fill(game, size, row +1, col);
	fill(game, size, row, col - 1);
	fill(game, size, row, col + 1);
}

void	is_accessible(t_game *game)
{
	int		i;

	i = 0;
	position_size(game);
	game->map_access = malloc(game->map_size.y * sizeof(char *));
	while (i < game->map_size.y)
	{
		game->map_access[i] = ft_strdup(game->map[i]);
		i++;
	}
	fill(game, game->map_size, game->start_pos.y, game->start_pos.x);
	free_map(game, game->map_access);
}
