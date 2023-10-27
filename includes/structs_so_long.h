#ifndef STRUCTS_SO_LONG_H
# define STRUCTS_SO_LONG_H

// STRUCTS SO_LONG
typedef struct s_commom_variables
{
	char				*path;
	int					choice;
	int					fd;
	int					index;
	int					bytes_read;
	int					k;
	int					j;
}						t_commom_variables;

typedef struct s_map
{
	char				**map;
	char				**fld_map;
	char				buffer[4080];
	char				*tmp;
}						t_map;

typedef struct s_recurses
{
	int					player;
	int					collectibles;
	int					exit;
	int					wall;
}						t_recurses;

typedef struct s_xy
{
	int					x;
	int					y;
}						t_xy;

typedef struct s_sl
{
	t_xy				dimentions;
	t_map				map_file;
	t_recurses			recurses;
	t_commom_variables	commom_variables;

}						t_sl;

#endif
