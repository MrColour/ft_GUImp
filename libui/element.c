/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:23:11 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 22:28:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	print_name(t_box *self)
{
	if (self->state.standard & MOUSE_HOVER &&
		self->window->events.left_click &&
		is_within(	self->window->events.mouse_pos_x,
					self->window->events.mouse_pos_y,
					self->rect,
					self->state.draw_x,
					self->state.draw_y) == 1)
	{
		printf(CYAN"Congratz you just clicked "COLOR_RESET"%s\n", self->state.name);
	}
}

t_box	*common_element(t_box *parent, t_rect rect, SDL_Texture *layer, t_window *window)
{
	t_box *result;

	result = malloc(sizeof(*result) * (1));
	ft_bzero(result, sizeof(*result));

	result->window = window;
	result->rect = rect;
	ft_bzero(&result->state, sizeof(result->state));
	result->layer = layer;

	result->parent = parent;
	result->tree = NULL;

	result->set_state = NULL;
	result->child_requirement = NULL;
	result->parent_requirment = NULL;
	result->clicked = &print_name;

	result->fetch_state = NULL;
	result->state.name = strdup(BLUE"Unassigned"COLOR_RESET);

	return (result);
}
