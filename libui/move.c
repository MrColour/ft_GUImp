/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 01:02:34 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 01:04:28 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

void	move_rectangle(t_rect *rectangle, int x, int y)
{
	rectangle->begin_x = rectangle->begin_x + x;
	rectangle->begin_y = rectangle->begin_y + y;

	rectangle->end_x = rectangle->end_x + x;
	rectangle->end_y = rectangle->end_y + y;
}
