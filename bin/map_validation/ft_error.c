/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:16:51 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/29 14:32:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	ft_error(char *str, t_sl *sl)
{
	if (sl->vars.choice == -40)
	{
		ft_matrixdel(sl->map_file.map);
		ft_matrixdel(sl->map_file.fld_map);
		exit(EXIT_SUCCESS);
	}
	ft_printf("Error\n%s", str);
	if (sl->vars.choice == -42)
	{
		close(sl->vars.fd);
		perror("");
	}
	if (sl->vars.choice == -41)
		perror("");
	exit(EXIT_FAILURE);
}
