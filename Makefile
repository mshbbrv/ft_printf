# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 20:54:40 by thjonell          #+#    #+#              #
#    Updated: 2020/11/23 20:51:00 by thjonell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SOURCE		= srcs/ft_doparse_doprint.c srcs/ft_print_str.c srcs/ft_isalpha.c \
				srcs/ft_putnbr_base_rv.c srcs/ft_flags_parse.c \
				srcs/ft_print_un_int.c srcs/ft_strchr.c srcs/ft_prec_parse.c \
				srcs/ft_print_x.c srcs/ft_type_parse.c srcs/ft_print_char.c \
				srcs/ft_print_xx.c srcs/ft_width_parse.c srcs/ft_print_int.c \
				srcs/ft_printf.c srcs/ft_print_ptr.c srcs/ft_putchar_rv.c


OBJECTS 	= ${SOURCE:.c=.o}

INCLUDE		= inc

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJECTS}
			ar -rc	${NAME} ${OBJECTS}
			ranlib	${NAME}

clean:
			${RM} ${OBJECTS} ${BONUS_OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re