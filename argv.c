/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:20:59 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/19 17:21:24 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/so_long.h"

bool	validate_argv(char *argv)
{
	int i;

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