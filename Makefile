# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: linhnguy <linhnguy@hive.student.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/15 19:56:43 by linhnguy          #+#    #+#              #
#    Updated: 2024/03/20 16:18:36 by linhnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
HEADERS	= -I ./include
LIBFT = libft.a
LIBFTDIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG_CFLAGS = -fsanitize=address -g3
SRCS = src/pipex.c src/envir_array.c src/utils.c src/clean_up.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME):$(OBJS)
	@make -C $(LIBFTDIR)
	$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFTDIR)/$(LIBFT) -o $(NAME)
	@echo "Program Made"

debug: re
	$(CC) $(OBJS) $(LIBS) $(HEADERS) $(DEBUG_CFLAGS) $(LIBFTDIR)/$(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(HEADERS)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFTDIR) clean
	@echo "Cleaned object files"

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFTDIR) fclean
	@echo "Fully Cleaned"

re: fclean all

.PHONY: all clean fclean re debug