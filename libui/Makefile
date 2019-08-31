# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kmira <kmira@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/12 11:40:08 by kmira             #+#    #+#              #
#    Updated: 2019/08/31 00:42:14 by kmira            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libui.a
FLAGS	= -Wall -Werror -Wextra -c

INCLUDES = libft
LIBRARY = libft/libft.a

FILES	=	\
			test \

C_FILES	= $(addsuffix .c, $(addprefix ft_, $(FILES)))
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
	@gcc $(FLAGS) $(C_FILES)

clean:
	@echo "	Removing only OBJ files..."
	@make -C libft clean
	@/bin/rm -f $(OBJ)

fclean: clean
	@echo "	Rmoving libui.a and libui/libft.a files..."
	@make -C libft fclean
	@/bin/rm -f $(NAME)

re: fclean all
