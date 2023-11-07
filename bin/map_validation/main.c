/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/07 19:22:15 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_sl	*sl;

	sl = (t_sl *)param;
	if ((keydata.key == ESC || keydata.key == Q) && (keydata.action == P
			|| keydata.action == R))
		mlx_error_sl("Obrigado por jogar!\nDev:Phenriq2", -41, sl);
	if ((keydata.key == UP || keydata.key == W) && (keydata.action == P
			|| keydata.action == R))
		miniprintf("Moves:%d\n", sl->vars.hook++);
	if ((keydata.key == RIGHT || keydata.key == D) && (keydata.action == P
			|| keydata.action == R))
		miniprintf("Moves:%d\n", sl->vars.hook++);
	if ((keydata.key == LEFT || keydata.key == A) && (keydata.action == P
			|| keydata.action == R))
		miniprintf("Moves:%d\n", sl->vars.hook++);
	if ((keydata.key == DOWN || keydata.key == S) && (keydata.action == P
			|| keydata.action == R))
		miniprintf("Moves:%d\n", sl->vars.hook++);
}
void	mlx_images_init(t_sl *sl)
{
	sl->images.player_img = mlx_new_image(sl->ml);
	sl->images.player = mlx_load_png("../../assets/player.png");
	sl->images.player_img = mlx_texture_to_image(sl->mlx, sl->images.player);
	sl->images.wall_img = mlx_new_image(sl->ml);
	sl->images.wall = mlx_load_png("../../assets/wall.png");
	sl->images.wall_img = mlx_texture_to_image(sl->mlx, sl->images.wall);
	sl->images.collectable_img = mlx_new_image(sl->ml);
	sl->images.collectable = mlx_load_png("../../assets/collectable.png");
	sl->images.collectable_img = mlx_texture_to_image(sl->mlx,
														sl->images.collectable);
	sl->images.exit_img = mlx_new_image(sl->ml);
	sl->images.exit = mlx_load_png("../../assets/exit.png");
	sl->images.exit_img = mlx_texture_to_image(sl->mlx, sl->images.exit);
	sl->images.floor_img = mlx_new_image(sl->ml);
	sl->images.floor = mlx_load_png("../../assets/floor.png");
	sl->images.floor_img = mlx_texture_to_image(sl->mlx, sl->images.floor);
}

void	map_creator(t_sl *sl)
{
	sl->vars.j = 0;
	sl->vars.k = 0;
	while (sl->map_file.map[sl->vars.j])
	{
		while (sl->map_file.map[sl->vars.j][sl->vars.k])
		{
			if (sl->map_file.map[sl->vars.j][sl->vars.k] == '1')
				mlx_image_to_window(sl->mlx, sl->images.wall_img, sl->vars.k
						, sl->vars.j);
			if (sl->map_file.map[sl->vars.j][sl->vars.k] == 'C')
				mlx_image_to_window(sl->mlx, sl->images.collectable_img,
						sl->vars.k, sl->vars.j);
			if (sl->map_file.map[sl->vars.j][sl->vars.k] == 'E')
				mlx_image_to_window(sl->mlx, sl->images.exit_img, sl->vars.k
					, sl->vars.j);
			if (sl->map_file.map[sl->vars.j][sl->vars.k] == '0')
				mlx_image_to_window(sl->mlx, sl->images.floor_img, sl->vars.k
					, sl->vars.j);
			sl->vars.k++;
		}
		sl->vars.k = 0;
		sl->vars.j++;
	}
	mlx_image_to_window(sl->mlx, sl->images.player_img, sl->vars.start_x,
			sl->vars.start_y);
}

void	mlx_work(t_sl *sl)
{
	// mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	sl->mlx = mlx_init(sl->map_file.width * 50, sl->map_file.height * 50,
			"papacu", 1);
	if (!sl->mlx)
		mlx_error_sl("mlx_init() failed", -40, sl);
	mlx_images_init(sl);
	map_creator(sl);
	mlx_key_hook(sl->mlx, &my_keyhook, (void *)sl);
	mlx_loop(sl->mlx);
}

int	main(int argc, char **argv)
{
	t_sl sl;

	if (argc != 2)
		ft_error("Invalid number of arguments", &sl);
	initiate_variables_collectables(&sl);
	arg_cheker(argv[1], &sl);
	map_maker(&sl);
	mlx_work(&sl);
}