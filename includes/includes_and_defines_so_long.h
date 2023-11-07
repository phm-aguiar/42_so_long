/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_and_defines_so_long.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:04:43 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/07 18:30:18 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_AND_DEFINES_SO_LONG_H
# define INCLUDES_AND_DEFINES_SO_LONG_H

// includes_and_defines_so_long.h
# include "../bin/libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define WALL INT_MAX
# define EMPTY 0
# define START "P"
# define END "E"
# define COLLECTABLE "C"
# define PERMITED_CHARS "CEP10"
# define WIDTH 32
# define HEIGHT 32
# define ESC MLX_KEY_ESCAPE
# define UP MLX_KEY_UP
# define DOWN MLX_KEY_DOWN
# define LEFT MLX_KEY_LEFT
# define RIGHT MLX_KEY_RIGHT
# define W MLX_KEY_W
# define S MLX_KEY_S
# define A MLX_KEY_A
# define D MLX_KEY_D
# define Q MLX_KEY_Q
# define P MLX_PRESS
# define R MLX_REPEAT


// STRUCTS SO_LONG

typedef struct s_commom_vars
{
	char			*path;
	int				choice;
	int				fd;
	int				index;
	int				bytes_read;
	int				i;
	int				k;
	int				j;
	int				start_x;
	int				start_y;
	int				end_x;
	int				end_y;
	int				pf_counter;
	int				hook;
}					t_commom_vars;

typedef struct s_map
{
	char			**map;
	char			**mapcpy;
	char			buffer[4080];
	char			*tmp;
	int				height;
	int				width;
}					t_map;

typedef struct s_recurses
{
	int				player;
	int				collectibles;
	int				exit;
	int				wall;
}					t_recurses;

typedef struct s_images
{
	mlx_texture_t	*wall;
	mlx_image_t		*wall_img;
	mlx_texture_t	*player;
	mlx_image_t		*player_img;
	mlx_texture_t	*collectable;
	mlx_image_t		*collectable_img;
	mlx_texture_t	*exit;
	mlx_image_t		*exit_img;
	mlx_texture_t	*floor;
	mlx_image_t		*floor_img;
}					t_images;


typedef struct s_sl
{
	t_map			map_file;
	t_recurses		recurses;
	t_commom_vars	vars;
	mlx_t			*mlx;
	t_images images;
}					t_sl;

// FUNCTIONS SO_LONG
void				initiate_variables_collectables(t_sl *sl);
void				check_if_matrix_is_rectangle(t_sl *sl);
void				find_player(t_sl *sl, int y, int x);
void				verify_path_ok(t_sl *sl, char **map);
void				full_floodfill(char **map, int y, int x);
void				check_edges_walls(t_sl *sl);
void				check_content(t_sl *sl);
void				validate_map(t_sl *sl);
void				map_maker(t_sl *sl);
void				ft_error(char *str, t_sl *sl);
void				arg_cheker(char *path, t_sl *sl);
void				mlx_error_sl(char *str, int choise, t_sl *sl);
int					miniprintf(const char *string, ...);

#endif
