/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:28:56 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/19 17:49:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../MLX42/include/MLX42/MLX42.h"
# include "../bin/libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define PERMITED_CHARS "01CEP"

// STRUCTS SO_LONG
typedef struct s_char_map
{
	char			**map;
}					t_char_map;

typedef struct s_map_recurses
{
	int				player;
	int				collectibles;
	int				exit;
	int				wall;
}					t_map_recurses;

typedef struct xy
{
	int				len_map_x;
	int				len_map_y;
}					t_xy;

typedef struct s_map
{
	t_xy			dimentions;
	t_char_map		map_file;
	t_map_recurses	recurses;
}					t_map;

#endif
