# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytop <ytop@student.42kocaeli.com.tr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/08 13:02:33 by ytop              #+#    #+#              #
#    Updated: 2024/08/08 13:10:32 by ytop             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	number_generator

SRCS	=	./number_generator.c

OBJS	=	$(SRCS:.c=.o)

CC		=	@cc
CFLAGS	=	-Wall -Wextra -Werror

RM		=	@rm -f

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re
