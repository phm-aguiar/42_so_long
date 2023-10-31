/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_so_long.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:27:45 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/31 20:32:25 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_SO_LONG_H
# define STRUCTS_SO_LONG_H

// STRUCTS SO_LONG

typedef struct s_node
{
	char						type;
	int							x;
	int							y;
	int							g;
	int							h;
	int							f;
	struct s_node				*parent;
}								t_node;

typedef struct s_open_list_node
{
	t_node						*node;
	int f; // Custo total estimado (f = g + h)
	struct s_open_list_node		*next;
}								t_open_list_node;

typedef struct s_closed_list_node
{
	t_node						*node;
	struct s_closed_list_node	*next;
}								t_closed_list_node;

typedef struct s_commom_vars
{
	char						*path;
	int							choice;
	int							fd;
	int							index;
	int							bytes_read;
	int							i;
	int							k;
	int							j;
	int							start_x;
	int							start_y;
	int							end_x;
	int							end_y;
}								t_commom_vars;

typedef struct s_map
{
	char						**map;
	char						**fld_map;
	char						buffer[4080];
	char						*tmp;
	int							height;
	int							width;
}								t_map;

typedef struct s_recurses
{
	int							player;
	int							collectibles;
	int							exit;
	int							wall;
}								t_recurses;

typedef struct s_sl
{
	t_map						map_file;
	t_recurses					recurses;
	t_commom_vars				vars;
	t_node						**graph;
	t_closed_list_node			*closed;
	s_open_list_node			*open;
}								t_sl;

// enum					e_celltype
// {
// 	WALL,
// 	GROUND,
// 	COLLECTIBLE,
// 	PLAYER,
// 	EXIT
// };

// typedef struct s_node
// {
// 	int					x;
// 	int					y;
// 	enum e_celltype		type;
// 	int					visited;
// 	int					g;
// 	int					h;
// 	int					f;
// 	struct s_node		*parent;
// }						t_node;

#endif
