# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thjonell <thjonell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 20:54:40 by thjonell          #+#    #+#              #
#    Updated: 2020/11/08 17:21:04 by thjonell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

SOURCE		= libft/ft_putnbr_fd.c libft/ft_putendl_fd.c libft/ft_putstr_fd.c \
			libft/ft_putchar_fd.c libft/ft_strmapi.c libft/ft_itoa.c \
			libft/ft_split.c libft/ft_strtrim.c libft/ft_strjoin.c \
			libft/ft_substr.c libft/ft_strdup.c libft/ft_calloc.c \
			libft/ft_tolower.c libft/ft_toupper.c libft/ft_isprint.c \
			libft/ft_isascii.c libft/ft_isalnum.c libft/ft_isdigit.c \
			libft/ft_isalpha.c libft/ft_atoi.c libft/ft_strncmp.c \
			libft/ft_strnstr.c libft/ft_strrchr.c libft/ft_strchr.c \
			libft/ft_strlcat.c libft/ft_strlcpy.c libft/ft_strlen.c \
			libft/ft_memcmp.c libft/ft_memchr.c libft/ft_memmove.c \
			libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c \
			libft/ft_memccpy.c

BONUS_SRS	= libft/ft_lstmap.c libft/ft_lstiter.c libft/ft_lstclear.c \
			libft/ft_lstdelone.c libft/ft_lstadd_back.c libft/ft_lstlast.c \
			libft/ft_lstsize.c libft/ft_lstadd_front.c libft/ft_lstnew.c

OBJECTS 	= ${SOURCE:.c=.o}

BONUS_OBJ	= ${BONUS_SRS:.c=.o}

INCLUDE		= libft/libft.h

.c.o:
			${CC} ${CFLAGS} -I${INCLUDE} -c $< -o ${<:.c=.o}

all:		${NAME}

$(NAME):	${OBJECTS}
			ar rc	${NAME} ${OBJECTS}
			ranlib	${NAME}

bonus:		${NAME}	${BONUS_OBJ}
			ar rc	${NAME} ${BONUS_OBJ}
			ranlib	${NAME}

clean:
			${RM} ${OBJECTS} ${BONUS_OBJ}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus