/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:20:09 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 01:13:39 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	render_tree(t_box *box)
{
	t_linker *node;

	if (box == NULL)
		return ;
	node = box->tree;
	if (box->state.standard & DISPLAY_ON)
		draw_box(box);
	while (node != NULL)
	{
		render_tree(node->data);
		node = node->next;
	}
}
