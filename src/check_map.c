/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:05:24 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 11:21:21 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_retangular(char **map)
{
	int	i;

	i = 1;
	if (!map)
		return (0);
	while (map[i])
	{
		if (ft_strlen(map[i]) != ft_strlen(map[0]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_wall(char **map)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	i = 0;
	while (map[i])
		i++;
	while (map[0][j] != '\0' && map[i - 1][j] != '\0')
	{
		if (map[0][j] != WALL || map[i - 1][j] != WALL)
			return (0);
		j++;
	}
	i = 1;
	len = ft_strlen(map[i]);
	while (map[i])
	{
		if (map[i][0] != WALL || map[i][len - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}

static int	is_component(t_game *game)
{
	int	i;
	int	j;

	game->n_collect = 0;
	game->n_player = 0;
	game->n_exit = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] != '\0')
		{
			if (game->map[i][j] == START)
				game->n_player++;
			else if (game->map[i][j] == EXIT)
				game->n_exit++;
			else if (game->map[i][j] == COLLECT)
				game->n_collect++;
			j++;
		}
		i++;
	}
	if (game->n_player != 1 || game->n_exit != 1 || game->n_collect == 0)
		return (0);
	return (1);
}

static int	is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != START && map[i][j] != EXIT && map[i][j] != COLLECT
				&& map[i][j] != FLOOR && map[i][j] != WALL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_map(t_game *game)
{
	game->exit_access = 0;
	game->collect_access = 0;
	if (!is_retangular(game->map))
		map_error_message("Map not rectangular.", game);
	if (!is_wall(game->map))
		map_error_message("Map not surrounded by walls", game);
	if (!is_component(game))
	{
		ft_printf("Error\n");
		if (game->n_player != 1)
			ft_printf("Less or more than 1 starting position.\n");
		if (game->n_exit != 1)
			ft_printf("Less or more than 1 exit.\n");
		if (game->n_collect == 0)
			ft_printf("No collectible.\n");
		map_error(game);
	}
	if (!is_valid(game->map))
		map_error_message("Map invalid.", game);
	is_accessible(game);
	if (game->exit_access != 1)
		map_error_message("Exit inaccessible.", game);
	if (game->collect_access != game->n_collect)
		map_error_message("At least 1 collectible inaccessible.", game);
	return (1);
}
