# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 21:11:53 by aceralin          #+#    #+#              #
#    Updated: 2022/11/28 14:42:08 by aceralin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=  	pipex.c\
					path.c \
					childs_process.c\
					errors.c \
					close.c\
					ft_utiles.c\
					ft_split.c\

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= pipex

all:			$(NAME) 

$(NAME):		$(OBJS) pipex.h
				@${CC} ${CFLAGS} ${OBJS}  -o pipex

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
