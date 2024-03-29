/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:20:09 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 22:20:04 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	render_tree(t_box *box)
{
	t_linker *node;

	if (box == NULL)
		return ;
	// printf("Rendering box\n");
	node = box->tree;
	if (box->state.standard & (DISPLAY_ON | PASSIVE_ACTIVE))
		draw_box(box);
	while (node != NULL)
	{
		// printf("Rendering child\n");
		render_tree(node->data);
		node = node->next;
	}
}

void	set_tree(t_box *box)
{
	t_linker *node;

	if (box == NULL)
		return ;
	// printf("Setting the state of the box\n");
	// printf("Setting: %s\n", box->state.name);
	node = box->tree;
	if (box->set_state != NULL)
		box->set_state(box);
	while (node != NULL)
	{
		// printf("Rendering child\n");
		set_tree(node->data);
		node = node->next;
	}
}

void	execute_tree(t_box *box)
{
	t_linker *node;

	if (box == NULL)
		return ;
	// printf("Rendering box\n");
	node = box->tree;
	if (box->clicked != NULL)
		box->clicked(box);
	while (node != NULL)
	{
		// printf("Rendering child\n");
		execute_tree(node->data);
		node = node->next;
	}
}

int		find_tree(t_box *box, t_activity search, int depth, int current_depth)
{
	t_linker	*node;
	int			result;

	if (current_depth > depth)
		return (0);

	result = 0;
	if (box != NULL)
	{
		node = box->tree;
		while (node != NULL)
		{
			if ((node->data->state.standard & search) != 0 || result == 1)
				return (1);
			result = find_tree(node->data, search, depth, current_depth + 1);
			node = node->next;
		}
	}
	return (result);
}

/*
** Returns 1 if the given state is found within the first 'depth' layers
** with the box as the starting point
*/

int		state_in_tree(t_box *box, t_activity search_state, int depth)
{
	int result;

	result = find_tree(box, search_state, depth, 0);
	return (result);
}

void	master_reccursive_call(t_box *root)
{
	set_tree(root);
	execute_tree(root);
	render_tree(root);
}
