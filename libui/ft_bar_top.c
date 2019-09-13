/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar_top.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:37:22 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:45:06 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		set_top_navigation_bar_state(t_gen_box *parent, t_gen_box *self, t_events *events)
{
	int	*ptr;

	ptr = self->self_state;
	*ptr = *ptr | 1;
	if (self->pos_x < events->mouse_pos_x && events->mouse_pos_x < self->pos_x + COMMON_WIDTH &&
		self->pos_y < events->mouse_pos_y && events->mouse_pos_y < self->pos_y + BAR_HEIGHT)
	{
		*ptr = *ptr | 2;
	}
	else
	{
		*ptr = 0;
		*ptr = 1;
		printf("No go!\n");
	}
	(void)parent;
	(void)events;
}

t_gen_box	*init_bar_top(char *bar_text, SDL_Renderer *renderer, int x, int y, t_events *events)
{
	t_gen_box	*bar;

	bar = malloc(sizeof(*bar) * (1));
	bar->renderer = renderer;
	bar->pos_x = x;
	bar->pos_y = y;
	bar->width = COMMON_WIDTH;
	bar->height = BAR_HEIGHT;
	bar->texture = ft_get_bar(renderer);
	bar->render_active = &always_active;
	bar->read_state = &common_read_state;
	bar->self_state = malloc(sizeof(int) * 1);
	bar->events = events;
	bar->set_state = &set_top_navigation_bar_state;
	bar->name = strdup(bar_text);

	bar->trie = malloc(sizeof(*bar->trie) * (1));
	bar->trie->data = init_textbox(bar, bar_text, renderer, x, y);
	bar->trie->data->render_active = &always_active;

	bar->trie->next = malloc(sizeof(*bar->trie->next) * (1));
	bar->trie->next->data = init_border(bar, renderer, x, y + BAR_HEIGHT - BORDER_HEIGHT);
	bar->trie->next->data->render_active = &always_active;

	bar->trie->next->next = NULL;

	return (bar);
}
