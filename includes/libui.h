/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libui.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 01:07:04 by kmira             #+#    #+#             */
/*   Updated: 2019/09/18 23:18:16 by kmira            ###   ########.fr       */
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
t_box	*common_element_below(t_box *parent, t_rect rect, SDL_Texture *layer);

void	common_set_state(t_box *self);
void	state_copy_parent(t_box *self);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** BAR CLASS
*/

t_rect		get_bar_rectangle(void);
SDL_Texture	*get_bar_layer(SDL_Renderer *renderer);
t_box		*bar_default(t_window *window, char *text, int x, int y);

t_box		*bar_on_option(t_box *parent, char *text, int options);

t_rect		get_border_rectangle(void);
SDL_Texture	*get_border_layer(SDL_Renderer *renderer);
t_box		*install_border(t_box *parent);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** TEXT Stuff
*/

SDL_Texture	*get_text_layer(SDL_Renderer *renderer, char *text);
t_box	*text_common(t_window *window, char *text, int x, int y);
t_box	*install_text(t_box *parent, int top_padding, int left_padding, char *text);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** TREE Functions
*/

void	render_tree(t_box *box);
void	set_tree(t_box *box);
int		state_in_tree(t_box *box, t_activity search_state, int depth);

void	tree_append(t_box *parent, t_box *child);
void	tree_append_parent(t_box *parent, t_box *child);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Fetch size
*/

int				get_width(t_rect rect);
int				get_height(t_rect rect);

int				is_within(int mouse_x, int mouse_y, t_rect rectanle, int rect_pos_x, int rect_pos_y);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Draw Stuff
*/

void			draw_box(t_box *box);
void			move_rectangle(t_rect *rectangle, int x, int y);
void			move_recursive(t_box *box, int amount_right, int amount_down);
void			move_option(t_box *parent, t_box *child, int option);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** Load Stuff
*/

SDL_Texture		*load_image(const char *file_path, SDL_Renderer *renderer);

#endif
