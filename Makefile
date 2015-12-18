# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adespond <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/18 14:14:20 by adespond          #+#    #+#              #
#    Updated: 2015/12/18 14:18:43 by adespond         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit

SRC		= src/ft_printf.c \
		  src/find.c \
		  src/format_create.c \
		  src/put_s.c \
		  src/put_d.c \
		  src/put_p.c
OBJ		= $(patsubst src/%.c,./%.o,$(SRC))

.SILENT:

$(NAME): $(OBJ)
	gcc -Wall -Werror -Wextra &(OBJ) -o $(NAME) -L libft/ -lft
	printf '\033[4m'
	printf '\033[32m[ ✔ ] %s\n\033[0m' "fillit is done !"

obj/%.o: ./%.c
	gcc -Wall -Wextra -Werror -c $< -o $@
	printf '\033[0m[ ✔ ] %s\n\033[0m' "$<"

clean:
	/bin/rm -rf *.o
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Clean"

fclean: clean
	/bin/rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fclean"

re: fclean all

all: $(NAME)

.PHONY: clean fclean re all
