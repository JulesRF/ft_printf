# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jroux-fo <jroux-fo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 15:30:45 by jroux-fo          #+#    #+#              #
#    Updated: 2021/12/22 14:33:32 by jroux-fo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_FILES =		ft_printf.c \
					ft_printf_utils.c

# SRCS_BONUS_FILES =	ft_lstnew.c \
# 					ft_lstadd_front.c \
# 					ft_lstsize.c \
# 					ft_lstlast.c \
# 					ft_lstadd_back.c \
# 					ft_lstdelone.c \
# 					ft_lstclear.c \
# 					ft_lstiter.c \
# 					ft_lstmap.c

OBJS_FILES =		${SRCS:.c=.o}

# OBJ_BONUS	=		${SRCS_BONUS:.c=.o}

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

# SRCS_BONUS		=	$(addprefix $(SRCS_PATH)/, $(SRCS_BONUS_FILES))



all		:	$(NAME)


$(NAME)		:	$(OBJS_FILES) $(HEADER)
			ar rc $(NAME) $(OBJS_FILES)

%o		:	%.c
			$(CC) $(FLAGS) $(HEADER_FILES) -c $< -o $@



# bonus		:		$(OBJ_BONUS) $(OBJ) $(INC)
# 				ar rc $(NAME) $(OBJ_BONUS)
clean:
			${RM} ${OBJS_FILES} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re :		fclean all

.PHONY:		all clean fclean re bonus
