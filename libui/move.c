/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:02:34 by kmira             #+#    #+#             */
/*   Updated: 2019/09/15 19:39:04 by kmira            ###   ########.fr       */
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

void	move_aboves(t_box *parent, t_box *child)
{
	move_recursive(child,
					parent->state.draw_x,
					parent->state.draw_y + get_height(parent->rect));
	tree_append(parent, child);
}

void	move_below(t_box *parent, t_box *child)
{
	move_recursive(child,
					parent->state.draw_x,
					parent->state.draw_y - get_height(parent->rect));
	tree_append(parent, child);
}

void	move_left(t_box *parent, t_box *child)
{
	move_recursive(child,
					parent->state.draw_x - get_width(parent->rect),
					parent->state.draw_y);
	tree_append(parent, child);
}

void	move_right(t_box *parent, t_box *child)
{
	move_recursive(child,
					parent->state.draw_x + get_width(parent->rect),
					parent->state.draw_y);
	tree_append(parent, child);
}
