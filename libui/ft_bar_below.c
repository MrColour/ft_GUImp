/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bar_below.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:47:03 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:33:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void		set_below_bar_state(t_gen_box *parent, t_gen_box *self, t_events *events)
{
	void	*data;
	int		*ptr;

	ptr = self->self_state;
	*ptr = 0;

	data = parent->read_state(parent->self_state, "HOVER");
	if (*(char *)data == 2)
	{
		printf("Parent is hovered!\n");
		free(data);
		*ptr = 1;
	}
	(void)events;
}

t_gen_box	*init_bar_below(t_gen_box *top, char *below_text, t_events *events)
{
	t_gen_box	*below;

	below = malloc(sizeof(*below) * (1));
	below->renderer = top->renderer;
	below->pos_x = top->pos_x;
	below->pos_y = top->pos_y + BAR_HEIGHT;
	below->texture = ft_get_bar(below->renderer);
	below->width = COMMON_WIDTH;
	below->height = BAR_HEIGHT;
	below->render_active = if_parent_is_active;
	below->read_state = common_read_state;
	below->parent_state = top;
	printf("Parent: %p\n", below->parent_state);
	below->events = events;
	below->self_state = malloc(sizeof(int) * 1);
	below->set_state = set_below_bar_state;
	below->name = strdup(below_text);

	below->trie = malloc(sizeof(*below->trie) * (1));
	below->trie->data = init_textbox(below, below_text, below->renderer, below->pos_x, below->pos_y);

	below->trie->next = malloc(sizeof(*below->trie->next) * (1));
	below->trie->next->data = init_border(below, below->renderer, below->pos_x, below->pos_y + BAR_HEIGHT - BORDER_HEIGHT);

	below->trie->next->next = NULL;

	if (top->trie == NULL)
	{
		top->trie = malloc(sizeof(*top->trie) * (1));
		top->trie->data = below;
		top->trie->next = NULL;
	}
	else
		append_container(top->trie, below);
	return (below);
}
