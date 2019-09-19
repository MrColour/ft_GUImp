/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 03:40:36 by kmira             #+#    #+#             */
/*   Updated: 2019/09/18 01:31:21 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_STRUCTS_H
# define LIBUI_STRUCTS_H

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"

typedef struct	s_events
{
	long long	down_keys;
	long long	released_keys;

	int			mouse_pos_x;
	int			mouse_pos_y;
	char		right_click;
	char		left_click;
	char		wheel_up;
	char		wheel_down;
}				t_events;

typedef enum	e_activity
{
    BOX_ACTIVE     = 0b00001,
    PASSIVE_ACTIVE = 0b00010,
    DISPLAY_ON     = 0b00100,
    HIDDEN_BOX     = 0b01000,
    MOUSE_HOVER    = 0b10000
}				t_activity;

typedef struct s_state
{
	t_activity	standard;
	int			draw_x;
	int			draw_y;
	void		*special;
	char		*name;
}				t_state;

typedef	struct s_rectangle
{
	int			begin_x;
	int			begin_y;
	int			end_x;
	int			end_y;
}				t_rect;

typedef struct	s_box	t_box;
typedef	struct	s_linker t_linker;

typedef	struct	s_window
{
	t_rect			rect;
	t_events		events;
	SDL_Renderer	*renderer;
}				t_window;

typedef struct	s_box
{
	t_window		*window;
	t_rect			rect;
	t_state			state;
	SDL_Texture		*layer;

	t_box			*parent;
	t_linker		*tree;

	void			(*set_state)(t_box *self);
	void			(*child_requirement)(t_box *self);
	void			(*parent_requirment)(t_box *self);

	void			*(*fetch_state)(t_box *, char *command);
}				t_box;

typedef struct	s_linker
{
	t_box			*data;
	struct s_linker	*next;
}				t_linker;

#endif
