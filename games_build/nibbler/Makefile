##
## EPITECH PROJECT, 2019
## Arcade
## File description:
## pacman library
##

LIB	=	lib_arcade_nibbler.so

SRC	=	./src/snake.cpp

OBJ	=	$(SRC:.cpp=.o)

CPPFLAGS	+=	-I./include -fPIC

all:	$(LIB)

obj:	$(OBJ)

$(LIB): obj
	$(CXX) -shared -o $(LIB) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(LIB)

re:	fclean all

.PHONY:	all obj clean fclean re