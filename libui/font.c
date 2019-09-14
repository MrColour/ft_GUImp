/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   font.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 01:59:30 by kmira             #+#    #+#             */
/*   Updated: 2019/09/13 21:48:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libui.h"

TTF_Font	*init_font(char *file_path, int font_size)
{
	TTF_Font	*resulting_font;

	resulting_font = NULL;
	resulting_font = TTF_OpenFont(file_path, font_size);
	if (resulting_font == NULL)
		printf(RED"Sorry we do not currently have this font\n"COLOR_RESET);
	return (resulting_font);
}
