/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/12 18:10:08 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_and_defines_so_long.h"

void	initiate_variables_collectables(t_sl *sl)
{
	sl->recurses.player = 0;
	sl->recurses.exit = 0;
	sl->recurses.collectibles = 0;
	sl->recurses.total_key = 0;
	sl->recurses.wall = 0;
	sl->recurses.entity = 0;
	sl->vars.index = 0;
	sl->vars.bytes_read = 0;
	sl->vars.pf_counter = 0;
	sl->vars.hook = 0;
}

void	counter_wall(t_sl *sl)
{
	int	i;
	int	j;

	i = 0;
	while (sl->map_file.map[i])
	{
		j = 0;
		while (sl->map_file.map[i][j])
		{
			if (sl->map_file.map[i][j] == '1')
				sl->recurses.wall++;
			j++;
		}
		i++;
	}
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
