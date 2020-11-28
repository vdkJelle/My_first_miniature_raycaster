# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jelvan-d <jelvan-d@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/31 09:58:25 by jelvan-d          #+#    #+#              #
#    Updated: 2019/11/29 13:43:22 by jelvan-d         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a
SRCS		=	ft_atoi\
				ft_bzero\
				ft_calloc\
				ft_isalnum\
				ft_isalpha\
				ft_isascii\
				ft_isdigit\
				ft_isprint\
				ft_itoa\
				ft_memccpy\
				ft_memchr\
				ft_memcmp\
				ft_memcpy\
				ft_memmove\
				ft_memset\
				ft_putchar_fd\
				ft_putendl_fd\
				ft_putnbr_fd\
				ft_putstr_fd\
				ft_split\
				ft_strchr\
				ft_strdup\
				ft_strjoin\
				ft_strlcpy\
				ft_strlcat\
				ft_strlen\
				ft_strmapi\
				ft_strncmp\
				ft_strnstr\
				ft_strrchr\
				ft_strtrim\
				ft_substr\
				ft_tolower\
				ft_toupper\
				ft_lstadd_back\
				ft_lstadd_front\
				ft_lstclear\
				ft_lstdelone\
				ft_lstiter\
				ft_lstlast\
				ft_lstmap\
				ft_lstnew\
				ft_lstsize
CFILES		=	$(SRCS:%=srcs/%.c)
OFILES		=	$(SRCS:%=obj/%.o)
INCLUDES	=	./includes/.
FLAGS		=	-Wall -Werror -Wextra

all:	$(NAME)

$(NAME):	$(OFILES)
	@ar rc $(NAME) $(OFILES)
	@echo "Library made"

obj/%.o:	srcs/%.c
	@echo "Compiling... $^"
	@gcc -o $@ $(FLAGS) -I $(INCLUDES) -c $^

clean:
	@echo "Cleaning..."
	@rm -f $(OFILES)

fclean:		clean
	@echo "Extra cleaning..."
	@rm -f $(NAME)

re:			fclean all
