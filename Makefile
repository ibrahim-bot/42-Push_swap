# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ichougra <ichougra@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/04 15:30:45 by ibrahim           #+#    #+#              #
#    Updated: 2021/03/12 10:56:16 by ichougra         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

LFLAGS	=	-I includes

NAME	=	checker

NAME2	=	push_swap

SRCS_NAME	=	checker.c error.c error2.c utils.c\
				list.c list2.c get_next_line.c\
				get_next_line_utils.c ft_split.c\
				utils2.c tri.c exec_cmd.c exec_cmd2.c\

SRCS_NAME2	=	push_swap.c error.c error2.c utils.c\
				list.c list_s.c ft_split.c\
				utils2.c tri.c exec_cmd.c exec_cmd2.c\

SRC_PATH	=	file_checker

SRC_PATH2	=	file_push_swap

SRCS 		= 	$(addprefix $(SRC_PATH)/,$(SRCS_NAME))

SRCS2		=	$(addprefix $(SRC_PATH2)/,$(SRCS_NAME2))

OBJ	=	$(SRCS:.c=.o)

OBJ2	=	$(SRCS2:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)	$(OBJ2)
	@$(CC) $(OBJ) $(CFLAGS) -o $(NAME)
	@$(CC) $(OBJ2) $(CFLAGS) -o $(NAME2)
	@echo "Making checker...\t\033[92m√\033[0m"
	@echo "Making push_swap...\t\033[92m√\033[0m"

%.o : %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

clean:
	@rm -f $(OBJ)
	@rm -f $(OBJ2)
	@echo "Clean(checker)\t\t\033[92m√\033[0m"
	@echo "Clean(push_swap)\t\033[92m√\033[0m"

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME2)
	@echo "Fclean(checker)\t\t\033[92m√\033[0m"
	@echo "Fclean(push_swap)\t\033[92m√\033[0m"

re : fclean all

.PHONY: all fclean clean re $(EXEC)
