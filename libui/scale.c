/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 01:20:10 by kmira             #+#    #+#             */
/*   Updated: 2019/09/25 02:04:42 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** The children of each node need to be scaled a bit differently from the node passed in.
** this is because the children need to be moved aswell.
*/

void	scale_children(t_box *box, float scale_x, float scale_y)
{
	t_linker	*node;
	float		delta_x;
	float		delta_y;
	float		move_x;
	float		move_y;

	if (box == NULL)
		return ;

	printf("Testing\n");
	delta_x = box->rect.end_x - box->rect.begin_x;
	delta_y = box->rect.end_y - box->rect.begin_y;
	delta_x = delta_x * scale_x;
	delta_y = delta_y * scale_y;

	box->rect.end_x = box->rect.begin_x + (int)delta_x;
	box->rect.end_y = box->rect.begin_y + (int)delta_y;

	move_x =  box->state.draw_x - box->parent->state.draw_x;
	move_y =  box->state.draw_y - box->parent->state.draw_y;
	move_x = move_x * scale_x - (box->state.draw_x - box->parent->state.draw_x);
	move_y = move_y * scale_y - (box->state.draw_y - box->parent->state.draw_y);

	move_recursive(box, move_x, move_y);

	node = box->tree;
	while (node != NULL)
	{
		scale_children(node->data, scale_x, scale_y);
		node = node->next;
	}
}

void	scale_recursive(t_box *root, float scale_x, float scale_y)
{
	t_linker	*node;
	float		delta_x;
	float		delta_y;

	if (root == NULL)
		return ;

	printf("Testing\n");
	delta_x = root->rect.end_x - root->rect.begin_x;
	delta_y = root->rect.end_y - root->rect.begin_y;
	delta_x = delta_x * scale_x;
	delta_y = delta_y * scale_y;

	root->rect.end_x = root->rect.begin_x + (int)delta_x;
	root->rect.end_y = root->rect.begin_y + (int)delta_y;

	node = root->tree;
	while (node != NULL)
	{
		scale_children(node->data, scale_x, scale_y);
		node = node->next;
	}
}
