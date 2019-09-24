/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hover.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 19:23:54 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 21:14:40 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture	*get_hover_layer(SDL_Renderer *renderer)
{
	SDL_Texture	*white_rect;

	white_rect = load_image("Resources/white_rectangle.png", renderer);
	return (white_rect);
}

t_box	*hover_element_common(t_box *parent, uint8_t red, uint8_t green, uint8_t blue)
{
	t_box		*hover_element;
	SDL_Texture *layer;
	t_rect		size;

	size.begin_x = 0;
	size.begin_y = 0;
	size.end_x = parent->rect.end_x;
	size.end_y = parent->rect.end_y;
	layer = get_hover_layer(parent->window->renderer);
	SDL_SetTextureColorMod(layer, red, green, blue);
	hover_element = common_element(parent,
									size,
									layer,
									parent->window);
	return (hover_element);
}

t_box	*install_hover(t_box *parent, uint8_t red, uint8_t green, uint8_t blue)
{
	t_box	*hover_element;

	hover_element = hover_element_common(parent, red, green, blue);
	hover_element->state.draw_x = parent->state.draw_x;
	hover_element->state.draw_y = parent->state.draw_y;
	hover_element->set_state = &state_display_on_hover;
	tree_append(parent, hover_element);
	return (hover_element);
}
