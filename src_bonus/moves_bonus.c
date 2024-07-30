/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 15:51:33 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/26 13:01:46 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_moves(t_game *game)
{
	char	*move_count;

	move_count = ft_itoa(game->moves);
	mlx_put_string(game->mlx, "MOVES: ", 25, 20);
	mlx_put_string(game->mlx, move_count, 90, 20);
	free(move_count);
}
