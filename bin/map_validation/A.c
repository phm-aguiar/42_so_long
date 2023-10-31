/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phenriq2 <phenriq2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:51:16 by phenriq2          #+#    #+#             */
/*   Updated: 2023/10/31 20:37:51 by phenriq2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	insertOpenList(t_open_list_node **openList, t_node *node, int f)
{
	t_open_list_node	*newNode;

	newNode = malloc(sizeof(t_open_list_node));
	newNode->node = node;
	newNode->f = f;
	newNode->next = *openList;
	*openList = newNode;
}

t_node	*removeMinFromOpenList(t_open_list_node **openList)
{
	t_open_list_node	*current;
	t_open_list_node	*prev;
	t_open_list_node	*minNode;
	int					minF;
	t_node				*minNodeData;

	if (*openList == NULL)
		return (NULL);
	current = *openList;
	prev = NULL;
	minNode = *openList;
	minF = (*openList)->f;
	while (current != NULL)
	{
		if (current->f < minF)
		{
			minF = current->f;
			minNode = current;
			prev = prev;
		}
		prev = current;
		current = current->next;
	}
	if (prev != NULL)
		prev->next = minNode->next;
	else
		*openList = minNode->next;
	minNodeData = minNode->node;
	free(minNode);
	return (minNodeData);
}

void	insertClosedList(t_closed_list_node **closedList, t_node *node)
{
	t_closed_list_node	*newNode;

	newNode = malloc(sizeof(t_closed_list_node));
	newNode->node = node;
	newNode->next = *closedList;
	*closedList = newNode;
}

int	isInClosedList(t_closed_list_node *closedList, t_node *node)
{
	t_closed_list_node	*current;

	current = closedList;
	while (current != NULL)
	{
		if (current->node == node)
			return (1);
		current = current->next;
	}
	return (0);
}

void	set_g(t_sl *sl)
{
	sl->vars.i = 0;
	while (sl->vars.i < sl->map_file.height)
	{
		sl->vars.j = 0;
		while (sl->vars.j < sl->map_file.width)
		{
			if (sl->graph[sl->vars.i][sl->vars.j].type == 'C')
				sl->graph[sl->vars.i][sl->vars.j].g = 1;
			if (sl->graph[sl->vars.i][sl->vars.j].type == '1')
				sl->graph[sl->vars.i][sl->vars.j].g = INT_MAX;
			if (sl->graph[sl->vars.i][sl->vars.j].type == 'E')
				sl->graph[sl->vars.i][sl->vars.j].g = 1;
			if (sl->graph[sl->vars.i][sl->vars.j].type == 'P')
				sl->graph[sl->vars.i][sl->vars.j].g = 1;
			if (sl->graph[sl->vars.i][sl->vars.j].type == '0')
				sl->graph[sl->vars.i][sl->vars.j].g = 0;
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

void	start_end(t_sl *sl)
{
	sl->vars.i = 0;
	while (sl->vars.i < sl->map_file.height)
	{
		sl->vars.j = 0;
		while (sl->vars.j < sl->map_file.width)
		{
			if (sl->graph[sl->vars.i][sl->vars.j].type == 'P')
			{
				sl->vars.start_x = sl->graph[sl->vars.i][sl->vars.j].x;
				sl->vars.start_y = sl->graph[sl->vars.i][sl->vars.j].y;
			}
			if (sl->graph[sl->vars.i][sl->vars.j].type == 'E')
			{
				sl->vars.end_x = sl->graph[sl->vars.i][sl->vars.j].x;
				sl->vars.end_y = sl->graph[sl->vars.i][sl->vars.j].y;
			}
			sl->vars.j++;
		}
		sl->vars.i++;
	}
}

void	createNodes(char **map, int height, int width, t_sl *sl)
{
	sl->graph = malloc(height * sizeof(t_node *));
	sl->vars.i = 0;
	while (sl->vars.i < height)
	{
		sl->graph[sl->vars.i] = malloc(width * sizeof(t_node));
		sl->vars.j = 0;
		while (sl->vars.j < width)
		{
			sl->graph[sl->vars.i][sl->vars.j].type = map[sl->vars.i][sl->vars.j];
			sl->graph[sl->vars.i][sl->vars.j].g = 0;
			sl->graph[sl->vars.i][sl->vars.j].h = 0;
			sl->graph[sl->vars.i][sl->vars.j].f = 0;
			sl->graph[sl->vars.i][sl->vars.j].parent = NULL;
			sl->graph[sl->vars.i][sl->vars.j].x = sl->vars.i;
			sl->graph[sl->vars.i][sl->vars.j].y = sl->vars.j;
			sl->vars.j++;
		}
		sl->vars.i++;
	}
	start_end(sl);
	set_g(sl);
}
