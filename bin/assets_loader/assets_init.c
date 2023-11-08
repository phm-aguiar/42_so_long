/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:39:34 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/08 18:40:11 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

typedef struct s_image{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}t_image;

typedef struct s_object{
	int x;
	int y;
	bool visible;
 char *name;
	t_image	*img;
}t_object;

t_image image_load(void *mlx, char *path)
{
	t_image img;

	img.texture = mlx_load_png(path);
	img.image = mlx_texture_to_image(mlx, img.texture);
	return (img);
}

void load_path(char *path)
{
	path[0] = "first";
	path[1] = "second";
	path[2] = "third";
	path[3] = "fourth";
	path[4] = "fiveth";
}

void all_image(t_sl *set)
{
	int i;
	char path[5];

	load_path(path);
	i = -1;
	while (++i < 5)
		set->image[i] = image_load(set->mlx, path[i]);

	set->object[0].img = set->image[1];
}