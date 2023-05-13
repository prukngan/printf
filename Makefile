# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prukngan <phongsathon.rak2003@gmail.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/16 20:36:37 by prukngan          #+#    #+#              #
#    Updated: 2023/04/16 20:36:37 by prukngan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

OBJS_DIR	=	output

SRCS	=	ft_printf.c \
			ft_convert_c.c \
			ft_convert_d.c \
			ft_convert_p.c \
			ft_convert_s.c \
			ft_convert_x.c \
			ft_flags.c \
			ft_len.c

OBJS	=	$(SRCS:.c=.o)

FLAGS	=	-Wall -Wextra -Werror -I./

$(NAME):
		gcc $(FLAGS) -c $(SRCS)
		mkdir -p $(OBJS_DIR)
		mv $(OBJS) $(OBJS_DIR)
		ar rc $(NAME) $(addprefix $(OBJS_DIR)/, $(OBJS))

$(OBJS):
		mkdir -p $(OBJS_DIR)
		mv $(OBJS) $(OBJS_DIR)

all :	$(NAME)

bonus:	all

clean:
		rm -rf $(OBJS_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus