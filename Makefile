# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrybak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/16 16:19:05 by mrybak            #+#    #+#              #
#    Updated: 2018/02/16 16:19:06 by mrybak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   lem-in
CC      =   gcc
FLAG    =   -Wall -Wextra -Werror
LIBFT   =   ./src/big_libft.a
SRC     =   ./main.c            \
			./lem_in.c 			\
			./map_creation.c    \
			./add_free.c        \
			./sub_funcs.c       \
			./sub_funcs2.c      \
			./link_it.c         \
			./read_it.c         \
			./find_path.c       \
			./way_back.c        \
			./move_ants.c       \

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) libft
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "\033[0;31mYour $(NAME) ready.\033[0m"

libft:
	@make -C ./src

%.o : %.c
	@$(CC) $(FLAG) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make clean -C ./src

fclean:
	@rm -f $(NAME)
	@rm -f $(OBJ)
	@make fclean -C ./src
	@echo "\033[0;31mYour $(NAME) is dead.\033[0m"

re: fclean all
.PHONY: all clean fclean re
