/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:16:51 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/02 19:21:03 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error(char *str, t_sl *sl)
{
	if (sl->vars.choice == -40)
	{
		ft_printf("Error\n%s", str);
		ft_matrixdel(sl->map_file.map);
		ft_matrixdel(sl->map_file.map);

		exit(EXIT_SUCCESS);
	}
	if (sl->vars.choice == -41)
	{
		ft_printf("\n%s", str);
		ft_matrixdel(sl->map_file.map);
		ft_matrixdel(sl->map_file.mapcpy);
		exit(EXIT_SUCCESS);
	}
	ft_printf("Error\n%s: ", str);
	if (sl->vars.choice == -42)
	{
		close(sl->vars.fd);
		perror("");
	}
	exit(EXIT_FAILURE);
}
