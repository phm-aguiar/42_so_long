/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_so_long.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:28:56 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/06 14:11:19 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_SO_LONG_H
# define FUNCTIONS_SO_LONG_H

# include "structs_so_long.h"

void	initiate_variables_collectables(t_sl *sl);
void	check_if_matrix_is_rectangle(t_sl *sl);
void	find_player(t_sl *sl, int y, int x);
void	verify_path_ok(t_sl *sl, char **map);
void	full_floodfill(char **map, int y, int x);
void	check_edges_walls(t_sl *sl);
void	check_content(t_sl *sl);
void	validate_map(t_sl *sl);
void	map_maker(t_sl *sl);
void	ft_error(char *str, t_sl *sl);
void	arg_cheker(char *path, t_sl *sl);

#endif
