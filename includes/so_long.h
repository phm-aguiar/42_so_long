/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 12:28:56 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/02 17:32:33 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// # include "../MLX42/include/MLX42/MLX42.h"
# include "../bin/libft/libft.h"
# include "structs_so_long.h"
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

void	ft_error(char *str, t_sl *sl);
void	iniciate_variables_collectables(t_sl *sl);
void	arg_cheker(char *path, t_sl *sl);
void	map_maker(t_sl *sl);
void	check_if_matrix_is_rectangle(t_sl *sl);
int		check_path_validation(t_sl *sl, int y, int x);

#endif
