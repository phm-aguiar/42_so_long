/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/03 10:50:30 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	sl->map_file.mapcpy = ft_split(sl->map_file.buffer, '\n');
	if (!sl->map_file.map)
		ft_error("failed to allocate memory", sl);
	sl->map_file.width = ft_strlen(sl->map_file.map[0]);
	sl->map_file.height = ft_matrixlen(sl->map_file.map);
	validate_map(sl);
}
