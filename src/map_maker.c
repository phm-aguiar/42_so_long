/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/12 18:10:15 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_and_defines_so_long.h"

void	validate_map(t_sl *sl)
{
	check_if_matrix_is_rectangle(sl);
	check_content(sl, '\0', sl->map_file.map);
	check_edges_walls(sl);
	sl->map_file.mapcpy = ft_split(sl->map_file.buffer, '\n');
	if (!sl->map_file.mapcpy)
		ft_error("failed to allocate memory", sl, 42);
	full_floodfill(sl->map_file.mapcpy, sl->vars.start_y, sl->vars.start_x);
	verify_path(sl, sl->map_file.mapcpy);
	ft_matrixdel(sl->map_file.mapcpy);
}

void	find_player(t_sl *sl, int y, int x, int choise)
{
	if (choise == 1)
	{
		sl->recurses.player++;
		sl->vars.start_y = y;
		sl->vars.start_x = x;
	}
	if (choise == 2)
	{
		sl->recurses.exit++;
		sl->vars.end_y = y;
		sl->vars.end_x = x;
	}
}

void	ft_error(char *str, t_sl *sl, int choise)
{
	miniprintf("%s", str);
	if (choise == 0)
	{
		close(sl->vars.fd);
		perror("");
	}
	if (!sl->map_file.map)
		ft_matrixdel(sl->map_file.map);
	exit(EXIT_FAILURE);
}

void	map_maker(t_sl *sl)
{
	sl->vars.choice = -42;
	sl->vars.fd = open(sl->vars.path, O_RDONLY);
	if (sl->vars.fd == -1)
		ft_error("open: Invalid file", sl, 0);
	sl->vars.bytes_read = read(sl->vars.fd, sl->map_file.buffer, 4079);
	if (sl->vars.bytes_read == -1)
		ft_error("read: Invalid file", sl, 0);
	if (sl->vars.bytes_read == 4080)
		ft_error("File too big", sl, 0);
	if (sl->vars.bytes_read == 0)
		ft_error("Empty file", sl, 0);
	sl->map_file.buffer[sl->vars.bytes_read] = '\0';
	close(sl->vars.fd);
	sl->map_file.map = ft_split(sl->map_file.buffer, '\n');
	if (!sl->map_file.map)
		ft_error("failed to allocate memory", sl, 42);
	sl->map_file.width = ft_strlen(sl->map_file.map[0]);
	sl->map_file.height = ft_matrixlen(sl->map_file.map);
	validate_map(sl);
}
