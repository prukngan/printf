# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 20:00:39 by prukngan          #+#    #+#              #
#    Updated: 2023/04/16 20:00:39 by prukngan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	printf.a

INCLUDE_PATH = ../../include

SRCS	=	ft_printf_base10.c \
			ft_printf_base16.c \
			ft_printf_str.c \
			ft_printf.c

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE_PATH)

$(NAME):
		gcc $(FLAGS) -c $(SRCS)
		ar rc $(NAME) $(OBJS)

all: $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re