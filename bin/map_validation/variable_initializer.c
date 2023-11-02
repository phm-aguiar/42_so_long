/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_initializer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:14:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/02 16:43:39 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	iniciate_variables_collectables(t_sl *sl)
{
	sl->recurses.player = 0;
	sl->recurses.exit = 0;
	sl->recurses.collectibles = 0;
	sl->recurses.wall = 0;
	sl->vars.index = 0;
	sl->vars.choice = 0;
	sl->vars.bytes_read = 0;
	sl->vars.pf_counter = 0;
}
