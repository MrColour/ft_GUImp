/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefabs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:43:08 by kmira             #+#    #+#             */
/*   Updated: 2019/09/23 21:16:45 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREFABS_H
# define PREFABS_H

# define DEFAULT_FONT_SIZE 14

# define WINDOW_WIDTH 420
# define WINDOW_HEIGHT 640

# define COMMON_WIDTH 100

# define BAR_WIDTH COMMON_WIDTH
# define BAR_HEIGHT 20

# define BORDER_WIDTH COMMON_WIDTH
# define BORDER_HEIGHT 2

enum	e_Move_option
{
    MOVE_UP    = 0b0001,
    MOVE_DOWN  = 0b0010,
    MOVE_LEFT  = 0b0100,
    MOVE_RIGHT = 0b1000
};

#endif
