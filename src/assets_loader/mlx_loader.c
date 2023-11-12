/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:17:57 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/12 12:18:07 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

void	ft_image(void *mlx, mlx_image_t *img, int x, int y)
{
	mlx_image_to_window(mlx, img, x * 64, y * 64);
}

void	floor_all(t_sl *sl, mlx_image_t *img)
{
	sl->vars.i = 0;
	while (sl->map_file.map[sl->vars.i])
	{
		sl->vars.j = 0;
		while (sl->map_file.map[sl->vars.i][sl->vars.j])
		{
			ft_image(sl->mlx, img, sl->vars.j, sl->vars.i);
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

void	collectable_creator(t_sl *sl)
{
	int	i;

	i = 4;
	sl->vars.i = 0;
	while (sl->map_file.map[sl->vars.i])
	{
		sl->vars.j = 0;
		while (sl->map_file.map[sl->vars.i][sl->vars.j])
		{
			if (sl->map_file.map[sl->vars.i][sl->vars.j] == 'C')
			{
				ft_image(sl->mlx, sl->image[i].image, sl->vars.j, sl->vars.i);
				i++;
			}
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

void	map_creator(t_sl *sl)
{
	floor_all(sl, sl->image[2].image);
	collectable_creator(sl);
	sl->vars.i = 0;
	while (sl->map_file.map[sl->vars.i])
	{
		sl->vars.j = 0;
		while (sl->map_file.map[sl->vars.i][sl->vars.j])
		{
			if (sl->map_file.map[sl->vars.i][sl->vars.j] == '1')
				ft_image(sl->mlx, sl->image[1].image, sl->vars.j, sl->vars.i);
			if (sl->map_file.map[sl->vars.i][sl->vars.j] == 'E')
				ft_image(sl->mlx, sl->image[3].image, sl->vars.j, sl->vars.i);
			if (sl->map_file.map[sl->vars.i][sl->vars.j] == 'P')
				ft_image(sl->mlx, sl->image[0].image, sl->vars.j, sl->vars.i);
			if (sl->map_file.map[sl->vars.i][sl->vars.j] == 'I')
				ft_image(sl->mlx, sl->entity.image, sl->vars.j, sl->vars.i);
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}
