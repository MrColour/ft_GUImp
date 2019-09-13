/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:07:04 by kmira             #+#    #+#             */
/*   Updated: 2019/09/12 22:40:35 by kmira            ###   ########.fr       */
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

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** GLOBAL VARS
*/

TTF_Font		*g_font;
extern TTF_Font *g_font;

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** COMMON BAR FUNCIONS
*/

void		append_container(t_linker *links, t_gen_box *container);
void		*common_read_state(void *self, char *string);
int			if_parent_is_active(t_gen_box *parent, void *self, t_events *event);
int			always_active(t_gen_box *parent, void *self, t_events *event);
void		set_below_bar_state(t_gen_box *parent, t_gen_box *self, t_events *events);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** BAR INITIALIZERS
*/

t_gen_box	*init_bar_top(char *bar_text, SDL_Renderer *rend, int x, int y, t_events *events);
t_gen_box	*init_bar_below(t_gen_box *top, char *below_text, t_events *events);
t_gen_box	*init_bar_right(t_gen_box *left_bar, char *right_text , t_events *events);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** TEXT BOX
*/

t_gen_box	*init_textbox(t_gen_box *parent, char *text, SDL_Renderer *renderer, int x, int y);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** BORDER
*/

t_gen_box	*init_border(t_gen_box *parent, SDL_Renderer *renderer, int x, int y);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** RENDERING TO SCREEN
*/

void		render_texture_native(SDL_Texture *texture, SDL_Renderer *rend, int x, int y);
void		render_texture_scale(SDL_Texture *texture, SDL_Renderer *rend, int x, int y, float scale);
void		render_texture(SDL_Texture *texture, SDL_Renderer *rend, int x, int y, int width, int height);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** WINDOW WIDE CALLS
*/

SDL_Window	*create_default_window(int win_width, int win_height);

TTF_Font	*init_font(char *file_path, int font_size);

SDL_Texture	*ft_get_bar(SDL_Renderer *renderer);
SDL_Texture	*ft_get_divider(SDL_Renderer *renderer);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** LIBUI
*/

SDL_Texture	*load_image(const char *file_path, SDL_Renderer *renderer);

#endif
