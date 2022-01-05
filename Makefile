# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 07:30:30 by fel-maac          #+#    #+#              #
#    Updated: 2022/01/05 12:34:20 by fel-maac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c parsing/parse_args.c parsing/parse_path.c utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I.

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

test:
	./pipex file1 cmd1 cmd2 cmd3 cmd4 file2
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test