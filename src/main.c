/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:38:55 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/12 18:00:42 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes_and_defines_so_long.h"

int	main(int argc, char **argv)
{
	t_sl	sl;

	if (argc != 2)
		ft_error("Invalid number of arguments", &sl, 42);
	initiate_variables_collectables(&sl);
	arg_cheker(argv[1], &sl);
	map_maker(&sl);
	mlx_work(&sl);
	return (0);
}
