# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 11:40:08 by kmira             #+#    #+#              #
#    Updated: 2019/09/12 22:18:57 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libui.a
FLAGS	= -Wall -Werror -Wextra -c

INCLUDES =	-I libft \
			-I includes \
			-I Frameworks/SDL2.framework/Versions/A/Headers \
			-I Frameworks/SDL2_image.framework/Versions/A/Headers \
			-I Frameworks/SDL2_ttf.framework/Versions/A/Headers \
			-I Frameworks/SDL2_mixer.framework/Versions/A/Headers \
			-F Frameworks/

LIBRARY = libft/libft.a

FILES	=	\
			assets \
			bar_below \
			bar_right \
			bar_top \
			border \
			common_functions \
			init_font \
			initialize \
			load \
			render_texture \
			text \


SRCS	= $(addsuffix .c, $(addprefix ft_, $(FILES)))
OBJ		= $(addsuffix .o, $(addprefix ft_, $(FILES)))

.PHONY: clean fclean all re

all: $(NAME)

$(NAME) : $(LIBRARY) $(OBJ)
	@echo "	Creating your libui.a library..."
	@ar rcs $(NAME) $(OBJ)
	@echo "Done!"

$(LIBRARY):
	@make -C libft

$(OBJ) :
	@echo "	Making OBJ Files..."
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)

clean:
	@echo "	Removing only OBJ files..."
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "	Rmoving libui.a and libui/libft.a files..."
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
