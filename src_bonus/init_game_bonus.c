/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:50:23 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 13:23:18 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_textures(t_game *game)
{
	game->texture.floor = mlx_load_png("images/0.png");
	game->texture.wall = mlx_load_png("images/1.png");
	game->texture.play_d = mlx_load_png("images/PD.png");
	game->texture.play_a = mlx_load_png("images/PA.png");
	game->texture.collect = mlx_load_png("images/C.png");
	game->texture.exit = mlx_load_png("images/E1.png");
	game->texture.exit2 = mlx_load_png("images/E2.png");
	game->texture.en1 = mlx_load_png("images/EN.png");
	game->texture.en2 = mlx_load_png("images/EN2.png");
	game->texture.en3 = mlx_load_png("images/EN3.png");
}

static void	get_images(t_game *game)
{
	game->image.floor = mlx_texture_to_image(game->mlx, game->texture.floor);
	game->image.wall = mlx_texture_to_image(game->mlx, game->texture.wall);
	game->image.collect = mlx_texture_to_image(game->mlx,
			game->texture.collect);
	game->image.player = mlx_texture_to_image(game->mlx, game->texture.play_d);
	game->image.play_d = mlx_texture_to_image(game->mlx, game->texture.play_d);
	game->image.play_a = mlx_texture_to_image(game->mlx, game->texture.play_a);
	game->image.exit = mlx_texture_to_image(game->mlx, game->texture.exit);
	game->image.exit2 = mlx_texture_to_image(game->mlx, game->texture.exit2);
	game->image.ennemi = mlx_texture_to_image(game->mlx, game->texture.en1);
	game->image.en1 = mlx_texture_to_image(game->mlx, game->texture.en1);
	game->image.en2 = mlx_texture_to_image(game->mlx, game->texture.en2);
	game->image.en3 = mlx_texture_to_image(game->mlx, game->texture.en3);
	mlx_delete_texture(game->texture.floor);
	mlx_delete_texture(game->texture.wall);
	mlx_delete_texture(game->texture.collect);
	mlx_delete_texture(game->texture.play_d);
	mlx_delete_texture(game->texture.play_a);
	mlx_delete_texture(game->texture.exit);
	mlx_delete_texture(game->texture.exit2);
	mlx_delete_texture(game->texture.en1);
	mlx_delete_texture(game->texture.en2);
	mlx_delete_texture(game->texture.en3);
}

static void	size_window_init(t_game *game)
{
	int	i;

	game->img_w = ft_strlen(game->map[0]) * 64;
	i = 0;
	while (game->map[i])
		i++;
	game->img_h = i * 64;
}

void	init_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	size_window_init(game);
	game->mlx = mlx_init(game->img_w, game->img_h, "so_long", false);
	game->moves = 0;
	game->endgame = 0;
	game->pos_enemies = 1;
	get_textures(game);
	get_images(game);
	if (game->map_size.x > 4 && game->map_size.y > 4)
	{
		if (game->map_size.x > game->map_size.y)
			i = random_between(1, (game->map_size.x / 2));
		else
			i = random_between(1, (game->map_size.y / 2));
		while (j <= i)
		{
			put_ennemies(game);
			j++;
		}
	}
	draw_map(game);
}
