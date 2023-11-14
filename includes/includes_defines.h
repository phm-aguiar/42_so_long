/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes_defines.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:47:31 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/14 10:53:01 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_DEFINES_H
# define INCLUDES_DEFINES_H

# include "../libs/MLX42/include/MLX42/MLX42.h"
# include "../libs/libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define PERMITED_CHARS "CEPI10"
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

#endif