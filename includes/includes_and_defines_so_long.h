/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_and_defines_so_long.h                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:04:43 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/10 13:35:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_AND_DEFINES_SO_LONG_H
# define INCLUDES_AND_DEFINES_SO_LONG_H

// includes_and_defines_so_long.h
# include "../src/libft/libft.h"
# include "MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// DEFINES SO_LONG
# define EMPTY 0
# define START "P"
# define END "E"
# define COLLECTABLE "C"
# define PERMITED_CHARS "CEPI10"
# define WIDTH 512
# define HEIGHT 512
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
	int				z;
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
	int				total_key;
	int				exit;
	int				wall;
}					t_recurses;

typedef struct s_image
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;
}					t_image;

typedef struct s_sl
{
	t_map			map_file;
	t_recurses		recurses;
	t_commom_vars	vars;
	mlx_t			*mlx;
	t_image			image[1000];
}					t_sl;

// FUNCTIONS SO_LONG
void				initiate_variables_collectables(t_sl *sl);
void				check_if_matrix_is_rectangle(t_sl *sl);
void				find_player(t_sl *sl, int y, int x, int choise);
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
void				map_creator(t_sl *sl);
void				floor_all(t_sl *sl, mlx_image_t *img);
t_image				image_load(void *mlx, char *path);
void				load_path(char **path);
void				all_image(t_sl *set);
void				counter_wall(t_sl *sl);

#endif
