/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_verify_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:20:47 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/13 19:41:19 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes_and_defines_so_long.h"

void	verify_exit_enimy(t_sl *sl, int px, int py)
{
	int	i;

	i = sl->recurses.boss - 1;
	if (px == sl->image[3].image->instances[0].x
		&& py == sl->image[3].image->instances[0].y)
	{
		if (sl->recurses.collectibles == 0)
			mlx_error_sl("Obrigado por jogar!\nDev:Phenriq2", sl);
	}
	while (i >= 0)
	{
		if (px == sl->image[4].image->instances[i].x
			&& py == sl->image[4].image->instances[i].y)
			mlx_error_sl("Voce perdeu!!\nObrigado por jogar!\
			\nDev:Phenriq2", sl);
		i--;
	}
}

void	verify_collectable(t_sl *sl, int px, int py)
{
	int	cx;
	int	cy;
	int	i;
	int	j;

	i = 5;
	j = sl->recurses.total_key + i;
	while (i < j)
	{
		cx = sl->image[i].image->instances[0].x;
		cy = sl->image[i].image->instances[0].y;
		if (px == cx && py == cy
			&& sl->image[i].image->instances[0].enabled != 0)
		{
			sl->image[i].image->instances[0].enabled = 0;
			sl->recurses.collectibles--;
			break ;
		}
		i++;
	}
	verify_exit_enimy(sl, px, py);
}

int	verify_content(t_sl *sl, int x, int y)
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
	while (i < sl->recurses.wall)
	{
		wx = sl->image[1].image->instances[i].x;
		wy = sl->image[1].image->instances[i].y;
		if (px == wx && py == wy)
			return (1);
		i++;
	}
	verify_collectable(sl, px, py);
	return (0);
}
