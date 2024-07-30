/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 13:14:32 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 11:08:25 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	map_name(char *name)
{
	size_t	len;

	len = ft_strlen(name) - 1;
	if (name[len] == 'r' && name[len - 1] == 'e' && name[len - 2] == 'b'
		&& name[len - 3] == '.')
		return (1);
	ft_printf("Error\nWrong extension.\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc < 2)
		ft_printf("Error\nNo map specified.");
	else if (argc > 2)
		ft_printf("Error\nToo many arguments.");
	else if (argc == 2 && map_name(argv[1]))
	{
		game.path = ft_strjoin("./maps/", argv[1]);
		game.map = read_map(game.path);
		free(game.path);
		if (game.map == NULL)
			map_error_message("Map is empty or wrong map name", &game);
		if (check_map(&game))
		{
			(&game)->exit_access = 0;
			init_game(&game);
			init_hooks(&game);
			mlx_loop(game.mlx);
		}
	}
	exit_game(&game);
	return (0);
}
