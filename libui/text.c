/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 22:27:48 by kmira             #+#    #+#             */
/*   Updated: 2019/09/15 19:35:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture	*get_text_layer(SDL_Renderer *renderer, char *text)
{
	SDL_Surface	*text_surface;
	SDL_Texture	*text_texture;
	SDL_Color	color;

	color.a = 0;
	color.r = 41;
	color.g = 46;
	color.b = 30;

	text_surface = TTF_RenderText_Blended(g_font, text, color);
	text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

	return (text_texture);
}

t_box	*text_common(t_window *window, char *text, int x, int y)
{
	t_box		*text_box;
	SDL_Texture	*text_texture;
	SDL_Rect	rect;
	t_rect		text_rect;

	text_rect.begin_y = 0;
	text_rect.begin_x = 0;
	text_texture = get_text_layer(window->renderer, text);
	SDL_QueryTexture(text_texture, NULL, NULL, &text_rect.end_x, &text_rect.end_y);
	text_box = common_element(NULL, text_rect, text_texture, window);
	text_box->state.draw_x = x;
	text_box->state.draw_y = y;
	text_box->state.name = text;

	(void)rect;
	return (text_box);
}

t_box	*install_text(t_box *parent, int top_padding, int left_padding, char *text)
{
	t_box	*text_box;

	text_box = text_common(parent->window,
				text,
				parent->state.draw_x + left_padding,
				parent->state.draw_y - top_padding);

	tree_append(parent, text_box);
	return (text_box);
}
