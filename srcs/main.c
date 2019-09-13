/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:04:45 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:31:02 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "guimp.h"

#define RUN_TIME 800

void	recursive_renderering(t_gen_box *container)
{
	t_linker	*node;

	if (container == NULL)
		return ;
	node = container->trie;
	if (container->render_active(container->parent_state,
								container->self_state,
								container->events) == 1)
	{
		render_texture(
			container->texture,
			container->renderer,
			container->pos_x,
			container->pos_y,
			container->width,
			container->height);
	}
	while (node != NULL)
	{
		recursive_renderering(node->data);
		node = node->next;
	}
}

void	recursive_set_state(t_gen_box *container)
{
	t_linker	*node;

	if (container == NULL)
		return ;
	node = container->trie;
	container->set_state(container->parent_state, container, container->events);
	while (node != NULL)
	{
		recursive_set_state(node->data);
		node = node->next;
	}
}

int		main(void)
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		events;
	int				quit;
	int				i;

	t_events	ui_state;

	window = create_default_window(WIN_WIDTH, WIN_HEIGHT);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_TARGETTEXTURE);

	t_gen_box	*top_bar;
	t_gen_box	*top1_bar;
	t_gen_box	*bar2;
	// t_gen_box	*bar3;
	// t_gen_box	*bar4;
	// t_gen_box	*bar5;
	// t_gen_box	*bar6;
	t_gen_box	*bar17;
	t_gen_box	*bar18;
	t_gen_box	*bar19;
	top_bar = init_bar_top("Text_00", renderer, 0, 0, &ui_state);
	bar2 = init_bar_below(top_bar, "Text_01", &ui_state);
	// bar3 = init_bar_below(bar2, "Text_02", &ui_state);
	// bar4 = init_bar_below(bar3, "Text_03", &ui_state);
	// bar5 = init_bar_below(bar4, "Text_04", &ui_state);
	// bar6 = init_bar_below(bar5, "Text_05", &ui_state);
	top1_bar = init_bar_right(top_bar, "Text_10" ,&ui_state);
	printf("Parent should be: %p\n", top1_bar);
	bar17 = init_bar_below(top1_bar, "Text_11", &ui_state);
	bar18 = init_bar_below(bar17, "Text_12", &ui_state);
	bar19 = init_bar_below(bar18, "Text_13", &ui_state);

	// t_gen_box	*top2_bar;
	// t_gen_box	*bar22;
	// t_gen_box	*bar23;
	// t_gen_box	*bar24;
	// t_gen_box	*bar25;
	// top2_bar = init_bar_top("Text_00", renderer, 200, 100, &ui_state);
	// bar22 = init_bar_below(top2_bar, "Text_01", &ui_state);
	// bar23 = init_bar_below(bar22, "Text_02", &ui_state);
	// bar24 = init_bar_below(bar23, "Text_03", &ui_state);
	// bar25 = init_bar_below(bar24, "Text_04", &ui_state);

	i = 0;
	quit = 0;
	while (quit == 0)
	{
		SDL_RenderClear(renderer);
		while (SDL_PollEvent(&events))
		{
			if (events.type == SDL_QUIT)
				quit = TRUE;
			if (events.type == SDL_KEYDOWN)
				if (events.key.keysym.scancode == SDL_SCANCODE_Q)
					quit = TRUE;
			if (events.type == SDL_MOUSEMOTION)
			{
				SDL_GetMouseState(&ui_state.mouse_pos_x, &ui_state.mouse_pos_y);
				// printf("MOUSE POS: (%d, %d)\n", ui_state.mouse_pos_x, ui_state.mouse_pos_y);
			}
		}
		recursive_set_state(top_bar);
		recursive_renderering(top_bar);

		// recursive_set_state(top2_bar);
		// recursive_renderering(top2_bar);

		SDL_RenderPresent(renderer);
		SDL_Delay(20);
		i++;
	}
	(void)ui_state;
	(void)i;
	(void)quit;
	(void)events;
	return (0);
}
