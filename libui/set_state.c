/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:21:29 by kmira             #+#    #+#             */
/*   Updated: 2019/09/18 22:49:09 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

/*
** Need a toogle for the menu bar
*/

void	common_set_state(t_box *self)
{
	t_box *parent;
	t_state	state_copy;

	parent = self->parent;
	state_copy = self->state;

	if (parent->state.standard & (MOUSE_HOVER | PASSIVE_ACTIVE))
		self->state.standard |= DISPLAY_ON;

	if (is_within(	self->window->events.mouse_pos_x,
					self->window->events.mouse_pos_y,
					self->rect,
					self->state.draw_x,
					self->state.draw_y) == 1 &&
					self->state.standard & DISPLAY_ON)
	{
		printf(MAGENTA"First child bar is hovered\n"COLOR_RESET);
		self->state.standard |= MOUSE_HOVER | BOX_ACTIVE | DISPLAY_ON;
		parent->state.standard |= PASSIVE_ACTIVE;
	}
	else
	{
		self->state.standard &= ~(MOUSE_HOVER | BOX_ACTIVE);
		// parent->set_state(parent);
		parent->state.standard &= ~PASSIVE_ACTIVE;
	}

	if (self->state.standard & ~MOUSE_HOVER && (parent->state.standard & (MOUSE_HOVER | PASSIVE_ACTIVE)) == 0)
		self->state.standard &= ~DISPLAY_ON;

	// if ((parent->state.standard & (MOUSE_HOVER | PASSIVE_ACTIVE)) == 0)
	// 	self->state.standard = self->state.standard & ~DISPLAY_ON;

	// else
	// {
	// 	self->state.standard = 0;
	// }
	// if (parent != NULL)
	// {
	// 	if (parent->state.standard & BOX_ACTIVE)
	// 		self->state.standard = self->state.standard | DISPLAY_ON;
	// 	if (parent->state.standard & PASSIVE_ACTIVE)
	// 		self->state.standard = self->state.standard | DISPLAY_ON;
	// }
	// self->state.standard = parent->state.standard;
}

void	state_copy_parent(t_box *self)
{
	t_box *parent;

	if (self->parent != NULL)
	{
		parent = self->parent;
		if (parent->state.standard & DISPLAY_ON)
			self->state.standard |= DISPLAY_ON;
		else
			self->state.standard &= ~DISPLAY_ON;
	}
}

