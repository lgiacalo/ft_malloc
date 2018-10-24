# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymohl-cl <ymohl-cl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/08 14:10:37 by ymohl-cl          #+#    #+#              #
#    Updated: 2015/03/13 11:38:39 by ymohl-cl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXPORT_LIBRARY = DYLD_LIBRARY_PATH=../depot/
export EXPORT_LIBRARY

NAME = test_malloc

CC = gcc

FLAG = -Wall -Wextra -Werror -g

LIBNAME = -L ../depot/ -lft_malloc

SRC =	main_malloc.c \
		tests_simples_malloc.c \
		tests_complet_map_tiny.c \
		tests_complet_map_medium.c \
		tests_complet_map_large.c \
		tests_all_map.c \
		tests_complet_realloc.c \
		tests_corruption_memory.c \
		tests_getrlimit.c \
		tests_multi_thread.c \
		tests_multiple_map.c \
		tests_big_tests.c \

OBJ = $(SRC:%.c=%.o)

.PHONY: all say clean fclean re libfts tmp

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAG) -o $@ -c $<
	@echo "\033[32m.\c\033[0m"

$(NAME): malloc_create say $(OBJ) close
	@$(CC) $(FLAG) -o $(NAME) $(OBJ) $(LIBNAME)
	@echo "\033[32m\tCompilation DONE !"
#	@sh ./scriptMakefile.sh
	@echo "\033[32m\tEnjoy !\033[37m"

say:
	@echo "\033[33m\t'.' == One file is compiled\033[0m"
	@echo "\033[33m\t' ' == make: Nothing to be for 'all'\033[0m"
	@echo "\033[32m\tCompilation progress: \c\033[0m"

malloc_create:
	rm -rf tmp
	@mkdir tmp
	@make -C ../depot/

close:
	@echo "\033[0m\t\033[m"

clean:
	rm -f $(OBJ)
	rm -rf tmp
	make clean -C ../depot/

fclean: clean
	rm -f $(NAME)
	make fclean -C ../depot/

re: fclean all

export DYLD_LIBRARY_PATH=../depot/
