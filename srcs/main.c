/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:04:45 by kmira             #+#    #+#             */
/*   Updated: 2019/09/15 19:59:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int		main(void)
{
	t_window		window;
	SDL_Window		*back_window;
	SDL_Event		events;
	int	quit;

	back_window = create_default_window(WIN_WIDTH, WIN_HEIGHT);
	window.renderer = SDL_CreateRenderer(back_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	window.rect = main_window(WINDOW_WIDTH, WINDOW_HEIGHT);

	t_box	*bar;
	t_box	*bar1;
	t_box	*bar2;

	bar = bar_default(&window, "Something", 0, WINDOW_HEIGHT);
	bar1 = bar_below(bar, "test");
	bar2 = bar_right(bar1, "YOOT");

	quit = 0;
	while (quit == 0)
	{
		SDL_RenderClear(window.renderer);
		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_QUIT)
				quit = TRUE;
			else if (events.type == SDL_KEYDOWN)
			{
				if (events.key.keysym.scancode == SDL_SCANCODE_Q)
					quit = TRUE;
			}
			// else if (events.type == SDL_MOUSEMOTION)
				// SDL_GetMouseState(&ui_state.mouse_pos_x, &ui_state.mouse_pos_y);
		}
		render_tree(bar);
		SDL_RenderPresent(window.renderer);
		SDL_Delay(90);
	}
	return (0);
}
