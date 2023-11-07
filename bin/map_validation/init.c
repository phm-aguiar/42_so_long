/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/07 18:09:47 by phenriq2         ###   ########.fr       */
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
	sl->vars.hook = 0;
	sl->mlx = NULL;
}

void	arg_cheker(char *path, t_sl *sl)
{
	while (path[sl->vars.index])
	{
		if (path[sl->vars.index] == '.'
			&& path[sl->vars.index + 1] == 'b'
			&& path[sl->vars.index + 2] == 'e'
			&& path[sl->vars.index + 3] == 'r'
			&& path[sl->vars.index + 4] == '\0')
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
