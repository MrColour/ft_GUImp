/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_texture.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 21:08:43 by kmira             #+#    #+#             */
/*   Updated: 2019/09/10 21:09:10 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	render_texture_native(SDL_Texture *texture, SDL_Renderer *rend, int x, int y)
{
	SDL_Rect	dst;

	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	SDL_RenderCopy(rend, texture, NULL, &dst);
}

void	render_texture_scale(SDL_Texture *texture, SDL_Renderer *rend, int x, int y, float scale)
{
	SDL_Rect	dst;

	dst.x = x;
	dst.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
	dst.w = dst.w * scale;
	dst.h = dst.h * scale;

	SDL_RenderCopy(rend, texture, NULL, &dst);
}

void	render_texture(SDL_Texture *texture, SDL_Renderer *rend, int x, int y, int width, int height)
{
	SDL_Rect	dst;

	dst.x = x;
	dst.y = y;
	dst.w = width;
	dst.h = height;
	SDL_RenderCopy(rend, texture, NULL, &dst);
}
