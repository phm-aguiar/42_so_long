/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/09 17:08:13 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

void	initiate_variables_collectables(t_sl *sl)
{
	sl->recurses.player = 0;
	sl->recurses.exit = 0;
	sl->recurses.collectibles = 0;
	sl->recurses.wall = 0;
	sl->vars.index = 0;
	sl->vars.choice = 0;
	sl->vars.bytes_read = 0;
	sl->vars.pf_counter = 0;
	sl->vars.z = 0;
	sl->vars.hook = 0;
}

void	counter_wall(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map_file.map[i])
	{
		j = 0;
		while (sl->map_file.map[i][j])
		{
			if (sl->map_file.map[i][j] == '1')
				sl->recurses.wall++;
			j++;
		}
		i++;
	}
}

void	arg_cheker(char *path, t_sl *sl)
{
	while (path[sl->vars.index])
	{
		if (path[sl->vars.index] == '.' && path[sl->vars.index + 1] == 'b'
			&& path[sl->vars.index + 2] == 'e' && path[sl->vars.index
			+ 3] == 'r' && path[sl->vars.index + 4] == '\0')
		{
			sl->vars.index = 0;
			sl->vars.path = path;
			return ;
		}
		sl->vars.index++;
	}
	sl->vars.index = 0;
	ft_error("Invalid file extension", sl);
}
