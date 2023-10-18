/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:19:12 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/18 19:04:57 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 512
#define HEIGHT 512

typedef struct s_game	t_game;
struct					s_game
{
	mlx_t				*mlx;
	mlx_texture_t		*texture[10];
	mlx_image_t			*image[10];
};

static mlx_image_t		*g_image;

void	key_bind(void *param)
{
	t_game	*game;

	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE) || mlx_is_key_down(game->mlx,
			MLX_KEY_Q))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_UP) || mlx_is_key_down(game->mlx,
			MLX_KEY_W))
		game->image[1]->instances[0].y -= 6;
	if (mlx_is_key_down(game->mlx, MLX_KEY_DOWN) || mlx_is_key_down(game->mlx,
			MLX_KEY_S))
		game->image[1]->instances[0].y += 6;
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT) || mlx_is_key_down(game->mlx,
			MLX_KEY_A))
		game->image[1]->instances[0].x -= 6;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT) || mlx_is_key_down(game->mlx,
			MLX_KEY_D))
		game->image[1]->instances[0].x += 6;
}

// -----------------------------------------------------------------------------

int32_t	main(int32_t argc, const char *argv[])
{
	t_game	local;
	t_game	*game;

	game = malloc(sizeof(t_game));
	game = &local;
	game->texture[1] = malloc(sizeof(mlx_texture_t *) * 10);
	game->image[1] = malloc(sizeof(mlx_image_t *) * 10);

	game->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	game->texture[1] = mlx_load_png("assets/walk_right.png");

	game->image[1] = mlx_texture_to_image(game->mlx, game->texture[1]);

	game->image[1] = mlx_new_image(game->mlx, 90, 90);
	mlx_loop_hook(game->mlx, key_bind, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
