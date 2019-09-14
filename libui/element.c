/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:23:11 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 00:43:15 by kmira            ###   ########.fr       */
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
