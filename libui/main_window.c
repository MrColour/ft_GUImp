/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 00:38:25 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 19:38:30 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_rect			main_window(int window_width, int window_height)
{
	t_rect	result;

	result.begin_x = 0;
	result.begin_y = 0;
	result.end_x = window_width;
	result.end_y = window_height;
	return (result);
}

SDL_Window		*create_default_window(int win_width, int win_height)
{
	SDL_Window *window;

	window = NULL;
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		printf(RED"There was an error initializing the window!\n"COLOR_RESET);
	if (TTF_Init() == -1)
		printf("SDL_ttf could not init! SDL_ttf Error: %s\n", TTF_GetError());
	window = SDL_CreateWindow("Lesson 2!",
								100,
								100,
								win_width,
								win_height,
								SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	if (window == NULL)
	{
		printf(RED"There was an error creating the window!\n"COLOR_RESET);
		SDL_Quit();
	}
	g_font = NULL;
	g_font = init_font("Resources/Fonts/Roboto-Regular.ttf", DEFAULT_FONT_SIZE);
	return (window);
}
