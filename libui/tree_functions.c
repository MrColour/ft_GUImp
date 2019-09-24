/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:32:22 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 16:33:46 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	tree_append(t_box *parent, t_box *child)
{
	t_linker	*node;

	if (parent->tree == NULL)
	{
		parent->tree = malloc(sizeof(parent->tree) * (1));
		parent->tree->data = child;
		parent->tree->next = NULL;
		return ;
	}
	node = parent->tree;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(parent->tree) * (1));
	node->next->data = child;
	node->next->next = NULL;
}

void	tree_append_parent(t_box *parent, t_box *child)
{
	t_linker	*node;

	if (parent->tree == NULL)
	{
		return ;
	}
	if (parent->parent == NULL)
		node = parent->tree;
	else
		node = parent->parent->tree;
	while (node->next != NULL)
		node = node->next;
	node->next = malloc(sizeof(parent->parent->tree) * (1));
	node->next->data = child;
	node->next->next = NULL;
}

void	tree_remove(t_box *parent, t_box *child)
{
	t_linker	*node;
	t_linker	*previous;

	if (parent == NULL || child == NULL)
		return ;
	node = parent->tree;
	previous = NULL;
	while (node != NULL)
	{
		if (node->data == child)
		{
			if (previous != NULL)
				previous->next = node->next;
			else
				parent->tree = NULL;
			free(node);
		}
		previous = node;
		node = node->next;
	}
}

void	tree_list(t_box *parent)
{
	t_linker	*node;
	int			i;

	i = 0;
	node = parent->tree;
	printf(MAGENTA"PARENT: %p\n"COLOR_RESET, parent);
	while (node != NULL)
	{
		printf(BLUE"CHILD %d: %p\n"COLOR_RESET, i, node->data);
		node = node->next;
		i++;
	}
}
