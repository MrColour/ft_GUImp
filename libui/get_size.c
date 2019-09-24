/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:26:19 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 21:19:35 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

int		get_width(t_rect rect)
{
	int	width;

	width = rect.end_x - rect.begin_x;
	return (width);
}

int		get_height(t_rect rect)
{
	int	height;

	height = rect.end_y - rect.begin_y;
	return (height);
}

int		is_within(int mouse_x, int mouse_y, t_rect rectanle, int rect_pos_x, int rect_pos_y)
{
	if (rectanle.begin_x + rect_pos_x <= mouse_x &&
		mouse_x <= rectanle.end_x + rect_pos_x &&
		rectanle.begin_y + WINDOW_HEIGHT - rect_pos_y < mouse_y &&
		mouse_y <= rectanle.end_y + WINDOW_HEIGHT - rect_pos_y)
		return (1);
	return (0);
}
