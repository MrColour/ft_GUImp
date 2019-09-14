/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:44:50 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 00:57:19 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_rect		get_bar_rectangle(void)
{
	static t_rect	bar_rectangle;

	bar_rectangle.begin_x = 0;
	bar_rectangle.begin_y = 0;
	bar_rectangle.end_x = BAR_WIDTH;
	bar_rectangle.end_y = BAR_HEIGHT;
	return (bar_rectangle);
}

SDL_Texture	*get_bar_layer(SDL_Renderer *renderer)
{
	static SDL_Texture		*layer;

	if (layer == NULL)
		layer = load_image("Resources/Border.png", renderer);
	return (layer);
}
