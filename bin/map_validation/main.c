/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:33:30 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/06 15:59:43 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/includes_and_defines_so_long.h"

int	main(int argc, char **argv)
{
	t_sl sl;

	if (argc != 2)
		ft_error("Invalid number of arguments", &sl);
	initiate_variables_collectables(&sl);
	arg_cheker(argv[1], &sl);
	map_maker(&sl);
	sl.vars.choice = -41;
	ft_error("tudo certo", &sl);
}