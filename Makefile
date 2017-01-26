# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleblanc <aleblanc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 14:13:37 by aleblanc          #+#    #+#              #
#    Updated: 2017/01/26 15:22:16 by aleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

FLAGS= -Wall -Werror -Wextra

INC= -I include

SRC= main.cpp \
		 Factory.class.cpp \
		 Vm.class.cpp

OBJ= $(SRC:%.cpp=obj/%.o)

all: $(NAME)

$(NAME): obj $(OBJ)
	clang++ $(FLAGS) -o $@ $(OBJ) $(LIB)

obj/%.o: src/%.cpp
			clang++ $(FLAGS) $(INC) -o $@ -c $<

obj:
	mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: fclean all clean
