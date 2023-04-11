# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 17:41:00 by thibnguy          #+#    #+#              #
#    Updated: 2023/04/11 18:50:43 by thibnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
SOURCES		=	./src
OBJECTS		=	./bin
INCLUDES	=	./includes

SRCS		=	get_next_line/get_next_line.c \
				libft/ft_atoi.c \
				libft/ft_putstr_fd.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlen.c \
				libft/ft_substr.c \
				ft_close_window.c \
				ft_free_array.c \
				ft_strdel.c \
				ft_abs.c

OBJS		=	$(addprefix ${OBJECTS}/, $(SRCS:.c=.o))

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CINCLUDES	=	-I ${INCLUDES}

BLACK		=	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;35m"
BLUE		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@echo "● Compilation de "$(BLUE)"${notdir $<}"$(EOC)"."
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME}

${NAME}: ${OBJS} ${OBJECTS}/${NAME}.o
	@echo $(GREEN)"● Compilation du ${NAME}..."$(EOC)
	@${CC} ${CFLAGS} -lm -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address ${CINCLUDES} -o ${NAME} ${OBJS} ${OBJECTS}/${NAME}.o

clean:
	@echo ${RED}"● Supression des fichiers binaires (.o)..."$(EOC)
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${RED}"● Supression des executables et librairies..."$(EOC)
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re