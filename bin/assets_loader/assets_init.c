/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:39:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/08 19:10:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

t_image	image_load(void *mlx, char *path)
{
	t_image	img;

	img.texture = mlx_load_png(path);
	img.image = mlx_texture_to_image(mlx, img.texture);
	return (img);
}

void	load_path(char **path)
{
	path[0] = "assets/player.png";
	path[1] = "assets/wall.png";
	path[2] = "assets/collectable.png";
	path[3] = "assets/floor.png";
	path[4] = "assets/exit.png";
}

void	all_image(t_sl *set)
{
	int i;
	char *path[5];

	load_path(path);
	i = -1;
	while (++i < 5)
		set->image[i] = image_load(set->mlx, path[i]);
}
