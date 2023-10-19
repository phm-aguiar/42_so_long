/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ONCOMING.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 11:24:20 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/19 18:04:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	iniciate_struct(len_line)
{
	t_map	map;

	map.dimentions.len_map_x = len_line - 1;
	map.dimentions.len_map_y = 0;
	map.recurses.player = 0;
	map.recurses.collectibles = 0;
	map.recurses.exit = 0;
	map.recurses.wall = 0;
}

bool	validate_dimentions(char *line, int len_line)
{
	if (ft_strlen(line) == len_line)
		return (true);
	else
		return (false);
}

bool	validate_recurses_map(char *line)
{
	int		i;
	t_map	map;

	i = 0;
	while (line[i])
	{
		if (line[i] == 'P')
			map.recurses.player++;
		if (line[i] == 'C')
			map.recurses.collectibles++;
		if (line[i] == 'E')
			map.recurses.exit++;
		if (line[i] == '1')
			map.recurses.wall++;
		i++;
	}
	if (map.recurses.player != 1 || map.recurses.collectibles < 1
		|| map.recurses.exit != 1 || map.recurses.wall < 1)
		return (false);
	else
		return (true);
}

bool	validate_line(char *msg, int len_line)
{
	int	index;

	index = 0;
	while (index < len_line)
	{
		if (ft_strchr(PERMITED_CHARS, msg[index]) == NULL)
			return (false);
		index++;
	}
	return (true);
}

bool	validate_map(char *line, int len_line)
{
	t_map	map;

	if (!validate_line(line, len_line))
		return (false);
	if (!validate_dimentions(line, len_line))
		return (false);
	if (!validate_recurses_map(line))
		return (false);
	map.dimentions.len_map_y++;
	return (true);
}

bool	tratament_file(char *map_join, int size_line)
{
	int		i;
	t_map	map;

	i = 0;
	iniciate_struct(size_line);
	map.map_file.map = ft_split(map_join, '\n');
	while (map.map_file.map[i])
	{
		if (!validate_map(map.map_file.map[i], size_line))
			return (false);
		i++;
	}
	return (true);
}

int	map_validation(char *argv)
{
	char	*line;
	char	*map;
	int		fd;
	int		size_line;

	map = "";
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	line = get_next_line(fd);
	if (!(line))
		return (0);
	size_line = ft_strlen(line) - 1;
	if (size_line < 3)
		return (0);
	while (line)
	{
		map = ft_strjoin(map, line);
		free(line);
		line = get_next_line(fd);
	}
	
}
