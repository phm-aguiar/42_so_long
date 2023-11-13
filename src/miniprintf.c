/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:13:39 by phenriq2          #+#    #+#             */
/*   Updated: 2023/11/13 16:35:56 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes_and_defines_so_long.h"

static int	ft_check_format(va_list args, char current_format)
{
	int	count;

	count = 0;
	if (current_format == 'c')
		count += ft_putchar((char)va_arg(args, int));
	else if (current_format == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (current_format == 'd' || current_format == 'i')
		count += ft_putnbr_base(va_arg(args, int), "0123456789");
	else if (current_format == '%')
		count += ft_putchar('%');
	return (count);
}

int	miniprintf(const char *string, ...)
{
	va_list	args;
	int		bytes;
	int		index;

	index = 0;
	bytes = 0;
	va_start(args, string);
	while (string[index] != '\0')
	{
		if (string[index] == '%')
		{
			index++;
			bytes += ft_check_format(args, string[index]);
		}
		else
			bytes += ft_putchar(string[index]);
		index++;
	}
	va_end(args);
	return (bytes);
}
