# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 00:32:20 by kmira             #+#    #+#              #
#    Updated: 2019/09/09 03:55:24 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = run_SDL_tutorial

FLAGS = -Wall -Wextra -Werror

INCLUDES =  -I includes \
			-I Frameworks/SDL2.framework/Versions/A/Headers \
			-I Frameworks/SDL2_image.framework/Versions/A/Headers \
			-I Frameworks/SDL2_ttf.framework/Versions/A/Headers \
			-I Frameworks/SDL2_mixer.framework/Versions/A/Headers \
			-F Frameworks/

FRAMEWORK = -framework SDL2_mixer \
			-framework SDL2_image \
			-framework SDL2_ttf \
			-framework SDL2 \
			-F Frameworks/ \

LIBFT_LIBRARY = libft/libft.a
LIBUI_LIBRARY = libui/libui.a

MAIN_FILES = \
			main \

SRCS_PATH = $(MAIN_FILES)

SRCS = $(addprefix srcs/, $(addsuffix .c, $(SRCS_PATH)))
OBJS = $(addsuffix .o, $(MAIN_FILES))

.PHONY: fclean clean re

all: $(NAME)

$(NAME): $(LIBFT_LIBRARY) $(LIBUI_LIBRARY) $(OBJS)
	@echo "Making your GUImp program..."
	@gcc -o $(NAME) $(FLAGS) $(OBJS) $(FRAMEWORK) $(LIBFT_LIBRARY) $(LIBUI_LIBRARY)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 Frameworks/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)
	@echo "Done"

$(LIBFT_LIBRARY):
	@make -C libft/

$(LIBUI_LIBRARY):
	@make -C libui/

clean:
	@echo "Removing all .o files..."
	@make -C libft/ clean
	@make -C libui/ clean
	@/bin/rm -f $(OBJS)

fclean: clean
	@find . -name "._*" -type f -delete
	@echo "Removing guimp and cleaning other files..."
	@make -C libft/ fclean
	@make -C libui/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

$(OBJS):
	@gcc $(FLAGS) $(INCLUDES) -c $(SRCS)

sync:
	cp libft/libft.h ./includes/libft.h
	cp -rf libui/includes/* ./includes/
	cp -rf libui/Resources/ ./Resources/

#The quick   make pragmas  remake guimp, libui
#The quicker make pragmas  remake guimp
#The regular make comamnds   make guimp, libui, and libft


quick_pragma: $(LIBUI_LIBRARY) $(OBJS)
	@echo "Making your GUImp program..."
	@gcc -o $(NAME) $(FLAGS) $(OBJS) $(FRAMEWORK) $(LIBFT_LIBRARY) $(LIBUI_LIBRARY)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 Frameworks/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)
	@echo "Done"

quick_fclean: quick_clean
	@echo "Removing guimp and cleaning other files..."
	@make -C libui/ fclean
	@/bin/rm -f $(NAME)

quick_clean:
	@echo "Removing all .o files..."
	@make -C libui/ clean
	@/bin/rm -f $(OBJS)

quick_re: quick_fclean quick_all

quick: quick_fclean quick_clean quick_pragma
	./$(NAME)

quicker_pragma: $(OBJS)
	@echo "Making your GUImp program..."
	@gcc -o $(NAME) $(FLAGS) $(OBJS) $(FRAMEWORK) $(LIBFT_LIBRARY) $(LIBUI_LIBRARY)
	@install_name_tool -change @rpath/SDL2.framework/Versions/A/SDL2 Frameworks/SDL2.framework/Versions/A/SDL2 $(NAME)
	@install_name_tool -change @rpath/SDL2_mixer.framework/Versions/A/SDL2_mixer Frameworks/SDL2_mixer.framework/Versions/A/SDL2_mixer $(NAME)
	@echo "Done"

quicker_fclean: quicker_clean
	@echo "Removing guimp and cleaning other files..."
	@/bin/rm -f $(NAME)

quicker_clean:
	@echo "Removing all .o files..."
	@/bin/rm -f $(OBJS)

quicker_re: quicker_fclean quicker_all

quicker: quicker_fclean quicker_clean quicker_pragma
	./$(NAME)

kill:
	pkill -KILL $(NAME)
