/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:51:16 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/29 14:32:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	create_graph_from_map(char **map, int height, int width, t_sl *sl)
{
	sl->vars.i = 0;
	while (sl->vars.i < height)
	{
		sl->vars.j = 0;
		while (sl->vars.j < width)
		{
			sl->vars.node = &sl->graph[sl->vars.i][sl->vars.j];
			sl->vars.node->value = map[sl->vars.i][sl->vars.j];
			sl->vars.node->x = sl->vars.i;
			sl->vars.node->y = sl->vars.j;
			sl->vars.node->f = 0;
			sl->vars.node->g = WALL;
			sl->vars.node->h = 0;
			sl->vars.node->parent = NULL;
			sl->vars.k = 0;
			while (sl->vars.k < 4)
			{
				sl->vars.node->neighbors[sl->vars.k] = NULL;
				sl->vars.k++;
			}
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

// int	main(void)
// {
// 	int	height;
// 	int	width;

// 	char map[4][7] = {"1111111", "1C0C0E1", "1P0CC01", "1111111"};
// 	height = 4;
// 	width = 7;
// 	createGraphFromMap(map, height, width);
// 	return (0);
// }
