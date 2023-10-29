/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:30 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/29 18:09:00 by phenriq2         ###   ########.fr       */
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
	sl.vars.choice = -40;
	ft_error("Invalid map", &sl);
}
