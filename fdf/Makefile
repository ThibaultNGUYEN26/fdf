# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 17:41:00 by thibnguy          #+#    #+#              #
#    Updated: 2023/06/19 18:43:43 by thibnguy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	fdf
SOURCES		=	./src
OBJECTS		=	./bin
INCLUDES	=	./includes

SRCS		=	bonus/ft_events_gestions.c \
				bonus/ft_events.c \
				bonus/ft_func_draw.c \
				get_next_line/get_next_line.c \
				libft/ft_atoi_base.c \
				libft/ft_atoi.c \
				libft/ft_not_in_str.c \
				libft/ft_split_char.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strcmp.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlen.c \
				libft/ft_substr.c \
				matrix/ft_allocate_matrix.c \
				matrix/ft_angle_calculation.c \
				matrix/ft_count_line.c \
				matrix/ft_fill_matrix.c \
				matrix/ft_free_matrix.c \
				matrix/ft_init_matrix.c \
				matrix/ft_init_size_render.c \
				matrix/ft_read_file.c \
				mlx/ft_adjust_size.c \
				mlx/ft_bresenham.c \
				mlx/ft_calculation.c \
				mlx/ft_check_map_color.c \
				mlx/ft_close_window.c \
				mlx/ft_define_colors.c \
				mlx/ft_display_matrix.c \
				mlx/ft_draw_ortho.c \
				mlx/ft_calculation_ortho.c \
				mlx/ft_init_data.c \
				mlx/ft_draw_background.c \
				printf/ft_intlen.c \
				printf/ft_printf.c \

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
	@echo $(WHITE)"● Compilation de "$(BLUE)"${notdir $<}"$(EOC)"."
	@${CC} ${CFLAGS} -o $@ -c $< ${CINCLUDES}

all: ${NAME} norminette

${NAME}: ${OBJS} ${OBJECTS}/${NAME}.o
	@echo $(GREEN)"● Compilation du ${NAME}..."$(EOC)
	@${CC} ${CFLAGS} -fsanitize=address -g -lm -lmlx -framework OpenGL -framework AppKit  ${CINCLUDES} -o ${NAME} ${OBJS} ${OBJECTS}/${NAME}.o

norminette:
	@norminette | grep "Error!" > /dev/null && echo $(WHITE)"● [Norminette]: "$(RED)"KO\n"$(EOC) || echo $(WHITE)"● [Norminette]: "$(GREEN)"OK\n"$(EOC)

clean:
	@echo ${RED}"● Supression des fichiers binaires (.o)..."$(EOC)
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${RED}"● Supression des executables et librairies..."$(EOC)
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re