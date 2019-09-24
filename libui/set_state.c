/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:21:29 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 21:40:15 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** Need a toogle for the menu bar
*/

void	top_item(t_box *self)
{
	self->state.standard |= DISPLAY_ON;

	if (is_within(	self->window->events.mouse_pos_x,
					self->window->events.mouse_pos_y,
					self->rect,
					self->state.draw_x,
					self->state.draw_y) == 1)
		self->state.standard |= MOUSE_HOVER | BOX_ACTIVE;
	else
		self->state.standard &= ~(MOUSE_HOVER | BOX_ACTIVE);

	t_linker	*node;
	int			re;

	re = 0;
	node = self->tree;
	while (node != NULL)
	{
		if ((is_within(	self->window->events.mouse_pos_x,
						self->window->events.mouse_pos_y,
						node->data->rect,
						node->data->state.draw_x,
						node->data->state.draw_y) == 1 &&
						node->data->state.standard & DISPLAY_ON) ||
						node->data->state.standard & PASSIVE_ACTIVE)
		{
			re = 1;
			break ;
		}
		node = node->next;
	}
	if (re == 1)
		self->state.standard |= PASSIVE_ACTIVE;
	else
		self->state.standard &= ~(PASSIVE_ACTIVE);
}

void	common_set_state(t_box *self)
{
	t_box *parent;
	t_state	state_copy;

	parent = self->parent;
	state_copy = self->state;

	if (parent->state.standard & (PASSIVE_ACTIVE | MOUSE_HOVER))
		self->state.standard |= DISPLAY_ON;

	if (is_within(	self->window->events.mouse_pos_x,
					self->window->events.mouse_pos_y,
					self->rect,
					self->state.draw_x,
					self->state.draw_y) == 1 &&
					self->state.standard & DISPLAY_ON)
	{
		self->state.standard |= MOUSE_HOVER | BOX_ACTIVE | DISPLAY_ON;
		parent->state.standard |= PASSIVE_ACTIVE;
	}
	else
		self->state.standard &= ~(MOUSE_HOVER | BOX_ACTIVE);

	if ((parent->state.standard & (PASSIVE_ACTIVE | MOUSE_HOVER)) == 0)
		self->state.standard &= ~DISPLAY_ON;

	t_linker	*node;
	int			re;

	re = 0;
	node = self->tree;
	while (node != NULL)
	{
		if (is_within(	self->window->events.mouse_pos_x,
						self->window->events.mouse_pos_y,
						node->data->rect,
						node->data->state.draw_x,
						node->data->state.draw_y) == 1 &&
						node->data->state.standard & DISPLAY_ON)
		{
			re = 1;
			break ;
		}
		node = node->next;
	}
	if (re == 1)
		self->state.standard |= PASSIVE_ACTIVE;
	else
		self->state.standard &= ~(PASSIVE_ACTIVE);
}

void	state_copy_parent(t_box *self)
{
	t_box *parent;

	if (self->parent != NULL)
	{
		parent = self->parent;
		if (parent->state.standard & (DISPLAY_ON | PASSIVE_ACTIVE))
			self->state.standard |= DISPLAY_ON;
		else
			self->state.standard &= ~DISPLAY_ON;
	}
}

void	state_display_on_hover(t_box *self)
{
	t_box *parent;

	if (self->parent != NULL)
	{
		parent = self->parent;
		if (parent->state.standard & (MOUSE_HOVER | PASSIVE_ACTIVE))
			self->state.standard |= DISPLAY_ON;
		else
			self->state.standard &= ~DISPLAY_ON;
	}
}
