# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 21:11:53 by aceralin          #+#    #+#              #
#    Updated: 2022/11/26 17:13:52 by aceralin         ###   ########.fr        #
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
CFLAGS			= -g3 -Wall -Wextra -Werror -I.

NAME			= pipex

all:			$(NAME) 

$(NAME):		$(OBJS) pipex.h
				@${MAKE} -C ./ft_printf
				@${CC} ${CFLAGS} ${OBJS} ./ft_printf/ft_printf -o pipex

clean:
				@${MAKE} -C ./ft_printf fclean
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
