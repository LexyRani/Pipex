# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 21:11:53 by aceralin          #+#    #+#              #
#    Updated: 2022/11/23 21:42:52 by aceralin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=  pipex.c path.c child_process.c close.c errors.c close.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= pipex

all:			$(NAME) pipex.h

$(NAME):		$(OBJS)
				@${MAKE} -C .ft_printf/
				@${CC} ${CFLAGS} ${OBJS} ./ft_printf/ft_printf -o pipex
				ar rcs $(NAME) $(OBJS)

clean:
				@${MAKE} -C ./ft_printf fclean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus