CC = cc
CFLAGS = -Wall -Werror -Wextra -g

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

CFILES = main.c pipex.c pipex_utils.c pipex_utils2.c
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