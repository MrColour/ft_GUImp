/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 19:32:22 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 20:36:49 by kmira            ###   ########.fr       */
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
