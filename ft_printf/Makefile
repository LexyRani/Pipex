# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aceralin <aceralin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/02 21:00:49 by aceralin          #+#    #+#              #
#    Updated: 2022/11/23 21:34:00 by aceralin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=   ft_printf.c\
					ft_print_str.c\
					ft_print_nbr.c \
					ft_print_unsigned.c \
					ft_print_hex.c \
					ft_print_ptr.c\

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= ft_printf

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS) ft_printf.h

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus
