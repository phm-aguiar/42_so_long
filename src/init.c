/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/14 12:51:38 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	initiate_variables_collectables(t_sl *sl)
{
	sl->recurses.player = 0;
	sl->recurses.door = 0;
	sl->recurses.wall = 0;
	sl->recurses.boss = 0;
	sl->recurses.collectibles = 0;
	sl->recurses.total_key = 0;
	sl->vars.index = 0;
	sl->vars.bytes_read = 0;
	sl->vars.pf_counter = 0;
	sl->vars.hook = 0;
}

void	arg_cheker(char *path, t_sl *sl)
{
	size_t		path_len;
	const char	*extension;
	size_t		extension_len;

	path_len = ft_strlen(path);
	extension = ".ber";
	extension_len = ft_strlen(extension);
	if (path_len >= extension_len && ft_strncmp(path + path_len - extension_len,
			extension, extension_len) == 0)
	{
		sl->vars.path = path;
		return ;
	}
	ft_error("Invalid file extension", sl, 42);
}
