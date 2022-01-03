# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 15:30:45 by jroux-fo          #+#    #+#              #
#    Updated: 2021/12/24 15:27:59 by jroux-fo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES =		ft_printf.c \
					ft_printf_utils.c

OBJS_FILES =		${SRCS:.c=.o}

HEADER_FILES		=	-I$(HEADER_PATH)

HEADER_PATH		= 		.

HEADER_NAME		=	ft_printf.h

SRCS_PATH =		.


CC		=	gcc

FLAGS		=	-Wall -Wextra -Werror

RM		=	rm -rf

HEADER		=	ft_printf.h

NAME		=	libftprintf.a

HEADER		=	$(addprefix $(HEADER_PATH)/, $(HEADER_NAME))

SRCS		=	$(addprefix $(SRCS_PATH)/, $(SRCS_FILES))



all		:	$(NAME)


$(NAME)		:	$(OBJS_FILES) $(HEADER)
			ar rc $(NAME) $(OBJS_FILES)

%o		:	%.c
			$(CC) $(FLAGS) $(HEADER_FILES) -c $< -o $@



clean:
			${RM} ${OBJS_FILES}

fclean:		clean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re
