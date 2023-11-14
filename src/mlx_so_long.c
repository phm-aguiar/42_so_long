/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:29:49 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/14 16:00:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	img_del(t_sl *sl)
{
	int	i;

	i = 0;
	while (i < sl->total_images)
		mlx_delete_texture(sl->image[i++].texture);
}

void	mlx_error_sl(char *str, t_sl *sl)
{
	int	i;

	i = 0;
	mlx_terminate(sl->mlx);
	img_del(sl);
	ft_error(str, sl, sl->vars.choice);
}

void	mlx_work(t_sl *sl)
{
	sl->recurses.total_key = sl->recurses.collectibles;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	sl->mlx = mlx_init(sl->map_file.width * 64, sl->map_file.height * 64,
			"so_long", 1);
	if (!sl->mlx)
		ft_error("mlx_init() failed\n", sl, 42);
	all_image(sl);
	map_creator(sl);
	mlx_key_hook(sl->mlx, &my_keyhook, (void *)sl);
	mlx_loop(sl->mlx);
}
