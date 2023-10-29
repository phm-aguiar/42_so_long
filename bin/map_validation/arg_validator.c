/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 12:08:04 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/29 14:32:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	arg_cheker(char *path, t_sl *sl)
{
	while (path[sl->vars.index])
	{
		if (path[sl->vars.index] == '.'
			&& path[sl->vars.index + 1] == 'b'
			&& path[sl->vars.index + 2] == 'e'
			&& path[sl->vars.index + 3] == 'r'
			&& path[sl->vars.index + 4] == '\0')
		{
			sl->vars.index = 0;
			sl->vars.path = path;
			return ;
		}
		sl->vars.index++;
	}
	sl->vars.index = 0;
	ft_error("Invalid file extension", sl);
}
