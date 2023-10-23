/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ONCOMMING2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/23 18:47:22 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	iniciate_struct(len_line)
{
	t_map	map;

	map.dimentions.len_map_x = len_line - 1;
	map.dimentions.len_map_y = 0;
	map.recurses.player = 0;
	map.recurses.collectibles = 0;
	map.recurses.exit = 0;
	map.recurses.wall = 0;
}

bool	validate_dimentions(char *line, int len_line)
{
	printf("len_line = %d\n", len_line);
	printf("ft_strlen(line) = %zu\n", ft_strlen(line));
	printf("line = %s\n", line);
	if (ft_strlen(line) == len_line)
		return (true);
	else
		return (false);
}

// bool	validate_recurses_map(char *line)
// {
// 	int		i;
// 	t_map	map;

// 	i = 0;
// 	while (line[i])
// 	{
// 		if (line[i] == 'P')
// 			map.recurses.player++;
// 		if (line[i] == 'C')
// 			map.recurses.collectibles++;
// 		if (line[i] == 'E')
// 			map.recurses.exit++;
// 		if (line[i] == '1')
// 			map.recurses.wall++;
// 		i++;
// 	}
// 	if (map.recurses.player != 1 || map.recurses.collectibles < 1
// 		|| map.recurses.exit != 1 || map.recurses.wall < 1)
// 		return (false);
// 	else
// 		return (true);
// }

bool	validate_line(char *msg, int len_line)
{
	int	index;

	index = 0;
	while (index < len_line)
	{
		if (ft_strchr(PERMITED_CHARS, msg[index]) == NULL)
			return (false);
		index++;
	}
	return (true);
}

bool	tratament_file(char *argv)
{
	t_map	map;
	int		fd;
	int		len_line;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (false);
	line = get_next_line(fd);
	while (line)
	{
		/* code */
	}

	if (!validate_line(line, len_line))
		return (false);
	if (!validate_dimentions(line, len_line))
		return (false);
	if (!validate_recurses_map(line))
		return (false);
	map.dimentions.len_map_y++;
	return (true);
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
bool	ft_error(char *msg)
{
	ft_printf("Error\n%s\n", msg);
	return (false);
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
	if (!tratament_file(argv[1]))
	{
		if (!ft_error("Invalid map"))
			return (0);
	}
}
