/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 23:26:19 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 01:23:17 by kmira            ###   ########.fr       */
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
