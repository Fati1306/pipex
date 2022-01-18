# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fel-maac <fel-maac@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 07:30:30 by fel-maac          #+#    #+#              #
#    Updated: 2022/01/18 12:12:27 by fel-maac         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS = pipex.c parsing/parse_args.c parsing/parse_path.c parsing/get_exec_args.c utils/err_exit.c utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c utils/ft_strjoin.c

OBJS = $(SRCS:.c=.o)

BONUS_NAME = pipex_bonus

BONUS_SRCS = pipex_bonus.c parsing/parse_args_bonus.c parsing/parse_path.c parsing/get_exec_args.c utils/err_exit.c utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c utils/ft_strjoin.c utils/ft_strncmp.c utils/ft_strcpy.c utils/get_next_line.c utils/ft_strchr.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -I.

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I.

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) -I.
	
test:
	./pipex file1 "wc -l" cat file2

test_bonus:
	./pipex_bonus file1 "grep 1" cat cat cat cat cat cat cat file2

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re test