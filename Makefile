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

SRCS_DIR = lib/

#------------------------ DIR ------------------------------

LIBFT_DIR 	=	libft/
PRINTF_DIR	=	printf/

#------------------------ PATH ------------------------------

LIBFT_PATH	=	lib/libft/
PRINTF_PATH	=	lib/printf/

#----------------------- COMMAND ----------------------------

$(NAME):
		make -C $(LIBFT_PATH)
		make -C $(PRINTF_PATH)

all: $(NAME)

clean:
		make clean -C $(LIBFT_PATH)
		make clean -C $(PRINTF_PATH)

fclean: clean
		rm -f $(LIBFT_PATH)libft.a
		rm -f $(PRINTF_PATH)printf.a
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re