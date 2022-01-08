# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abensett <abensett@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 22:33:41 by abensett          #+#    #+#              #
#    Updated: 2021/10/07 15:29:49 by abensett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c \
	ft_printf_identifiers.c \
	ft_printf_utils_and_bonus.c


OBJS 	=   $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(MAKE) -C libft
			cp libft/libft.a $(NAME)	
			ar rc $(NAME) $(OBJS)

.c.o:
			gcc -Wall -Wextra -Werror -c $< -o $(<:.c=.o)

bonus:	$(NAME)

clean:
	$(MAKE) fclean -C ./libft
	/bin/rm -f $(OBJS)	$(OBJSBONUS)

fclean:	clean
	$(MAKE) fclean -C ./libft
	/bin/rm -f $(NAME) 

re:	fclean all

.PHONY: all clean fclean re
