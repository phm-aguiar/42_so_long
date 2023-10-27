/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:16:51 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/27 16:13:11 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error(char *str, t_sl *sl)
{

	if (sl->commom_variables.choice == -40)
	{
		ft_matrixdel(sl->map_file.map);
		ft_matrixdel(sl->map_file.fld_map);
		exit(EXIT_SUCCESS);
	}
	ft_printf("Error\n%s", str);
	if (sl->commom_variables.choice == -42)
	{
		close(sl->commom_variables.fd);
		perror("");
	}
	if (sl->commom_variables.choice == -41)
		perror("");
	exit(EXIT_FAILURE);
}