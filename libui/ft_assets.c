/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assets.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 23:34:57 by kmira             #+#    #+#             */
/*   Updated: 2019/09/10 23:35:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Texture		*ft_get_bar(SDL_Renderer *renderer)
{
	static SDL_Texture	*bar;

	if (bar == 0)
		bar = load_image("Resources/Border.png", renderer);
	return (bar);
}

SDL_Texture		*ft_get_divider(SDL_Renderer *renderer)
{
	static SDL_Texture	*divider;

	if (divider == 0)
		divider = load_image("Resources/Divider.png", renderer);
	return (divider);
}
