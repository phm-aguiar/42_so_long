/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:00:21 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/08 15:11:05 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

static mlx_image_t	*image;

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

void	ft_hook(void *param)
{
	mlx_t	*mlx;
	int		i;

	mlx = param;
	i = 0;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		image->instances[0].y -= 5;
		printf("%d", i++);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		image->instances[0].y += 5;
		printf("%d", i++);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		image->instances[0].x -= 5;
		printf("%d", i++);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		image->instances[0].x += 5;
		printf("%d", i++);
	}
}

// -----------------------------------------------------------------------------

int32_t	main(int32_t argc, const char *argv[])
{
	mlx_t *mlx;

	// Gotta error check this stuff
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}