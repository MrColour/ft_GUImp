/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:32:22 by kmira             #+#    #+#             */
/*   Updated: 2019/09/18 02:34:27 by kmira            ###   ########.fr       */
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
