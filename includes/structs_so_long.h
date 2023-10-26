#ifndef STRUCTS_SO_LONG_H
# define STRUCTS_SO_LONG_H

// STRUCTS SO_LONG
typedef struct s_char_map
{
	char		**map;
	char		**fld_map;
}				t_map;

typedef struct s_map_recurses
{
	int			player;
	int			collectibles;
	int			exit;
	int			wall;
}				t_recurses;

typedef struct xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct s_map
{
	t_xy		dimentions;
	t_map		map_file;
	t_recurses	recurses;
}				t_so_long;

#endif
