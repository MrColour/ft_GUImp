/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:23:13 by kmira             #+#    #+#             */
/*   Updated: 2019/09/18 23:26:33 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

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
	dst.h = get_height(box->rect);
	dst.w = get_width(box->rect);
	SDL_RenderCopy(box->window->renderer, box->layer, NULL, &dst);
}
