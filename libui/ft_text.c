/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_text.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:41:23 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:33:56 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture			*create_text_texture(char *text, SDL_Renderer *renderer)
{
	SDL_Surface	*text_surface;
	SDL_Texture	*text_texture;
	SDL_Color	color;

	color.r = 41;
	color.g = 46;
	color.b = 30;

	text_surface = TTF_RenderText_Blended(g_font, text, color);
	text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);

	return (text_texture);
}

t_gen_box	*init_textbox(t_gen_box *parent, char *text, SDL_Renderer *renderer, int x, int y)
{
	t_gen_box	*textbox;


	textbox = malloc(sizeof(*textbox) * (1));
	textbox->parent_state = parent;
	textbox->renderer = renderer;
	textbox->pos_x = x;
	textbox->pos_y = y;
	textbox->texture = create_text_texture(text, renderer);
	SDL_QueryTexture(textbox->texture, NULL, NULL,
					&textbox->width, &textbox->height);
	textbox->render_active = if_parent_is_active;
	textbox->read_state = common_read_state;
	textbox->self_state = malloc(sizeof(int) * 1);
	textbox->set_state = set_below_bar_state;
	textbox->events = parent->events;
	textbox->trie = NULL;

	return (textbox);
}
