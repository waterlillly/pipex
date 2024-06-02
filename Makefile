# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 20:02:31 by lbaumeis          #+#    #+#              #
#    Updated: 2024/06/02 17:30:25 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address
LIB_FLAGS = -L. -lft

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = pipex.c error.c main.c
OFILES = $(CFILES:.c=.o)
P_NAME = pipex

all: $(P_NAME)

$(P_NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $@ $^ $(LIB_FLAGS)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(P_NAME)

re: fclean all

.PHONY: all clean fclean re