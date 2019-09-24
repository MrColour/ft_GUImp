/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bar.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:44:50 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 21:16:12 by kmira            ###   ########.fr       */
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
	t_box	*bar;
	t_box	*border;
	t_box	*text_box;

	bar = common_element(NULL, get_bar_rectangle(), get_bar_layer(window->renderer), window);
	bar->state.name = strdup(text);

	border = install_border(bar);
	border->set_state = &state_copy_parent;

	text_box = install_text(bar, 0, 5, text);
	text_box->set_state = &state_copy_parent;

	return (bar);
}

t_box	*bar_hover(t_window *window, char *text)
{
	t_box	*bar;
	t_box	*border;
	t_box	*text_box;
	t_box	*hover_element;

	bar = common_element(NULL, get_bar_rectangle(), get_bar_layer(window->renderer), window);
	bar->state.name = strdup(text);

	hover_element = install_hover(bar, 225, 50, 190);

	border = install_border(bar);
	border->set_state = &state_copy_parent;

	text_box = install_text(bar, 0, 5, text);
	text_box->set_state = &state_copy_parent;

	return (bar);
}

t_box	*bar_default(t_window *window, char *text, int x, int y)
{
	t_box	*bar;

	bar = bar_common(window, text);
	move_recursive(bar, x, y);

	return (bar);
}

t_box	*bar_on_option(t_box *parent, char *text, int option)
{
	t_box	*bar_below;

	bar_below = bar_common(parent->window, text);
	move_option(parent, bar_below, option);
	if (parent->parent == NULL)
		bar_below->parent = parent;
	else
		bar_below->parent = parent->parent;
	bar_below->set_state = &common_set_state;

	return (bar_below);
}

t_box	*bar_hover_on_option(t_box *parent, char *text, int option)
{
	t_box	*bar_below;

	bar_below = bar_hover(parent->window, text);
	move_option(parent, bar_below, option);
	if (parent->parent == NULL)
		bar_below->parent = parent;
	else
		bar_below->parent = parent->parent;
	bar_below->set_state = &common_set_state;

	return (bar_below);
}
