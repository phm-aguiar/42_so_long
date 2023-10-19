/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/16 13:25:25 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*extract_lines(t_gnl **main_list)
{
	int		i;
	char	*line;
	int		idx;

	i = ft_sizelst(main_list);
	line = malloc(sizeof(char) * (i + 1));
	if (line == NULL)
		return (NULL);
	idx = 0;
	while (idx < i)
	{
		line[idx] = (*main_list)->data;
		*main_list = (*main_list)->next;
		idx++;
	}
	line[idx] = '\0';
	ft_wipe_list(main_list, -1);
	return (line);
}

char	**ft_split_lst(char const *s, char c)
{
	t_gnl	*main_list;
	char	**words;
	int		i;
	int		idx;

	i = ft_count_words(s, c);
	words = malloc(sizeof(char *) * (i + 1));
	if (words == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
		{
			words[idx] = extract_lines(&main_list);
			idx++;
			s++;
			continue ;
		}
		ft_add_caracter(&main_list, *s);
		s++;
	}
	words[idx] = extract_lines(&main_list);
	words[idx + 1] = NULL;
	return (words);
}

#include <stdio.h>

int	main(void)
{
	char	**kekw;
	int		i;

	kekw = ft_split_lst("oloco    bixo", ' ');
	i = 0;
	while (kekw[i])
	{
		printf("%s", kekw[i]);
		i++;
	}
	return (1);
}
