# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/31 00:32:20 by kmira             #+#    #+#              #
#    Updated: 2019/08/31 01:20:44 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = guimp

FLAGS = -Wall -Wextra -Werror

INCLUDES = includes/
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
	@gcc -o $(NAME) $(FLAGS) $(OBJS) $(LIBFT_LIBRARY) $(LIBUI_LIBRARY)
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
	@echo "Removing guimp and cleaning other files..."
	@make -C libft/ fclean
	@make -C libui/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

$(OBJS):
	@gcc $(FLAGS) -I$(INCLUDES) -c $(SRCS)

