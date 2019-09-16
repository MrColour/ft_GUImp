/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 20:47:28 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 22:27:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_rect		get_border_rectangle(void)
{
	static t_rect	border_rectangle;

	border_rectangle.begin_x = 0;
	border_rectangle.begin_y = 0;
	border_rectangle.end_x = BORDER_WIDTH;
	border_rectangle.end_y = BORDER_HEIGHT;
	return (border_rectangle);
}

SDL_Texture	*get_border_layer(SDL_Renderer *renderer)
{
	static SDL_Texture		*layer;

	if (layer == NULL)
		layer = load_image("Resources/Divider.png", renderer);
	return (layer);
}

t_box		*install_border(t_box *parent)
{
	t_box	*border;

	border = common_element(parent,
							get_border_rectangle(),
							get_border_layer(parent->window->renderer),
							parent->window);
	border->state.draw_x = parent->state.draw_x;
	border->state.draw_y = parent->state.draw_y - (get_height(parent->rect) - BORDER_HEIGHT);

	tree_append(parent, border);

	return (border);
}
