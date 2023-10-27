/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:30 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/27 16:37:30 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_sl	sl;
	if (argc != 2)
		ft_error("Invalid number of arguments", &sl);
	iniciate_variables_collectables(&sl);
	arg_cheker(argv[1], &sl);
	map_maker(&sl);
	check_if_matrix_is_rectangle(&sl);

	sl.commom_variables.choice = -40;
	ft_error("Invalid map", &sl);
}
