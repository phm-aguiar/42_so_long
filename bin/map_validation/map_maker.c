/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/31 14:37:31 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_pathfinding(t_sl *sl);
// no implementation yet
// algorithm A*
void	check_edges_walls(t_sl *sl)
{
	sl->vars.j = 0;
	sl->vars.choice = -40;
	sl->vars.k = 0;
	while (sl->map_file.map[sl->vars.j])
	{
		while (sl->map_file.map[sl->vars.j][sl->vars.k])
		{
			if (sl->map_file.map[0][sl->vars.k] != '1')
				ft_error("Invalid map wall", sl);
			else if (sl->map_file.map[sl->vars.j][0] != '1' ||
						sl->map_file.map[sl->vars.j][sl->map_file.width
							- 1] != '1')
				ft_error("Invalid map wall", sl);
			else if (sl->map_file.map[sl->map_file.height
					- 1][sl->vars.k] != '1')
				ft_error("Invalid map wall", sl);
			sl->vars.k++;
		}
		sl->vars.j++;
	}
}
// no implementation yet
void	check_content(t_sl *sl)
{
	sl->vars.choice = -40;
	sl->vars.j = 0;
	sl->vars.k = 0;
	while (sl->map_file.map[sl->vars.j])
	{
		while (sl->map_file.map[sl->vars.j][sl->vars.k])
		{
			if (!ft_strchr(PERMITED_CHARS,
					sl->map_file.map[sl->vars.j][sl->vars.k]))
				ft_error("Invalid character in map", sl);
			if (sl->map_file.map[sl->vars.j][sl->vars.k] == 'P')
				sl->recurses.player++;
			if (sl->map_file.map[sl->vars.j][sl->vars.k] == 'E')
				sl->recurses.exit++;
			if (sl->map_file.map[sl->vars.j][sl->vars.k] == 'C')
				sl->recurses.collectibles++;
			sl->vars.k++;
		}
		sl->vars.k = 0;
		sl->vars.j++;
	}
	if (sl->recurses.player != 1 || sl->recurses.exit != 1
		|| sl->recurses.collectibles < 1)
		ft_error("Invalid recurses map", sl);
}
// no implementation yet

void	validate_map(t_sl *sl)
{
	check_if_matrix_is_rectangle(sl);
	check_content(sl);
	check_edges_walls(sl);
	// create_graph_from_map(sl->map_file.map, sl->map_file.height,
	// sl->map_file.width, sl);
	// check_pathfinding(sl);
}
// no implementation yet

void	map_maker(t_sl *sl)
{
	sl->vars.choice = -42;
	sl->vars.fd = open(sl->vars.path, O_RDONLY);
	if (sl->vars.fd == -1)
		ft_error("open: Invalid file", sl);
	sl->vars.bytes_read = read(sl->vars.fd, sl->map_file.buffer, 4079);
	if (sl->vars.bytes_read == -1)
		ft_error("read: Invalid file", sl);
	if (sl->vars.bytes_read == 4080)
		ft_error("File too big", sl);
	if (sl->vars.bytes_read == 0)
		ft_error("Empty file", sl);
	sl->map_file.buffer[sl->vars.bytes_read] = '\0';
	close(sl->vars.fd);
	sl->vars.choice = -41;
	sl->map_file.map = ft_split(sl->map_file.buffer, '\n');
	sl->map_file.fld_map = ft_split(sl->map_file.buffer, '\n');
	if (!sl->map_file.map)
		ft_error("failed to allocate memory", sl);
	sl->map_file.width = ft_strlen(sl->map_file.map[0]);
	sl->map_file.height = ft_matrixlen(sl->map_file.map);
	validate_map(sl);
}
