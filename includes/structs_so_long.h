/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_so_long.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:27:45 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/02 17:06:16 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_SO_LONG_H
# define STRUCTS_SO_LONG_H

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
	int 			pf_counter;
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

typedef struct s_sl
{
	t_map			map_file;
	t_recurses		recurses;
	t_commom_vars	vars;

}					t_sl;

#endif
