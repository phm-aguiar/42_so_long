/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ONCOMMING2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/27 15:01:51 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	debugger(t_map *teste)
{
	int	i;

	i = 0;
	printf("player: %d\n", teste->recurses.player);
	printf("collectibles: %d\n", teste->recurses.collectibles);
	printf("exit: %d\n", teste->recurses.exit);
	printf("wall: %d\n", teste->recurses.wall);
	printf("x: %d\n", teste->dimentions.x);
	printf("y: %d\n", teste->dimentions.y);
	while (teste->map_file.map[i])
		printf("%s\n", teste->map_file.map[i++]);
}
int	ft_error(char *msg)
{
	printf("Error\n%s\n", msg);
	return (0);
}
void	iniciate_struct(t_map *map)
{
	map->dimentions.x = 0;
	map->dimentions.y = 0;
	map->recurses.player = 0;
	map->recurses.collectibles = 0;
	map->recurses.exit = 0;
	map->recurses.wall = 0;
}

int	validate_width(t_map *map_files)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(map_files->map_file.map[0]);
	map_files->dimentions.x = len;
	if (len < 3)
	{
		ft_error("Invalid map width");
		return (0);
	}
	while (map_files->map_file.map[i])
	{
		if (ft_strlen(map_files->map_file.map[i]) != len)
		{
			ft_error("Invalid map width");
			return (0);
		}
		i++;
	}
	map_files->dimentions.y = i;
	return (1);
}

int	validate_empty_map(char **map)
{
	if (!map[0])
	{
		ft_error("Empty map");
		return (0);
	}
	return (1);
}
bool	validate_walls(t_map *map)
{
	int	j;
	int	k;
	int	x;
	int	y;

	x = map->dimentions.x;
	y = map->dimentions.y;
	j = 0;
	k = 0;
	while (map->map_file.map[j])
	{
		while (map->map_file.map[j][k])
		{
			if (map->map_file.map[0][k] != '1')
				return (FALSE);
			else if (map->map_file.map[j][0] != '1' ||
						map->map_file.map[j][x - 1] != '1')
				return (FALSE);
			else if (map->map_file.map[y - 1][k] != '1')
				return (FALSE);
			k++;
		}
		j++;
	}
	return (TRUE);
}

void	increment_map(char c, t_map *map)
{
	if (c == 'P')
		map->recurses.player++;
	if (c == 'C')
		map->recurses.collectibles++;
	if (c == 'E')
		map->recurses.exit++;
	if (c == '1')
		map->recurses.wall++;
}

int	validate_elements(t_map *elements)
{
	int	i;
	int	j;

	i = 0;
	while (elements->map_file.map[i])
	{
		j = 0;
		while (elements->map_file.map[i][j])
		{
			if (!ft_strchr(PERMITED_CHARS, elements->map_file.map[i][j]))
			{
				// ft_error("Invalid permited map elements ");
				return (0);
			}
			else
				increment_map(elements->map_file.map[i][j], elements);
			j++;
		}
		i++;
	}
	if (elements->recurses.player != 1 || elements->recurses.collectibles < 1
		|| elements->recurses.exit != 1 || elements->recurses.wall < 1)
		return (0);
	return (1);
}
int	validate_map(t_map *map_files)
{
	if (!validate_empty_map(map_files->map_file.map))
	{
		if (!ft_error("Invalid map Validate_empty_map"))
			return (0);
	}
	if (!validate_width(map_files))
	{
		if (!ft_error("Invalid map Validate_width"))
			return (0);
	}
	if (!validate_elements(map_files))
	{
		if (!ft_error("Invalid map Validate_elements"))
			return (0);
	}
	if (!validate_walls(map_files))
	{
		if (!ft_error("Invalid map Validate_walls"))
			return (0);
	}
	return (1);
}

char	**make_map(char *path)
{
	int		fd;
	char	line[4096];
	int		tmp;
	char	**map;
	int		i;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		ft_error("Invalid file");
		return (NULL);
	}
	read(fd, line, 1024);
	map = ft_split(line, '\n');
	close(fd);
	return (map);
}

int	validate_argv(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == '.' && argv[i + 1] == 'b' && argv[i + 2] == 'e' && argv[i
			+ 3] == 'r' && argv[i + 4] == '\0')
			return (1);
		i++;
	}
	return (0);
}
int	map_checker(char *path, t_map *map)
{
	iniciate_struct(map);
	map->map_file.map = make_map(path);
	if (!map->map_file.map)
	{
		if (!ft_error("Invalid file"))
			return (0);
	}
	if (!validate_map(map))
	{
		debugger(map);
		return (0);
	}
	debugger(map);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map	so_long;
	int		i;

	i = 0;
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
	if (!map_checker(argv[1], &so_long))
		return (0);
	printf("Valid map\n");
	while (so_long.map_file.map[i])
		free(so_long.map_file.map[i++]);
	free(so_long.map_file.map);
}
