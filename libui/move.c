/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:02:34 by kmira             #+#    #+#             */
/*   Updated: 2019/09/25 01:17:41 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	move_rectangle(t_rect *rectangle, int x, int y)
{
	rectangle->begin_x = rectangle->begin_x + x;
	rectangle->begin_y = rectangle->begin_y + y;

	rectangle->end_x = rectangle->end_x + x;
	rectangle->end_y = rectangle->end_y + y;
}

void	move_recursive(t_box *box, int amount_right, int amount_down)
{
	t_linker	*node;

	if (box == NULL)
		return ;
	box->state.draw_x = box->state.draw_x + amount_right;
	box->state.draw_y = box->state.draw_y + amount_down;
	node = box->tree;
	while (node != NULL)
	{
		move_recursive(node->data, amount_right, amount_down);
		node = node->next;
	}
}

void	move_option(t_box *parent, t_box *child, int option)
{
	int delta_x;
	int delta_y;

	delta_x = 0;
	delta_y = 0;
	if (option & MOVE_UP)
		delta_y = get_height(parent->rect);
	else if (option & MOVE_DOWN)
		delta_y = -1 * get_height(parent->rect);
	if (option & MOVE_RIGHT)
		delta_x = get_width(parent->rect);
	else if (option & MOVE_LEFT)
		delta_x = -1 * get_width(parent->rect);

	move_recursive(child,
					parent->state.draw_x + delta_x,
					parent->state.draw_y + delta_y);
	tree_append_parent(parent, child);
}

