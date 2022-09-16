# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anifanto <stasy247@mail.ru>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/03 11:38:11 by anifanto          #+#    #+#              #
#    Updated: 2021/11/11 15:13:34 by anifanto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIST =	ft_atoi.c			ft_bzero.c			ft_calloc.c\
		ft_isalnum.c		ft_isalpha.c		ft_isascii.c\
		ft_isdigit.c		ft_isprint.c		ft_memchr.c\
		ft_memcmp.c			ft_memcpy.c			ft_memmove.c\
		ft_memset.c			ft_strchr.c			ft_strcmp.c\
		ft_strdup.c			ft_strlcat.c		ft_strlcpy.c\
		ft_strlen.c			ft_strncmp.c		ft_strnstr.c\
		ft_strrchr.c		ft_tolower.c		ft_toupper.c\
		ft_substr.c			ft_strjoin.c		ft_strtrim.c\
		ft_split.c			ft_itoa.c			ft_strmapi.c\
		ft_striteri.c		ft_putchar_fd.c		ft_putstr_fd.c\
		ft_putendl_fd.c		ft_putnbr_fd.c		ft_atod.c

LIST_BONUS =	ft_lstnew.c		ft_lstadd_front.c	ft_lstsize.c\
				ft_lstlast.c	ft_lstadd_back.c	ft_lstdelone.c\
				ft_lstclear.c	ft_lstiter.c		ft_lstmap.c

OBJ = $(LIST:.c=.o)
OBJ_BONUS = $(LIST_BONUS:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	gcc -c $(FLAGS) $(LIST)
	ar -rc $(NAME) $(OBJ)

%.o : %.c
	gcc $(FLAGS) -c $< -o $(<:%.c=%.o)

bonus : $(NAME) $(OBJ_BONUS)
	gcc -c $(FLAGS) $(LIST_BONUS)
	ar -rc $(NAME) $(OBJ) $(OBJ_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
