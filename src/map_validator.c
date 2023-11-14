/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:26 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/14 15:38:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		ft_error("Map is not a valid rectangle\n", sl, 42);
}

void	verify_path(t_sl *sl, char **map)
{
	sl->vars.i = 0;
	while (map[sl->vars.i])
	{
		sl->vars.j = 0;
		while (map[sl->vars.i][sl->vars.j])
		{
			if (map[sl->vars.i][sl->vars.j] == 'E'
				|| map[sl->vars.i][sl->vars.j] == 'C')
			{
				ft_matrixdel(sl->map_file.mapcpy);
				ft_error("Invalid path floodfill\n", sl, 42);
			}
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
	while (sl->map_file.map[sl->vars.j])
	{
		sl->vars.k = 0;
		while (sl->map_file.map[sl->vars.j][sl->vars.k])
		{
			if (sl->map_file.map[0][sl->vars.k] != '1')
				ft_error("Invalid map wall\n", sl, 42);
			else if (sl->map_file.map[sl->vars.j][0] != '1' ||
						sl->map_file.map[sl->vars.j][sl->map_file.width
							- 1] != '1')
				ft_error("Invalid map wall\n", sl, 42);
			else if (sl->map_file.map[sl->map_file.height
					- 1][sl->vars.k] != '1')
				ft_error("Invalid map wall\n", sl, 42);
			sl->vars.k++;
		}
		sl->vars.j++;
	}
}

void	check_content(t_sl *sl, char current_char, char **map)
{
	sl->vars.j = 0;
	while (map[sl->vars.j])
	{
		sl->vars.k = 0;
		while (map[sl->vars.j][sl->vars.k])
		{
			current_char = map[sl->vars.j][sl->vars.k];
			if (!ft_strchr(PERMITED_CHARS, current_char))
				ft_error("Invalid character in map\n", sl, 42);
			else if (current_char == 'P')
				set_xy(sl, sl->vars.j, sl->vars.k, 1);
			else if (current_char == 'E')
				set_xy(sl, sl->vars.j, sl->vars.k, 2);
			sl->vars.k++;
		}
		sl->vars.j++;
	}
	if (sl->recurses.player != 1 || sl->recurses.door != 1
		|| sl->recurses.collectibles < 1)
		ft_error("Invalid recurses map\n", sl, 42);
}
