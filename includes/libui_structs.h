/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 03:40:36 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:27:42 by kmira            ###   ########.fr       */
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

typedef	struct	s_linker t_linker;

typedef struct	s_gen_box
{
	SDL_Window 			*window;
	SDL_Renderer		*renderer;
	int					pos_x;
	int					pos_y;
	int					width;
	int					height;
	SDL_Texture			*texture;
	char				*name;

	struct s_linker		*trie;

	t_events			*events;
	void				*self_state;
	struct s_gen_box	*parent_state;

	int					(*render_active)(struct s_gen_box *, void *, t_events *);
	void				*(*read_state)(void *, char *);
	void				(*set_state)(struct s_gen_box *, struct s_gen_box *, t_events *);

}					t_gen_box;

typedef struct	s_linker
{
	t_gen_box	*data;
	struct s_linker		*next;
}				t_linker;

#endif
