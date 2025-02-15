# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/13 06:42:03 by lbaumeis          #+#    #+#              #
#    Updated: 2024/06/13 11:33:22 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = main.c pipex.c check_free_close.c processes.c
OFILES = $(CFILES:.c=.o)
P_NAME = pipex

all: $(P_NAME)

$(P_NAME): $(OFILES)
	($(MAKE) -C ./libft)
	$(CC) $(CFLAGS) -o $@ $^ ./libft/libft.a

clean:
	($(MAKE) -C ./libft clean)
	rm -f $(OFILES)

fclean: clean
	($(MAKE) -C ./libft fclean)
	rm -f $(P_NAME)

re: fclean all

.PHONY: all clean fclean re
