/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:44:50 by kmira             #+#    #+#             */
/*   Updated: 2019/09/15 19:33:42 by kmira            ###   ########.fr       */
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

t_box	*bar_common(t_window *window, char *text)
{
	t_box	*bar_top;
	t_box	*border;
	t_box	*text_box;

	bar_top = common_element(NULL, get_bar_rectangle(), get_bar_layer(window->renderer), window);
	bar_top->state.standard = bar_top->state.standard | DISPLAY_ON;
	bar_top->state.name = strdup("BAR");


	border = install_border(bar_top);
	border->state.standard = border->state.standard | DISPLAY_ON;

	text_box = install_text(bar_top, 0, 5, text);
	text_box->state.standard = text_box->state.standard | DISPLAY_ON;

	return (bar_top);
}

t_box	*bar_default(t_window *window, char *text, int x, int y)
{
	t_box	*bar;

	bar = bar_common(window, text);
	move_recursive(bar, x, y);

	return (bar);
}

t_box	*bar_below(t_box *parent, char *text)
{
	t_box	*bar_below;

	bar_below = bar_common(parent->window, text);
	move_below(parent, bar_below);

	return (bar_below);
}

