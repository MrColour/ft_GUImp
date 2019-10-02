# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 11:40:08 by kmira             #+#    #+#              #
#    Updated: 2019/09/25 01:29:37 by kmira            ###   ########.fr        #
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
			bar \
			border \
			draw \
			element \
			font \
			get_size \
			hover \
			load \
			main_window \
			move \
			render \
			scale \
			set_state \
			text \
			tree_functions \


SRCS	= $(addsuffix .c, $(FILES))
OBJ		= $(addsuffix .o, $(FILES))

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
