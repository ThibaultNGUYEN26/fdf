# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thibnguy <thibnguy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/25 17:41:00 by thibnguy          #+#    #+#              #
#    Updated: 2023/06/20 16:39:12 by thibnguy         ###   ########.fr        #
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
				libft/ft_strstr.c \
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
CFLAGS		=	-Wall -Wextra -Werror #-fsanitize=address -g
CINCLUDES	=	-I ${INCLUDES}

BLACK		=	"\033[1;30m"
RED			=	"\033[1;31m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;35m"
BLUE		=	"\033[1;36m"
WHITE		=	"\033[1;37m"
EOC			=	"\033[0;0m"

TOTAL_OBJS := $(words $(OBJS))
COMPILED_OBJS := 0

define print_progress
	printf $(WHITE)"\r● [Compiling]  : "
	$(eval PERCENTAGE=$(shell echo "$(2)*100/$(1)" | bc))
	$(eval FILLED_BLOCKS=$(shell if [ "$(shell echo "$(PERCENTAGE)/10" | bc)" -lt "1" ]; then echo "1"; else echo "$(shell echo "$(PERCENTAGE)/10" | bc)"; fi))
	$(eval EMPTY_BLOCKS=$(shell echo "10 - $(FILLED_BLOCKS)" | bc))
	for i in `seq 1 $(shell echo "$(FILLED_BLOCKS)" | awk '{print int($$1)}')`; do \
		printf $(GREEN)"▇▇▇"; \
	done
	if [ "$(PERCENTAGE)" != "100" ]; then \
		for i in `seq 1 $(EMPTY_BLOCKS)`; do \
			printf $(WHITE)"▇▇▇"; \
		done; \
	fi
	printf $(WHITE)" $(PERCENTAGE)%%"$(EOC)
	if [ $(2) -eq $(1) ]; then printf "\n"; fi
endef

${OBJECTS}/%.o: ${SOURCES}/%.c
	@mkdir -p $(dir $@)
	@$(call print_progress, $(TOTAL_OBJS), $(COMPILED_OBJS))
	@$(CC) $(CFLAGS) -o $@ -c $< $(CINCLUDES)
	@$(eval COMPILED_OBJS=$(shell echo "$(COMPILED_OBJS)+1" | bc))

all: ${NAME} norminette

${NAME}: ${OBJS} ${OBJECTS}/${NAME}.o
	@echo $(GREEN)"● Compilation of ${NAME}..."$(EOC)
	@${CC} ${CFLAGS} -lm -lmlx -framework OpenGL -framework AppKit  ${CINCLUDES} -o ${NAME} ${OBJS} ${OBJECTS}/${NAME}.o 

norminette:
	@norminette | grep "Error!" > /dev/null && echo $(WHITE)"● [Norminette] : "$(RED)"KO\n"$(EOC) || echo $(WHITE)"● [Norminette] : "$(GREEN)"OK\n"$(EOC)

clean:
	@echo ${RED}"● Deletion of binary files (.o)..."$(EOC)
	@rm -rf ${OBJECTS}

fclean: clean
	@echo ${RED}"● Deletion of executables and libraries..."$(EOC)
	@rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re