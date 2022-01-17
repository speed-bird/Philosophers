# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrobert <jrobert@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 19:40:56 by jrobert           #+#    #+#              #
#    Updated: 2022/01/16 19:57:19 by jrobert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES	= 	philo.c

SRCS_DIR	= 	srcs/
SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_FILES))
OBJS		= 	$(SRCS:%.c=%.o)
NAME		=	philo
CFLAGS		= 	-Wall -Wextra -Werror -I includes
			
$(NAME)			:	$(OBJS)
					gcc $(OBJS) -fsanitize=address -g3 -o $(NAME)

all    			:	$(NAME)

clean 			:	
					rm -f $(OBJS)

fclean 			:	clean
					rm -f $(NAME)
					
re				:	fclean all

.PHONY			: 	all clean fclean re
