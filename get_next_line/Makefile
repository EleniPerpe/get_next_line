# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/24 17:30:25 by eperperi          #+#    #+#              #
#    Updated: 2024/03/27 12:45:54 by eperperi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wextra -Wall -Werror

SRCS = get_next_line.c get_next_line_utils.c

OFILES = $(SRCS: .c=.o)

NAME = get_next_line.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	$(RM) -f $(OFILES)

fclean:
	$(RM) -f $(NAME)

re: fclean all

.PHONY: all clean fclean
