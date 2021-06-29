# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jelvan-d <jelvan-d@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/05/25 12:35:41 by jelvan-d      #+#    #+#                  #
#    Updated: 2021/03/07 20:22:09 by jelvan-d      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			=	cub3d

SRCS			=	initialize_values\
					parser_utils\
					parser\
					error_handling\
					map_handling\
					floodfill\
					floodfill_utils\
					mlx_functions\
					mlx_hooks\
					colours\
					map_utils\
					movement\
					raycasting\
					raycasting_info\
					sprites_utils\
					sprites_draw\
					bmp\
					main

CFILES			=	$(SRCS:%=%.c)
OFILES			=	$(CFILES:.c=.o)
FLAGS			=	-Wall -Wextra -Werror
ifdef DEBUG
FLAGS += -g -fsanitize=address
else
FLAGS += -O3
endif
LIBRARIES		=	libft/libft.a\
					get_next_line/gnl.a\
					minilibx-master/libmlx_x86_64.a

all:		$(NAME)

$(NAME): $(OFILES) $(LIBRARIES)
	@gcc $(FLAGS) $^ -Lminilibx-master -lmlx_x86_64 -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBRARIES):
	@echo "Compiling libft..."
	@make -C libft
	@echo "Compiling get_next_line..."
	@make -C get_next_line
	@echo "Compiling minilibx..."
	@make -C minilibx-master

%.o: %.c
	@gcc $(FLAGS) -I/usr/include -Imlx_linux -c $< -o $@

clean:
	@echo "Cleaning..."
	@rm -f $(OFILES)
	@make clean -C libft
	@make clean -C get_next_line
	@make clean -C minilibx-master

fclean:		clean
	@echo "Extra cleaning..."
	@rm -f $(NAME).a
	@rm -f cub3d
	@make fclean -C libft
	@make fclean -C get_next_line

re:			fclean all
