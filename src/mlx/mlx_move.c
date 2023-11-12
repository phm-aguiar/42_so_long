/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:19:43 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/12 12:37:44 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

void	my_move_img(t_sl *sl, int direction)
{
	if (direction == 1)
	{
		if (!verify_content(sl, 0, -64))
			sl->image[0].image->instances[0].y -= 64;
	}
	if (direction == 2)
	{
		if (!verify_content(sl, 0, 64))
			sl->image[0].image->instances[0].y += 64;
	}
	if (direction == 3)
	{
		if (!verify_content(sl, -64, 0))
			sl->image[0].image->instances[0].x -= 64;
	}
	if (direction == 4)
	{
		if (!verify_content(sl, 64, 0))
			sl->image[0].image->instances[0].x += 64;
	}
	miniprintf("Moves:%d\n", sl->vars.hook++);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_sl	*sl;

	sl = (t_sl *)param;
	if (keydata.key == ESC && (keydata.action == P || keydata.action == R))
		mlx_error_sl("Obrigado por jogar!\nDev:Phenriq2", -41, sl);
	if ((keydata.key == UP || keydata.key == W) && (keydata.action == P
			|| keydata.action == R))
		my_move_img(sl, 1);
	if ((keydata.key == RIGHT || keydata.key == D) && (keydata.action == P
			|| keydata.action == R))
		my_move_img(sl, 4);
	if ((keydata.key == LEFT || keydata.key == A) && (keydata.action == P
			|| keydata.action == R))
		my_move_img(sl, 3);
	if ((keydata.key == DOWN || keydata.key == S) && (keydata.action == P
			|| keydata.action == R))
		my_move_img(sl, 2);
}
