/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_border.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 21:48:52 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:35:51 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

t_gen_box	*init_border(t_gen_box *parent, SDL_Renderer *renderer, int x, int y)
{
	t_gen_box	*border;

	border = malloc(sizeof(*border) * (1));
	border->renderer = renderer;
	border->pos_x = x;
	border->pos_y = y;
	border->width = COMMON_WIDTH;
	border->height = BORDER_HEIGHT;
	border->texture = ft_get_divider(renderer);
	border->render_active = if_parent_is_active;
	border->read_state = common_read_state;
	border->parent_state = parent;
	border->self_state = malloc(sizeof(int) * 1);
	border->set_state = set_below_bar_state;
	border->events = parent->events;

	border->trie = NULL;

	return (border);
}
