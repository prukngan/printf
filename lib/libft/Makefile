# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/04 17:15:24 by prukngan          #+#    #+#              #
#    Updated: 2023/04/17 21:22:28 by prukngan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE_PATH	=	../../include

SRCS	=	ft_itoa.c \
			ft_strlen.c

OBJS		= $(SRCS:.c=.o)

FLAGS		= -Wall -Wextra -Werror -I$(INCLUDE_PATH)

$(NAME):
		gcc $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)

all:	$(NAME)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
