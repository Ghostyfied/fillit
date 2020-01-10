# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-ket <rvan-ket@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/17 17:42:44 by rvan-ket       #+#    #+#                 #
#    Updated: 2019/02/17 17:47:18 by rvan-ket      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


NAME = fillit

SRC = fillit.c ft_check.c ft_solve.c main.c extra.c extra_two.c

OBJ = fillit.o ft_check.o ft_solve.o main.o extra.o extra_two.o

HEADER = fillit.h

FLAGS = -Wall -Wextra -Werror

LIBFT = ./libft/

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFT)
	gcc $(FLAGS) $(OBJ) -o $(NAME) -L$(LIBFT) -lft
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)
fclean:	clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT)
re: fclean all