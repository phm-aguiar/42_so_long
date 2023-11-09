/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: Invalid date        by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/09 18:28:40 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes_and_defines_so_long.h"

void	verify_collectable(t_sl *sl, int px, int py)
{
	int	cx;
	int	cy;
	int	i;

	i = 4;
	int j = sl->recurses.collectibles + i;
	while (i < j)
	{
		cx = sl->image[i].image->instances[0].x;
		cy = sl->image[i].image->instances[0].y;
			printf("%d", i);
		if (px == cx && py == cy)
		{
			sl->image[i].image->instances[0].enabled = 0;
			sl->recurses.collectibles--;
			break ;
		}
		i++;
	}

}

int	verify_wall(t_sl *sl, int x, int y)
{
	int	wx;
	int	wy;
	int	px;
	int	py;
	int	i;

	i = 0;
	px = sl->image[0].image->instances[0].x + x;
	py = sl->image[0].image->instances[0].y + y;
	if (px < 0 || py < 0 || px > sl->map_file.width * 64
		|| py > sl->map_file.height * 64)
		return (1);
	// printf("px:%d py:%d\n", px, py);
	while (i < sl->recurses.wall)
	{
		wx = sl->image[1].image->instances[i].x;
		wy = sl->image[1].image->instances[i].y;
		// printf("wx:%d wy:%d\n", wx, wy);
		if (px == wx && py == wy)
			return (1);
		i++;
	}
	verify_collectable(sl, px, py);
	return (0);
}

void	my_move_img(t_sl *sl, int direction)
{
	if (direction == 1)
	{
		if (!verify_wall(sl, 0, -64))
			sl->image[0].image->instances[0].y -= 64;
	}
	if (direction == 2)
	{
		if (!verify_wall(sl, 0, 64))
			sl->image[0].image->instances[0].y += 64;
	}
	if (direction == 3)
	{
		if (!verify_wall(sl, -64, 0))
			sl->image[0].image->instances[0].x -= 64;
	}
	if (direction == 4)
	{
		if (!verify_wall(sl, 64, 0))
			sl->image[0].image->instances[0].x += 64;
	}
	miniprintf("Moves:%d\n", sl->vars.hook++);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_sl	*sl;

	sl = (t_sl *)param;
	if (keydata.key == ESC &&
		(keydata.action == P || keydata.action == R))
		mlx_error_sl("Obrigado por jogar!\nDev:Phenriq2", -41, sl);
	if ((keydata.key == UP || keydata.key == W) &&
		(keydata.action == P || keydata.action == R))
		my_move_img(sl, 1);
	if ((keydata.key == RIGHT || keydata.key == D) &&
		(keydata.action == P || keydata.action == R))
		my_move_img(sl, 4);
	if ((keydata.key == LEFT || keydata.key == A) &&
		(keydata.action == P || keydata.action == R))
		my_move_img(sl, 3);
	if ((keydata.key == DOWN || keydata.key == S) &&
		(keydata.action == P || keydata.action == R))
		my_move_img(sl, 2);
}

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
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

void	mlx_work(t_sl *sl)
{
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	sl->mlx =
		mlx_init(sl->map_file.width * 64, sl->map_file.height * 64, "papacu",
				1);
	if (!sl->mlx)
		mlx_error_sl("mlx_init() failed", -40, sl);
	counter_wall(sl);
	all_image(sl);
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