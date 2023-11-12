/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:26 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/12 18:10:22 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_and_defines_so_long.h"

void	check_if_matrix_is_rectangle(t_sl *sl)
{
	int	area;
	int	index;
	int	i;
	int	j;

	area = sl->map_file.height * sl->map_file.width;
	index = 0;
	i = 0;
	while (sl->map_file.map[i])
	{
		j = 0;
		while (sl->map_file.map[i][j])
		{
			index++;
			j++;
		}
		i++;
	}
	if (index != area || area < 15 || sl->map_file.height * 64 > 1080
		|| sl->map_file.width * 64 >= 1920)
		ft_error("Map is not a valid rectangle", sl, 42);
}

void	verify_path(t_sl *sl, char **map)
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
				ft_error("Invalid path floodfill", sl, 42);
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

void	full_floodfill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == '-' || map[y][x] == 'I')
		return ;
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
	while (sl->map_file.map[sl->vars.j])
	{
		sl->vars.k = 0;
		while (sl->map_file.map[sl->vars.j][sl->vars.k])
		{
			if (sl->map_file.map[0][sl->vars.k] != '1')
				ft_error("Invalid map wall", sl, 42);
			else if (sl->map_file.map[sl->vars.j][0] != '1' ||
						sl->map_file.map[sl->vars.j][sl->map_file.width
							- 1] != '1')
				ft_error("Invalid map wall", sl, 42);
			else if (sl->map_file.map[sl->map_file.height
					- 1][sl->vars.k] != '1')
				ft_error("Invalid map wall", sl, 42);
			sl->vars.k++;
		}
		sl->vars.j++;
	}
}

void	check_content(t_sl *sl, char current_char, char **map)
{
	sl->vars.choice = -40;
	sl->vars.j = 0;
	while (map[sl->vars.j])
	{
		sl->vars.k = 0;
		while (map[sl->vars.j][sl->vars.k])
		{
			current_char = map[sl->vars.j][sl->vars.k];
			if (!ft_strchr(PERMITED_CHARS, current_char))
				ft_error("Invalid character in map", sl, 42);
			else if (current_char == 'P')
				find_player(sl, sl->vars.j, sl->vars.k, 1);
			else if (current_char == 'E')
				find_player(sl, sl->vars.j, sl->vars.k, 2);
			else if (current_char == 'C')
				sl->recurses.collectibles++;
			else if (current_char == 'I')
				sl->recurses.entity++;
			sl->vars.k++;
		}
		sl->vars.j++;
	}
	if (sl->recurses.player != 1 || sl->recurses.exit != 1
		|| sl->recurses.collectibles < 1)
		ft_error("Invalid recurses map", sl, 42);
}
