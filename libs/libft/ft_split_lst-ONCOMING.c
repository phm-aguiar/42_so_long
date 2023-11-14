/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_lst-ONCOMING.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 11:57:25 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/26 15:21:14 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_subs(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] != c && s[i])
		count++;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	return (count);
}

char	**split_lst(const char *s, char c)
{
	t_gnl	*lst;
	char	**strs;
	int		i;
	int		counter;

	lst = NULL;
	i = ft_count_subs(s, c);
	strs = (char **)malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	while (*s == c)
		s++;
	ft_split_char(s, &lst);
	while ()
	{
		/* code */
	}
	
	counter = ft_sizelst(&lst, '\n');
	strs[i] = NULL;
	if (!s)
		return (NULL);
	while (*s == c)
		s++;
}
