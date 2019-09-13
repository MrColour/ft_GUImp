/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:45:37 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:40:14 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		set_right_navigation_bar_state(t_gen_box *parent, t_gen_box *self, t_events *events)
{
	int	*ptr;

	ptr = self->self_state;
	*ptr = *ptr | 1;
	if (150 < events->mouse_pos_x && events->mouse_pos_x < 300 &&
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

t_gen_box	*init_bar_right(t_gen_box *left_bar, char *right_text , t_events *ui_state)
{
	t_gen_box	*right_bar;

	right_bar = malloc(sizeof(*right_bar) * (1));
	right_bar->renderer = left_bar->renderer;
	right_bar->pos_x = left_bar->pos_x + COMMON_WIDTH;
	right_bar->pos_y = left_bar->pos_y;
	right_bar->width = COMMON_WIDTH;
	right_bar->height = BAR_HEIGHT;
	right_bar->texture = ft_get_bar(right_bar->renderer);
	right_bar->render_active = always_active;
	right_bar->read_state = common_read_state;
	right_bar->self_state = malloc(sizeof(int) * 1);
	right_bar->events = ui_state;
	right_bar->set_state = set_right_navigation_bar_state;
	right_bar->name = strdup(right_text);

	right_bar->trie = malloc(sizeof(*right_bar->trie) * (1));
	right_bar->trie->data = init_textbox(right_bar, right_text, right_bar->renderer, right_bar->pos_x, right_bar->pos_y);
	right_bar->trie->data->render_active = always_active;

	right_bar->trie->next = malloc(sizeof(*right_bar->trie->next) * (1));
	right_bar->trie->next->data = init_border(right_bar, right_bar->renderer, right_bar->pos_x, right_bar->pos_y + BAR_HEIGHT - BORDER_HEIGHT);
	right_bar->trie->next->data->render_active = always_active;

	right_bar->trie->next->next=NULL;

	if (left_bar->trie == NULL)
	{
		left_bar->trie = malloc(sizeof(*left_bar->trie) * (1));
		left_bar->trie->data = right_bar;
		left_bar->trie->next = NULL;
	}
	else
		append_container(left_bar->trie, right_bar);
	return (right_bar);
}
