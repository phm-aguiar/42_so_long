/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ONCOMMING2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/24 19:02:09 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

bool	ft_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (false);
}
void	iniciate_struct(int len_line, int lines)
{
	t_map	map;

	map.dimentions.len_map_x = len_line - 1;
	map.dimentions.len_map_y = lines;
	map.recurses.player = 0;
	map.recurses.collectibles = 0;
	map.recurses.exit = 0;
	map.recurses.wall = 0;
}

bool	validate_width(char **map)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map[0]);
	if (len < 3)
	{
		ft_error("Invalid map width");
		return (false);
	}
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
		{
			ft_error("Invalid map width");
			return (false);
		}
		i++;
	}
	iniciate_struct(len, i);
	return (true);
}

bool	validate_empty_map(char **map)
{
	if (!map[0])
	{
		ft_error("Empty map");
		return (false);
	}
	return (true);
}
void	increment_map(char c ,t_map	map)
{
	if (c == 'P')
		map.recurses.player++;
	if (c == 'C')
		map.recurses.collectibles++;
	if (c == 'E')
		map.recurses.exit++;
	if (c == '1')
		map.recurses.wall++;
}

bool	validate_elements(char **map)
{
	int		i;
	int		j;
	t_map	elements;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!ft_strchr(PERMITED_CHARS, map[i][j]))
			{
				ft_error("Invalid permited map elements ");
				return (false);
			}
			else
				increment_map(map[i][j], elements);
			j++;
		}
		i++;
	}
	if (elements.recurses.player != 1 || elements.recurses.collectibles < 1
		|| elements.recurses.exit != 1 || elements.recurses.wall < 1)
		return (false);
	return (true);
}
bool	validate_map(char **map,t_map map_file)
{
	if (!validate_empty_map(map))
		return (false);
	if (!validate_elements(map, map_file))
		return (false);
	if (!validate_width(map))
		return (false);
	return (true);
}

char	**make_map(char *path)
{
	int		fd;
	char	*line;
	char	*tmp;
	char **map;

	line = ft_strdup("");
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Invalid file");
		return (NULL);
	}
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line = ft_strjoin(line, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	map = ft_split(line, '\n');
	free(line);
	return (map);
}

bool	validate_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e' && argv[i
			+ 3] == 'r' && argv[i + 4] == '\0')
			return (true);
		i++;
	}
	return (false);
}
void	map_checker(char *path)
{
	t_map	map;

	map.map_file.map = make_map(path);
	if (!map.map_file.map)
	{
		if (!ft_error("Invalid file"))
			return ;
	}
	if (!validate_map(map.map_file.map))
			return ;
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		if (!ft_error("Invalid number of arguments"))
			return (0);
	}
	if (!validate_argv(argv[1]))
	{
		if (!ft_error("Invalid file extension"))
			return (0);
	}
	map_checker(argv[1]);
	printf("Valid map\n");
}
