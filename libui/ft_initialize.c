/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:38:25 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:28:48 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

SDL_Window		*create_default_window(int win_width, int win_height)
{
	SDL_Window *resulting_window;

	resulting_window = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf(RED"There was an error initializing the window!\n"COLOR_RESET);
	if( TTF_Init() == -1)
		printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
	resulting_window = SDL_CreateWindow("Lesson 2!", 100, 100, win_width, win_height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (resulting_window == NULL)
	{
		printf(RED"There was an error creating the window!\n"COLOR_RESET);
		SDL_Quit();
	}
	g_font = init_font("Resources/Fonts/Roboto-Regular.ttf", DEFAULT_FONT_SIZE);
	return (resulting_window);
}
