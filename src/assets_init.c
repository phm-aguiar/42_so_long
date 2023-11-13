/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:39:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/13 20:16:32 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes_and_defines_so_long.h"

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
	path[2] = "assets/floor.png";
	path[3] = "assets/exit.png";
	path[4] = "assets/enimy.png";
	path[5] = "assets/collectable.png";
}

void	all_image(t_sl *set)
{
	int		i;
	char	*path[6];
	int		k;

	load_path(path);
	i = 0;
	while (i < 5)
	{
		set->image[i] = image_load(set->mlx, path[i]);
		i++;
	}
	k = set->recurses.collectibles;
	k += i;
	while (i < k)
		set->image[i++] = image_load(set->mlx, path[5]);
	set->total_images = i;
}
