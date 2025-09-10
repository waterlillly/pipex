# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbaumeis <lbaumeis@student.42vienna.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/06 18:13:23 by lbaumeis          #+#    #+#              #
#    Updated: 2025/02/03 14:36:49 by lbaumeis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
OBJDIR	= obj
DEPDIR	= $(OBJDIR)/.deps
HEADERS	= libft.h
OBJ		= $(SRC:src/%.c=$(OBJDIR)/%.o)
DEPS	= $(OBJ:.o=.d)

CLASSIFICATION =	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
                    ft_isalpha_extend.c ft_isprint_extend.c ft_isascii_extend.c \
                    ft_skipwhite.c ft_onlywhite.c ft_iswhite.c

MEMORY =			ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
            		ft_memchr.c ft_memcmp.c ft_calloc.c ft_realloc.c \
            		ft_free_double.c ft_realloc_2d.c

MODIFICATION =		ft_strlcpy.c ft_strlcat.c ft_strcpy.c ft_strcat.c ft_strncpy.c \
                	ft_strjoin_free.c ft_striteri.c ft_strappend.c

CREATION =			ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
                    ft_split.c ft_strmapi.c

INFORMATION =		ft_strlen.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strcmp.c \
                	ft_strcmp_bool.c ft_strnstr.c ft_strnstr_bool.c ft_strspn.c \
                	ft_arrlen.c

CONVERSION =		ft_atoi.c ft_atoi_long.c ft_atof.c ft_itoa.c ft_itoa_long.c \
                	ft_toupper.c ft_tolower.c ft_strtoupper.c ft_strtolower.c

LINKEDLISTS =		ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
            		ft_lstlast.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

PRINTF =			ft_printf.c ft_printchar.c ft_printstr.c ft_printnbr.c \
        			ft_printptr.c ft_decideformat.c

OUTPUT =			ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
            		ft_print_array.c ft_print_array_fd.c

GNL =				get_next_line.c

SRC = $(addprefix src/classification/, $(CLASSIFICATION)) \
      $(addprefix src/memory/, $(MEMORY)) \
      $(addprefix src/modification/, $(MODIFICATION)) \
      $(addprefix src/creation/, $(CREATION)) \
      $(addprefix src/information/, $(INFORMATION)) \
      $(addprefix src/conversion/, $(CONVERSION)) \
      $(addprefix src/linked_lists/, $(LINKEDLISTS)) \
      $(addprefix src/printf/, $(PRINTF)) \
      $(addprefix src/output/, $(OUTPUT)) \
      $(addprefix src/gnl/, $(GNL))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

$(OBJDIR)/%.o: src/%.c $(HEADERS)
	@mkdir -p $(dir $@)
	@mkdir -p $(DEPDIR)/$(dir $*)
	@$(CC) $(CFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@

-include $(DEPS)

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	@rm -f a.out

re: fclean all

.PHONY: all clean fclean re