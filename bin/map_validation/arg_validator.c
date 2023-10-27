/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/27 16:32:52 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	arg_cheker(char *path, t_sl *sl)
{
	while (path[sl->commom_variables.index])
	{
		if (path[sl->commom_variables.index] == '.'
			&& path[sl->commom_variables.index + 1] == 'b'
			&& path[sl->commom_variables.index + 2] == 'e'
			&& path[sl->commom_variables.index + 3] == 'r'
			&& path[sl->commom_variables.index + 4] == '\0')
		{
			sl->commom_variables.index = 0;
			sl->commom_variables.path = path;
			return ;
		}
		sl->commom_variables.index++;
	}
	sl->commom_variables.index = 0;
	ft_error("Invalid file extension", sl);
}
