/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmouette <jmouette@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 11:17:20 by jmouette          #+#    #+#             */
/*   Updated: 2024/07/30 10:23:07 by jmouette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*read_file_content(int fd)
{
	char	*file_content;
	char	*line;
	char	*tmp_content;

	file_content = ft_strdup("");
	line = get_next_line(fd);
	while (line != NULL)
	{
		tmp_content = file_content;
		file_content = ft_strjoin(tmp_content, line);
		free(line);
		free(tmp_content);
		line = get_next_line(fd);
	}
	return (file_content);
}

char	**read_map(char *path)
{
	int		fd;
	char	*file_content;
	char	**map;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = read_file_content(fd);
	close(fd);
	if (ft_strlen(file_content) == 0)
	{
		free(file_content);
		return (NULL);
	}
	map = ft_split(file_content, '\n');
	free(file_content);
	return (map);
}
