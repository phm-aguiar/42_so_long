/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:26 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/29 14:32:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

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
	sl->vars.choice = 0;
	if (sl->vars.index != area)
		ft_error("Map is not a rectangle", sl);
}
