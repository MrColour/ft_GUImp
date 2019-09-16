/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:23:11 by kmira             #+#    #+#             */
/*   Updated: 2019/09/15 19:37:31 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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

	result->fetch_state = NULL;

	return (result);
}

t_box	*common_element_below(t_box *parent, t_rect rect, SDL_Texture *layer)
{
	t_box *result;

	result = common_element(parent, rect, layer, parent->window);
	move_below(parent, result);

	return (result);
}

t_box	*common_element_right(t_box *parent, t_rect rect, SDL_Texture *layer)
{
	t_box *result;

	result = common_element(parent, rect, layer, parent->window);
	result->state.draw_x = parent->state.draw_x + get_width(parent->rect);
	result->state.draw_y = parent->state.draw_y;

	tree_append(parent, result);

	return (result);
}
