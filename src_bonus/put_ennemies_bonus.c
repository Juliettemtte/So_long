/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ennemies_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:47:59 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/25 13:30:40 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	random_between(int min, int max)
{
	int	random;

	random = min + rand() % (max - min + 1);
	return (random);
}

void	put_ennemies(t_game *game)
{
	int	rand_x;
	int	rand_y;
	int	attempts;
	int	max;

	game->exit_access = 0;
	attempts = 0;
	max = 300;
	rand_x = random_between(1, game->map_size.x - 1);
	rand_y = random_between(1, game->map_size.y - 1);
	while (game->map[rand_y][rand_x] != FLOOR
		|| is_accessible(game, rand_y, rand_x) == 0)
	{
		game->exit_access = 1;
		rand_x = random_between(1, game->map_size.x - 1);
		rand_y = random_between(1, game->map_size.y - 1);
		if (attempts >= max)
			return ;
		attempts++;
	}
	game->map[rand_y][rand_x] = ENNEMI;
}
