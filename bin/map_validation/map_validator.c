/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:26 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/27 16:33:06 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_if_matrix_is_rectangle(t_sl *sl)
{
	int	area;

	sl->commom_variables.j = 0;
	sl->commom_variables.k = 0;
	sl->commom_variables.index = 0;
	area = sl->dimentions.x * sl->dimentions.y;
	while (sl->map_file.map[sl->commom_variables.j])
	{
		while (sl->map_file.map[sl->commom_variables.j][sl->commom_variables.k])
		{
			sl->commom_variables.k++;
			sl->commom_variables.index++;
		}
		sl->commom_variables.k = 0;
		sl->commom_variables.j++;
	}
	sl->commom_variables.choice = 0;
	if (sl->commom_variables.index != area)
		ft_error("Map is not a rectangle", sl);
}
