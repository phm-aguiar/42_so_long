/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ONVOMMING3.C                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:01:43 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/09 11:10:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	modifier_matriz(t_sl *sl, int sx, int sy)
// {
// 	if (sl->map_file.map[sl->vars.start_y + sy][sl->vars.start_x + sx] == '1')
// 		return (0);
// 	if (sl->map_file.map[sl->vars.start_y + sy][sl->vars.start_x + sx] == 'C')
// 	{
// 		sl->images.collectable_img->enabled = false;
// 		sl->map_file.map[sl->vars.start_y + sy][sl->vars.start_x + sx] = '0';
// 		sl->recurses.collectibles--;
// 	}
// 	if (sl->map_file.map[sl->vars.start_y + sy][sl->vars.start_x + sx] == 'E')
// 	{
// 		if (sl->recurses.collectibles == 0)
// 			mlx_error_sl("Obrigado por jogar!\nDev:Phenriq2", -41, sl);
// 	}
// 	sl->map_file.map[sl->vars.start_y][sl->vars.start_x] = '0';
// 	sl->vars.start_x = sl->vars.start_x + sx;
// 	sl->vars.start_y = sl->vars.start_y + sy;
// 	return (1);
// }

// void	ft_image(void *mlx, mlx_image_t *img, int x, int y)
// {
// 	mlx_image_to_window(mlx, img, x * 64, y * 64);
// }

// void	my_move_img(t_sl *sl, int direction)
// {
// 	if (direction == 1)
// 	{
// 		if (modifier_matriz(sl, 0, -1 ))
// 			sl->images.player_img->instances[0].y -= 64;
// 	}
// 	else if (direction == 2)
// 	{
// 		if (modifier_matriz(sl, 0, 1))
// 			sl->images.player_img->instances[0].y += 64;
// 	}
// 	else if (direction == 3)
// 	{
// 		if (modifier_matriz(sl, -1, 0))
// 			sl->images.player_img->instances[0].x -= 64;
// 	}
// 	else if (direction == 4)
// 	{
// 		if (modifier_matriz(sl, +1, 0))
// 			sl->images.player_img->instances[0].x += 64;
// 	}
// 	miniprintf("Moves:%d\n", sl->vars.hook++);
// }

// void	my_keyhook(mlx_key_data_t keydata, void *param)
// {
// 	t_sl	*sl;

// 	sl = (t_sl *)param;
// 	if ((keydata.key == ESC || keydata.key == Q) &&
// 		(keydata.action == P || keydata.action == R))
// 		mlx_error_sl("Obrigado por jogar!\nDev:Phenriq2", -41, sl);
// 	if ((keydata.key == UP || keydata.key == W) &&
// 		(keydata.action == P || keydata.action == R))
// 		my_move_img(sl, 1);
// 	if ((keydata.key == RIGHT || keydata.key == D) &&
// 		(keydata.action == P || keydata.action == R))
// 		my_move_img(sl, 4);
// 	if ((keydata.key == LEFT || keydata.key == A) &&
// 		(keydata.action == P || keydata.action == R))
// 		my_move_img(sl, 3);
// 	if ((keydata.key == DOWN || keydata.key == S) &&
// 		(keydata.action == P || keydata.action == R))
// 		my_move_img(sl, 2);
// }

// void	floor_all(t_sl *sl, mlx_image_t *img)
// {
// 	sl->vars.i = 0;
// 	while (sl->map_file.map[sl->vars.i])
// 	{
// 		sl->vars.j = 0;
// 		while (sl->map_file.map[sl->vars.i][sl->vars.j])
// 		{
// 			ft_image(sl->mlx, img, sl->vars.j, sl->vars.i);
// 			sl->vars.j++;
// 		}
// 		sl->vars.i++;
// 	}
// }

// void	mlx_images_init(t_sl *sl)
// {
// 	sl->images.player_img = mlx_new_image(sl->mlx, 64, 64);
// 	sl->images.player = mlx_load_png("../../assets/player.png");
// 	sl->images.player_img = mlx_texture_to_image(sl->mlx, sl->images.player);
// 	sl->images.wall_img = mlx_new_image(sl->mlx, 64, 64);
// 	sl->images.wall = mlx_load_png("../../assets/wall.png");
// 	sl->images.wall_img = mlx_texture_to_image(sl->mlx, sl->images.wall);
// 	sl->images.collectable_img = mlx_new_image(sl->mlx, 64, 64);
// 	sl->images.collectable = mlx_load_png("../../assets/collectable.png");
// 	sl->images.collectable_img =
// 		mlx_texture_to_image(sl->mlx, sl->images.collectable);
// 	sl->images.exit_img = mlx_new_image(sl->mlx, 64, 64);
// 	sl->images.exit = mlx_load_png("../../assets/exit.png");
// 	sl->images.exit_img = mlx_texture_to_image(sl->mlx, sl->images.exit);
// 	sl->images.floor_img = mlx_new_image(sl->mlx, 64, 64);
// 	sl->images.floor = mlx_load_png("../../assets/floor.png");
// 	sl->images.floor_img = mlx_texture_to_image(sl->mlx, sl->images.floor);
// }

// void	map_creator(t_sl *sl)
// {
// 	floor_all(sl, sl->images.floor_img);
// 	sl->vars.i = 0;
// 	while (sl->map_file.map[sl->vars.i])
// 	{
// 		sl->vars.j = 0;
// 		while (sl->map_file.map[sl->vars.i][sl->vars.j])
// 		{
// 			if (sl->map_file.map[sl->vars.i][sl->vars.j] == '1')
// 				ft_image(sl->mlx, sl->images.wall_img, sl->vars.j, sl->vars.i);
// 			if (sl->map_file.map[sl->vars.i][sl->vars.j] == 'C')
// 				ft_image(sl->mlx, sl->images.collectable_img, sl->vars.j,
// 						sl->vars.i);
// 			if (sl->map_file.map[sl->vars.i][sl->vars.j] == 'E')
// 				ft_image(sl->mlx, sl->images.exit_img, sl->vars.j, sl->vars.i);
// 			if (sl->map_file.map[sl->vars.i][sl->vars.j] == 'P')
// 				ft_image(sl->mlx, sl->images.player_img, sl->vars.j,
// 						sl->vars.i);
// 			sl->vars.j++;
// 		}
// 		sl->vars.i++;
// 	}
// }