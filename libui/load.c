/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 00:37:14 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 00:37:29 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture		*load_image(const char *file_path, SDL_Renderer *renderer)
{
	SDL_Texture	*texture = IMG_LoadTexture(renderer, file_path);
	if (texture == NULL)
		printf(RED"Error in making the image to a texture! File: %s\n"COLOR_RESET, file_path);
	return (texture);
}
