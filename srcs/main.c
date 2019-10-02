/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:04:45 by kmira             #+#    #+#             */
/*   Updated: 2019/09/25 02:07:55 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

int		main(void)
{
	t_window		window;
	SDL_Window		*back_window;
	SDL_Event		events;
	int				quit;
	int				stop;

	bzero(&window.events, sizeof(window.events));
	back_window = create_default_window(WIN_WIDTH, WIN_HEIGHT);
	window.renderer = SDL_CreateRenderer(back_window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);
	window.rect = main_window(WINDOW_WIDTH, WINDOW_HEIGHT);
	SDL_SetRenderDrawColor(window.renderer, 100, 100, 100, 255);

	// Clear the entire screen to our selected color.
	SDL_RenderClear(window.renderer);


	t_box	*program    __attribute__((unused)) = bar_default(&window, "GIMP", 0, WINDOW_HEIGHT);
	program->set_state = top_item;

	t_box	*bar2    __attribute__((unused)) = bar_hover_on_option(program, "Preferences", MOVE_DOWN);
	t_box	*bar1    __attribute__((unused)) = bar_hover_on_option(bar2, "About", MOVE_DOWN);

	t_box	*barA1    __attribute__((unused)) = bar_on_option(bar1, "Right", MOVE_RIGHT);
	tree_remove(program, barA1);
	barA1->parent = bar1;
	tree_append(bar1, barA1);
	t_box	*barA2    __attribute__((unused)) = bar_hover_on_option(barA1, "Right 1", MOVE_DOWN);
	tree_remove(program, barA2);
	barA2->parent = barA1;
	tree_append(barA1, barA2);

	t_box	*file    __attribute__((unused)) = bar_default(&window, "File", BAR_WIDTH, WINDOW_HEIGHT);
	file->set_state = top_item;
	t_box	*barf1    __attribute__((unused)) = bar_hover_on_option(file,  "New File", MOVE_DOWN);
	t_box	*barf2    __attribute__((unused)) = bar_hover_on_option(barf1, "Open", MOVE_DOWN);
	t_box	*barf3    __attribute__((unused)) = bar_hover_on_option(barf2, "Save", MOVE_DOWN);
	t_box	*barf4    __attribute__((unused)) = bar_hover_on_option(barf3, "Save As", MOVE_DOWN);

	move_recursive(barf4, 100, BAR_HEIGHT * 4);
	scale_recursive(barf4, 4, 4);

	t_box	*edit    __attribute__((unused)) = bar_default(&window, "Edit", BAR_WIDTH * 2, WINDOW_HEIGHT);
	edit->set_state = top_item;
	t_box	*bare1    __attribute__((unused)) = bar_hover_on_option(edit,  "Undo", MOVE_DOWN);
	t_box	*bare2    __attribute__((unused)) = bar_hover_on_option(bare1, "Redo", MOVE_DOWN);
	t_box	*bare3    __attribute__((unused)) = bar_hover_on_option(bare2, "Cut", MOVE_DOWN);
	t_box	*bare4    __attribute__((unused)) = bar_hover_on_option(bare3, "Copy", MOVE_DOWN);
	t_box	*bare5    __attribute__((unused)) = bar_hover_on_option(bare4, "Paste", MOVE_DOWN);

	quit = 0;
	stop = 50;
	while (quit == 0 && stop != 0)
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
			else if (events.type == SDL_MOUSEMOTION)
				SDL_GetMouseState(&window.events.mouse_pos_x, &window.events.mouse_pos_y);
			else if (events.type == SDL_MOUSEBUTTONDOWN)
				window.events.left_click = 1;
			else if (events.type == SDL_MOUSEBUTTONUP)
				window.events.left_click = 0;
		}
		master_reccursive_call(program);
		master_reccursive_call(edit);
		master_reccursive_call(file);
		SDL_RenderPresent(window.renderer);
		SDL_Delay(90);
		// stop--;
	}
	return (0);
}
