# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/26 12:04:08 by jelvan-d          #+#    #+#              #
#    Updated: 2019/12/23 14:24:58 by jelvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf

SRCS 			= 	ft_printf\
					ft_get_width\
					ft_putchar_count\
					ft_putnbr_hex_low\
					ft_putnbr_hex_up\
					ft_putnbr\
					ft_put_p\
					ft_put_s\
					ft_put_c\
					ft_reverse_pad\
					ft_pad\
					ft_strlen\
					ft_put_u

CFILES			=	$(SRCS:%=%.c)
OFILES			=	$(CFILES:.c=.o)
INCLUDES		=	.
FLAGS			=	-Wall -Wextra -Werror

all:	$(NAME)

$(NAME):	$(OFILES)
	@ar rc $(NAME).a $(OFILES)
	@echo "Your ft_printf library is ready!"

%.o:	%.c
	@echo "Compiling..." $^
	@gcc -o $@ $(FLAGS) -I $(INCLUDES) -c $^

clean:
	@echo "Cleaning..."
	@rm -f $(OFILES)

fclean:		clean
	@echo "Extra cleaning..."
	@rm -f $(NAME).a

re:		fclean all
