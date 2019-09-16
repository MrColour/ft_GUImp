/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:23:13 by kmira             #+#    #+#             */
/*   Updated: 2019/09/15 17:05:52 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

// void	draw_texture_native(SDL_Texture *texture, SDL_Renderer *rend, int x, int y)
// {
// 	SDL_Rect	dst;

// 	dst.x = x;
// 	dst.y = y;
// 	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
// 	SDL_RenderCopy(rend, texture, NULL, &dst);
// }

// void	draw_texture_scale(SDL_Texture *texture, SDL_Renderer *rend, int x, int y, float scale)
// {
// 	SDL_Rect	dst;

// 	dst.x = x;
// 	dst.y = y;
// 	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
// 	dst.w = dst.w * scale;
// 	dst.h = dst.h * scale;

// 	SDL_RenderCopy(rend, texture, NULL, &dst);
// }

// void	draw_texture(SDL_Texture *texture, SDL_Renderer *rend, int x, int y, int width, int height)
// {
// 	SDL_Rect	dst;

// 	dst.x = x;
// 	dst.y = y;
// 	dst.w = width;
// 	dst.h = height;
// 	SDL_RenderCopy(rend, texture, NULL, &dst);
// }

void	draw_box(t_box *box)
{
	SDL_Rect	dst;

	if (box->layer == NULL)
	{
		printf("This containter does not have a texture.\n");
		return ;
	}
	dst.x = box->state.draw_x;
	dst.y = get_height(box->window->rect) - box->state.draw_y;
	// printf("Window is %d and box is (%d, %d)\n", get_height(box->window->rect), box->state.draw_x, box->state.draw_y);
	// printf("NAME: %s\n", box->state.name);
	// printf("Window is %d and box is (%d, %d)\n", get_height(box->window->rect), dst.x, dst.y);
	dst.h = get_height(box->rect);
	dst.w = get_width(box->rect);
	SDL_RenderCopy(box->window->renderer, box->layer, NULL, &dst);

	// printf("Your thingy was drawn\n");
}
