/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:26 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/06 12:07:35 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

void	check_if_matrix_is_rectangle(t_sl *sl)
{
	int	area;

	sl->vars.j = 0;
	sl->vars.k = 0;
	sl->vars.index = 0;
	area = sl->map_file.height * sl->map_file.width;
	while (sl->map_file.map[sl->vars.j])
	{
		while (sl->map_file.map[sl->vars.j][sl->vars.k])
		{
			sl->vars.k++;
			sl->vars.index++;
		}
		sl->vars.k = 0;
		sl->vars.j++;
	}
	sl->vars.choice = -40;
	if (sl->vars.index != area || area < 15)
		ft_error("Map is not a valide rectangle", sl);
}

void	verify_path_ok(t_sl *sl, char **map)
{
	sl->vars.choice = -40;
	sl->vars.i = 0;
	while (map[sl->vars.i])
	{
		sl->vars.j = 0;
		while (map[sl->vars.i][sl->vars.j])
		{
			if (map[sl->vars.i][sl->vars.j] == 'E'
				|| map[sl->vars.i][sl->vars.j] == 'C')
				ft_error("Invalid path", sl);
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

void	full_floodfill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == '-')
		return ;
	if (map[y][x] == 'E')
	{
		map[y][x] = '-';
		return ;
	}
	map[y][x] = '-';
	full_floodfill(map, y - 1, x);
	full_floodfill(map, y + 1, x);
	full_floodfill(map, y, x - 1);
	full_floodfill(map, y, x + 1);
}

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
				find_player(sl, sl->vars.j, sl->vars.k);
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
