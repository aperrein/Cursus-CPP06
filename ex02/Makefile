# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperrein <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 11:17:51 by aperrein          #+#    #+#              #
#    Updated: 2023/10/31 11:17:55 by aperrein         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ex03

OBJ_DIR		=	OBJ/

SRC			=	Base.cpp main.cpp

OBJ			=	$(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -g -std=c++98

all			:	$(OBJ_DIR) $(NAME)

$(OBJ_DIR)%.o:  $(SRC_DIR)%.cpp
				c++ $(CFLAGS) -c $< -o $@

$(OBJ_DIR)	:	
				mkdir $(OBJ_DIR)

$(NAME)		:	$(OBJ)
				c++	$(CFLAGS) -o $(NAME) $(OBJ)

clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
