/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/27 16:49:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	validate_map(t_sl *sl);

void	map_maker(t_sl *sl)
{
	sl->commom_variables.choice = -42;
	sl->commom_variables.fd = open(sl->commom_variables.path, O_RDONLY);
	if (sl->commom_variables.fd == -1)
		ft_error("Invalid file", sl);
	sl->commom_variables.bytes_read = read(sl->commom_variables.fd,
											sl->map_file.buffer,
											4079);
	if (sl->commom_variables.bytes_read == -1)
		ft_error("Invalid file", sl);
	if (sl->commom_variables.bytes_read == 4080)
		ft_error("File too big", sl);
	if (sl->commom_variables.bytes_read == 0)
		ft_error("Empty file", sl);
	sl->map_file.buffer[sl->commom_variables.bytes_read] = '\0';
	close(sl->commom_variables.fd);
	sl->commom_variables.choice = -41;
	sl->map_file.map = ft_split(sl->map_file.buffer, '\n');
	sl->map_file.fld_map = ft_split(sl->map_file.buffer, '\n');
	if (!sl->map_file.map)
		ft_error("failed to allocate memory", sl);
	sl->dimentions.x = ft_strlen(sl->map_file.map[0]);
	sl->dimentions.y = ft_matrixlen(sl->map_file.map);
	validate_map(sl); // no implementation yet
}
