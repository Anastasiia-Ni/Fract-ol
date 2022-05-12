 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 16:43:21 by anifanto          #+#    #+#              #
#    Updated: 2021/11/17 13:50:23 by anifanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc

LIST =	fractol.c	ft_check_input.c 	ft_color.c\
		ft_free.c	ft_math_part.c		ft_events.c\
		ft_screen.c ft_window.c

OBJ = $(LIST:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :	$(OBJ)
			$(MAKE) -C ./libft
			$(MAKE) -C ./mlx
			$(CC) $(LIST) $(CFLAGS) $(OBJS) -L ./mlx -l mlx -framework OpenGL -Ofast -framework AppKit -L ./libft -l ft -lm -o $(NAME)

%.o : %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

bonus : $(NAME)

clean:
	rm -rf $(OBJ)
	rm -f ./mlx/*.a
	rm -f ./libft/*.o
	rm -f ./libft/*.a

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : all clean fclean re bonus
