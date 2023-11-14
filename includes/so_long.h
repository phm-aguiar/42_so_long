/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:04:43 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/14 14:48:46 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "includes_defines.h"

typedef struct s_vars
{
	char				*path;
	int					choice;
	int					fd;
	int					index;
	int					bytes_read;
	int					i;
	int					k;
	int					j;
	int					start_x;
	int					start_y;
	int					end_x;
	int					end_y;
	int					pf_counter;
	int					hook;
	char				*move_counter;
}						t_vars;

typedef struct s_map
{
	char				**map;
	char				**mapcpy;
	char				buffer[4080];
	int					height;
	int					width;
}						t_map;

typedef struct s_recurses
{
	int					player;
	int					collectibles;
	int					total_key;
	int					boss;
	int					door;
	int					wall;
}						t_recurses;

typedef struct s_image
{
	mlx_texture_t		*texture;
	mlx_image_t			*image;
}						t_image;

typedef struct s_sl
{
	t_map				map_file;
	t_recurses			recurses;
	t_vars				vars;
	mlx_t				*mlx;
	t_image				image[1000];
	int					total_images;
	mlx_image_t			*write;
}						t_sl;

t_image					image_load(void *mlx, char *path);
void					load_path(char **path);
void					all_image(t_sl *set);
void					ft_image(void *mlx, mlx_image_t *img, int x, int y);
void					floor_all(t_sl *sl, mlx_image_t *img);
void					collectable_creator(t_sl *sl);
void					map_creator(t_sl *sl);
void					initiate_variables_collectables(t_sl *sl);
void					arg_cheker(char *path, t_sl *sl);
void					ft_error(char *str, t_sl *sl, int choise);
void					map_maker(t_sl *sl);
void					set_xy(t_sl *sl, int y, int x, int choise);
void					check_content(t_sl *sl, char current_char, char **map);
void					check_edges_walls(t_sl *sl);
void					full_floodfill(char **map, int y, int x);
void					validate_map(t_sl *sl);
void					check_if_matrix_is_rectangle(t_sl *sl);
void					verify_path(t_sl *sl, char **map);
int						miniprintf(const char *string, ...);
void					my_move_img(t_sl *sl, int direction);
void					my_keyhook(mlx_key_data_t keydata, void *param);
void					mlx_error_sl(char *str, t_sl *sl);
void					mlx_work(t_sl *sl);
void					verify_exit_enimy(t_sl *sl, int px, int py);
void					verify_collectable(t_sl *sl, int px, int py);
int						verify_content(t_sl *sl, int x, int y);
void					img_del(t_sl *sl);

#endif
