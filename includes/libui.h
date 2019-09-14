/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:07:04 by kmira             #+#    #+#             */
/*   Updated: 2019/09/14 01:05:07 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUI_H
# define LIBUI_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include "SDL.h"
# include "SDL_image.h"
# include "SDL_mixer.h"
# include "SDL_ttf.h"

# include "color.h"
# include "libft.h"
# include "libui_structs.h"
# include "prefabs.h"

TTF_Font		*g_font;
extern TTF_Font	*g_font;

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MAIN_WINDOWS
*/

SDL_Window		*create_default_window(int win_width, int win_height);
TTF_Font		*init_font(char *file_path, int font_size);

t_rect			main_window(int window_width, int window_height);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Generic Box things
*/

t_box	*common_element(t_box *parent, t_rect rect, SDL_Texture *layer, t_window *window);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** BAR CLASS
*/

t_rect		get_bar_rectangle(void);
SDL_Texture	*get_bar_layer(SDL_Renderer *renderer);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Render Stuff
*/

void	render_tree(t_box *box);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Fetch size
*/

int				get_width(t_rect rect);
int				get_height(t_rect rect);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Draw Stuff
*/

void			draw_box(t_box *box);
void			move_rectangle(t_rect *rectangle, int x, int y);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Load Stuff
*/

SDL_Texture		*load_image(const char *file_path, SDL_Renderer *renderer);

#endif
